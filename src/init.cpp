#include "nooc.hpp"

param init(int argc, char **argv) {
	param scan;
	scan.host = "localhost";
	scan.first_port = 0;
	scan.last_port = MAX_PORT;
	(void)argc;
	(void)argv;
	return scan;
}
