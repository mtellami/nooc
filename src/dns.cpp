#include "nooc.hpp"

string dns(string &hostname) {
	struct hostent* he = gethostbyname(hostname.c_str());
  if (!he) {
    return hostname;
  }
  struct in_addr** addr_list = reinterpret_cast<struct in_addr**>(he->h_addr_list);
  return inet_ntoa(*addr_list[0]);
}
