#include "nooc.hpp"
#include <regex>

void scanner(param scan, vector<int> &open_ports, mutex &mtx) {
	regex domain("^(?!-)[A-Za-z0-9-]+([\\-\\.]{1}[a-z0-9]+)*\\.[A-Za-z]{2,6}$");
	if (!regex_match(scan.host, domain)) {
		scan.host = dns(scan.host);
		cout << "is domin" << endl;
	}
	for (int port = scan.first_port; port <= scan.last_port; port++) {
		if (is_open_port(scan.host, port)) {
			lock_guard<mutex> lock(mtx);
			open_ports.push_back(port);
		}
	}
}

