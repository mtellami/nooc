#include "nooc.hpp"

bool is_open_port(string &host, int port) {
	int sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == ERR) {
		throw "socket system call failed";
	}

	struct sockaddr_in address;
	address.sin_family = AF_INET;
	address.sin_port = htons(port);
	address.sin_addr.s_addr = inet_addr(host.c_str());

	int open = connect(sock, (struct sockaddr *)&address, sizeof(address));
	close(sock);
	return !open;
}
