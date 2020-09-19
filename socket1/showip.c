// showip.c - show IP addesses for a host given on the command line
// example to getaddrinfo()


#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main(int argc, char const *argv[])
{
	// set up right structs 
	struct addrinfo hints, *res, *p;
	int status;
	char ipstr[INET6_ADDRSTRLEN];

	// check for the right ammount of args
	if(argc != 2)
	{
		fprintf(stderr, "usage: showip hostname\n");
		return 1;
	}

	// make sure hints is empty
	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC; // whatever format is given
	hints.ai_socktype = SOCK_STREAM; // looking for a stream socket

	// get linked list with format hints and put in res
	// set status to that
	// if status is not zero raise error
	if((status = getaddrinfo(argv[1], NULL, &hints, &res)) != 0)
	{
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
		return 2;
	}

	// print target ip
	printf("IP addresses for %s:\n\n", argv[1]);

	// loop over the element in res linked list with p
	for(p = res; p != NULL; p = p->ai_next)
	{
		void *addr;
		char *ipver;

		if(p->ai_family == AF_INET) // if its a ipv4 ip
		{
			// get pointer to the address in p
			struct sockaddr_in *ipv4 = (struct sockaddr_in *)p->ai_addr;
			// pass to addr
			addr = &(ipv4->sin_addr);
			ipver = "IPv4";
		} else // ipv6
		{
			struct sockaddr_in6 *ipv6 = (struct sockaddr_in6 *)p->ai_addr;
			addr = &(ipv6->sin6_addr);
			ipver = "IPv6";
		}

		// convert ip to string and print
		inet_ntop(p->ai_family, addr, ipstr, sizeof ipstr);
		printf("  %s: %s\n", ipver, ipstr);

	}

	freeaddrinfo(res); // free linked list

	return 0;
}