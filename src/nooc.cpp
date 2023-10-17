#include "nooc.hpp"

int main(int argc, char **argv) {
	vector<thread> threads;
	vector<int> open_ports;
	mutex mtx;

	try {
		param scan = init(argc, argv);
		int numThreads = thread::hardware_concurrency();
		int chunk = (scan.last_port - scan.first_port + 1) / numThreads;

		for (int i = 0; i < numThreads; i++) {
			param range;
			range.host = scan.host;
			range.first_port = scan.first_port + i * chunk;
			range.last_port = i == numThreads - 1 ? scan.last_port : range.first_port + chunk - 1;
			threads.emplace_back(scanner, range, ref(open_ports), ref(mtx));
		}

		for (thread& thread : threads) {
			thread.join();
		}

		if (open_ports.empty()) {
			cout << "No open ports found on " << scan.host << endl;
		} else {
			for (int port : open_ports) {
				cout << scan.host << ":" << port << endl;
			}
		}
	} catch (exception &e) {
		cerr << e.what() << endl;
	}
}
