#include "nooc.h"

int main(int argc, char **argv) {
	if (argc != 2) {
		cerr << "Usage: nooc <host>" << endl;
		return EXIT_FAILURE;
	}

	try {
		string host = argv[1];
		vector<int> open_ports = scanner(host, 0, MAX_PORT);
		if (open_ports.empty()) {
			cout << "No open ports found on " << host << endl;
		} else {
			for (int port : open_ports) {
				cout << host << ":" << port << endl;
			}
		}
	} catch (exception &e) {
		cerr << e.what() << endl;
	}
}
