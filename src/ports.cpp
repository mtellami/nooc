#include "nooc.hpp"

range ports(string input) {
	range pair;
	regex pattern(R"(\d+,\d+)");

	if (!regex_match(input, pattern))
		throw Error("nooc: error invalid ports range");

	size_t pos = input.find(',');
	pair.first = stoi(input.substr(0, pos));
	pair.first = pair.first > MAX_PORT ? MAX_PORT : pair.first;
	pair.first = pair.first < 0 ? 0 : pair.first;

	pair.second = stoi(input.substr(pos + 1));
	pair.second = pair.second > MAX_PORT ? MAX_PORT : pair.second;
	pair.second = pair.second < 0 ? 0 : pair.second;

	return pair;
}
