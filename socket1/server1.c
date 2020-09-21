// a simple c "hello world" server

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>

#define PORT "3490" // port to connect to
#define BACKLOG 10  // how many pending connections will hold

void sigchldHandler(int s)
{
	int saved_errno = errno;

	while(waitpid(-1, NULL, WNOHANG) > 0);

	errno = saved_errno;
}

// get sockaddr ipv3 or ipv6
void *getInAddr(struct sockaddr *sa)
{
	if (sa->sa_family == AF_INET)
	{
		return &(((struct sockaddr_in*)sa)->sin_addr);
	}
	return &(((struct sockaddr_in6*)sa)->sin6_addr);
}

int main(void)
{
	// initlise all variables used in server
	int sockfd, new_fd; // listn fd and connection fd
	struct addrinfo hints, *servinfo, *p;
	struct sockaddr_storage thier_addr; // connecters addr info
	socklen_t sin_size;
	struct sigaction sa;
	int yes = 1;
	char s[INET6_ADDRSTRLEN];
	int rv;

	// setup hints to be empty
	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC; // whatever format is given
	hints.ai_socktype = SOCK_STREAM; // looking for a stream socket
	hints.ai_flags = AI_PASSIVE; // us my ip

	// run getaddrinfo() for ourself if error print it
	if ((rv = getaddrinfo(NULL, PORT, &hints, &servinfo)) != 0)
	{
		fprintf(stderr, "%s\n", gai_strerror(rv));
		return 1;
	}

	// loop through all the result and bind to the first we can
	// we do this to listen to out internal port
	for (p = servinfo; p != NULL; p->ai_next)
	{
		// find socked info and raise error if none
		if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1)
		{
			perror("server: socket");
			continue;
		}
		// ???
		if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1)
		{
			perror("setsockopt");
			exit(1);
		}
		// bind to that socket and if error close
		if (bind(sockfd, p->ai_addr, p->ai_addrlen) == -1)
		{
			close(sockfd);
			perror("server: bind");
			continue;
		}
		// find first that works then break
		break;
	}

	// freeup this struct
	freeaddrinfo(servinfo);

	// if we failed to find a addr that works exit
	if (p == NULL)
	{
		fprintf(stderr, "server: failed to bind\n");
		exit(1)
	}

	// start listen to our port, if failed exit
	if (listen(sockfd, BACKLOG) == -1)
	{
		perror("listen");
		exit(1)
	}

	// i think this bit handles extra processes
	sa.sa_handler = sigchldHandler; // reap dead processes ?
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	if (sigaction(SIGCHLD, &sa, NULL) == -1)
	{
		perror("sigaction");
		exit(1)
	}


	// we have begun listening on our port and are ready to take 
	// connects
	printf("server: waiting for connections...\n");

	while(1) // accept loop
	{
		sin_size = sizeof thier_addr;
		new_fd = accept(sockfd, (struct sockaddr *)&thier_addr, &sin_size);
		if (new_fd == -1)
		{
			perror("accept");
			continue;
		}
	}

	return 0;
}

