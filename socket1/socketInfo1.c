#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>

// socket adress information
struct sockaddr
{
	// ipv4 or ipv6
	unsigned short     sa_family; // for this either AF_INET or AF_INET6
	// destination address port number etc.
	char               sa_data[14]; // 14 bytes of protocol address
};


// internet address - OLD HISTORICAL
struct in_addr
{
	uint32_t           s_addr; // 32-bit int - 4 bytes
};

// socket address information for ipv4
struct sockaddr_in
{
	short int          sin_family; // address family inet - ipv4
	// use htons() to makes sure it matches network byte order
	unsigned short int sin_port; // port number
	struct in_addr     sin_addr; // internet address
	// use memset() to all zeroes - just padding to same size as sockaddr
	unsigned char      sin_zero[8]; // to make the size same as struct
};

struct sockaddr_storage
{
	sa_family_t        ss_family; // address family ipv4..
};

// specific adress information
struct addrinfo
{
	int                ai_flags;
	// What family this belongs to internet or internet6
	int                ai_family; // AF_INET, AF_INET6 - 
	// Whether the socket is stream or datgram
	int                ai_socktype; // SOCK_STREAM, SOCK_DGRAM
	int                ai_protocol; // "0" for any
	size_t             ai_addrlen; // size of ai_addr in bytes
	// difernce between ipv4 adn ipv6
	struct sockaddr    *ai_add; // struct sockaddr_in or _in6
	char               *ai_canonname; // full hostname

	struct addrinfo *ai_next; // next node in linked list
};

// exemplar of inet_pton() "presentation to network"
// convert sockaddr_in -> in_addr

/*
sockaddr_in sa;
inet_pton(AF_INET, "10.12.110.57", &(sa.sin_addr));
*/

// exemplar of inet_ntop() "network to presentation"
// convert in_addr -> sockaddr_in
/*
char ip4[INET_ADDRSTRLEN];
struct sockaddr_in sa;

inet_ntop(AF_INET, &(sa.sin_addr), ip4, INET_ADDRSTRLEN)
*/


int main(int argc, char const *argv[])
{	
	int x = 5;
	printf("%d\n", x);
	return 0;
}