#include "nooc.h"
#include <cctype>

bool isDomain(string hostname) {
	for (char c : hostname) {
		if (isalpha(c)) {
			return true;
		}
	}
	return false;
}

vector<int> scanner(string host, int start, int end) {
	vector<int> open_ports;
	if (start < 0 || end < 0) {
		return open_ports;
	}
	if (isDomain(host)) {
		host = dns_resolve(host);
	}
	for (int port = start; port < end; port++) {
		if (is_open_port(host, port)) {
			open_ports.push_back(port);
		}
	}
	return open_ports;
}
