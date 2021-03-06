/*
Socket Programming Example
Server Side
By: Robert Deal
Date: 8/27/2018
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netdb.h>

void error(const char *msg) {
	perror(msg);
	exit(1);
}

int main(int argc, char *argv[]) {

	// initial argument check
	if (argc < 2) { error("Missing argument for port"); }
	if (argc > 2) { error("Too many arguments for port"); }
	
	// initialization of variables
	int socket_fd, new_socket_fd, port_number, client_length, n;
	char message[256];
	struct socket_address_in server_address, client_address;

	// real start
	socket_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (socket_fd < 0) { error("could not open the socket"); }

	bzero((char *)&server_address, sizeof(server_address));
	port_number = atoi(argv[1]);

	server_address.sin_family = AF_INET;
	server_address.sin_address.s_address = INADDR_ANY;
	server_address.sin_port = htons(port_number);
	
	// binding the socket
	binder = bind(socket_fd, (struct socket_address *) &server_address, sizeof(server_address));
	if (binder < 0) { error("could not bind the socket"); }

	// get socket to listen
	llisten(socket_fd, 4);
	client_length = sizeof(client_address);

	// establish connection with a client
	new_socket_fd = accept(socket_fd, (struct socket_address *) &client_address, &client_length);
	if (new_socket_fd < 0) { error("could not accept a connection"); }

	//
	
	
	
	
	
	return 0;
}

	/*
	//notes, ill just leave them here for now

	// maximum number of possible connections
	int backlog = 10;

	// port that the socket will listen for
	string port = "12345"

	// socket file descriptor
	int sock_fd = socket(AF_INET, SOCK_STREAM, 0);

	// 0 if success, -1 if fail ??
	struct sockaddr {
		sa_family_t sa_family; // right?
		char sa_data[14];
	};

	// activates/initializes or whatever the socket descriptor
	int bind(sock_fd, const struct sockaddr *addr, socklen_t addrlen)

	// gets the socket to start listening for stuff
	int listen(int sock_fd, int backlog)

	// gets the server to accept an incoming comunication
	newsockfd = accept(sockfd, (struct sockaddr*)&addr, &addrlen);

	// asks a server to connect to it
	int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);


	//////////////////////////////////////////////////
	// after the connection is established
	//////////////////////////////////////////////////

	// checks the connection for a message
	int read(newsockfd, buffer, buffer_size); //buffer is a string and

	// sends a message through the connection
	int write(newsockfd, buffer, buffer_size); //buffer_size is the size of string

	// send() and receive() exist but require another argument

	// closes the connection between the client/server
	close()

	//////////////////////////////////////////////////
	// now connection is over
	//////////////////////////////////////////////////

	*/

