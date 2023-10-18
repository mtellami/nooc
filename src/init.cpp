#include "nooc.hpp"

param init(int argc, char **argv) {
	param scan = {"none", 0, MAX_PORT};
	range range;

	if (argc == 1)
		throw Error("nooc usage: ./nooc -h <hostname> -p <port>");
	for (int i = 1; i < argc; i++) {
		if (!string(argv[i]).compare("-h") || !string(argv[i]).compare("-host")) {
			if (++i == argc)
				throw Error("nooc: error host required");
			if (scan.host != "none")
				throw Error("nooc: error multiple hosts");
			scan.host = argv[i];
		} else if (!string(argv[i]).compare("-p") || !string(argv[i]).compare("-port")) {
			if (++i == argc)
				throw Error("nooc: error port required");
			if (scan.first_port || scan.last_port != MAX_PORT)
				throw Error("nooc: error multiple ports");
			range = ports(string(argv[i]));
			scan.first_port = range.first;
			scan.last_port = range.second;
		} else {
			throw Error("nooc: error format\nnooc usage: ./nooc -h <host>");
		}
	}
	return scan;
}

