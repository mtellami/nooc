#include "nooc.hpp"
#include <cstring>
#include <arpa/inet.h>
#include <netdb.h>
string dns(string &hostname) {
	struct addrinfo hints, *result, *p;
  char ipstr[INET6_ADDRSTRLEN];

  memset(&hints, 0, sizeof hints);
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;

  int status = getaddrinfo(hostname.c_str(), NULL, &hints, &result);
  if (status) {
		cout << "heere  ." << endl;
		return "";
	}

  for (p = result; p != nullptr; p = p->ai_next) {
    void *addr;
    if (p->ai_family == AF_INET) {
      struct sockaddr_in *ipv4 = (struct sockaddr_in *)p->ai_addr;
      addr = &(ipv4->sin_addr);
    } else {
      struct sockaddr_in6 *ipv6 = (struct sockaddr_in6 *)p->ai_addr;
      addr = &(ipv6->sin6_addr);
    }
    inet_ntop(p->ai_family, addr, ipstr, sizeof ipstr);
  }
  freeaddrinfo(result);

	cout << "==========. >" << ipstr << endl;
  return ipstr;
}

