#include "nooc.hpp"

bool isDomain(string hostname) {
	for (char c : hostname) {
		if (isalpha(c)) {
			return true;
		}
	}
	return false;
}

void scanner(param scan, vector<int> &open_ports, mutex &mtx) {
	if (isDomain(scan.host)) {
		scan.host = dns(scan.host);
	}
	for (int port = scan.first_port; port <= scan.last_port; port++) {
		if (is_open_port(scan.host, port)) {
			lock_guard<mutex> lock(mtx);
			open_ports.push_back(port);
		}
	}
}
