#include "nooc.hpp"

void scanner(param scan, vector<int> &open_ports, mutex &mtx) {
	regex domain("^(?!\\d)([a-zA-Z0-9-]+\\.)+[a-zA-Z]{2,}$");
	if (regex_match(scan.host, domain)) {
		scan.host = dns(scan.host);
	}
	for (int port = scan.first_port; port <= scan.last_port; port++) {
		if (is_open_port(scan.host, port)) {
			lock_guard<mutex> lock(mtx);
			open_ports.push_back(port);
		}
	}
}

