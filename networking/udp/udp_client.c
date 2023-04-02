/* For educational purposes only! Based on https://github.com/codeplea/Hands-On-Network-Programming-with-C */
#include "../socket_utils.h"

#if defined(_WIN32)
#include <conio.h>
#endif

int main() {

	/* Initialize WinSock */
#if defined(_WIN32)
	WSADATA d;
	if (WSAStartup(MAKEWORD(2, 2), &d)) {
		fprintf(stderr, "Failed to initialize.\n");
		return 1;
	}
#endif

	/* Configure a remote address for connection */
	printf("Configuring remote address...\n");
	struct addrinfo hints;
	memset(&hints, 0, sizeof(hints));
	hints.ai_socktype = SOCK_DGRAM;
	struct addrinfo *peer_address;
	if (getaddrinfo("127.0.0.1", "8080", &hints, &peer_address)) {
		fprintf(stderr, "getaddrinfo() failed. (%d)\n", GETSOCKETERRNO());
		return 1;
	}

	/* Print out the address */
	printf("Remote address is: ");
	char address_buffer[100];
	char service_buffer[100];
	getnameinfo(peer_address->ai_addr, peer_address->ai_addrlen,
		address_buffer, sizeof(address_buffer),
		service_buffer, sizeof(service_buffer),
		NI_NUMERICHOST | NI_NUMERICSERV);
	printf("%s %s\n", address_buffer, service_buffer);

	/* Create our socket */
	printf("Creating socket...\n");
	SOCKET socket_peer;
	socket_peer = socket(peer_address->ai_family,
		peer_address->ai_socktype, peer_address->ai_protocol);
	if (!ISVALIDSOCKET(socket_peer)) {
		fprintf(stderr, "socket() failed. (%d)\n", GETSOCKETERRNO());
		return 1;
	}

	/* Send data */
	const char *message = "Hello World";
	printf("Sending: %s\n", message);
	int bytes_sent = sendto(socket_peer,
		message, strlen(message),
		0,
		peer_address->ai_addr, peer_address->ai_addrlen);
	printf("Sent %d bytes.\n", bytes_sent);

	freeaddrinfo(peer_address);

	/* Close socket and clean up winsock */
	printf("Closing socket...\n");
	CLOSESOCKET(socket_peer);

#if defined(_WIN32)
	WSACleanup();
#endif	

	printf("Finished.\n");
	return 0;
}
