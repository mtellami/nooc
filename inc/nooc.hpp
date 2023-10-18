#pragma once

// Clib
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

// CPP
#include <iostream>
#include <vector>
#include <cctype>
#include <mutex>
#include <thread>
#include <regex>

#define MAX_PORT 65535

using namespace std;

typedef struct param {
	string 	host;
	int 		first_port;
	int 		last_port;
} param;

typedef pair<int, int> range;

class Error : public exception {
	private:
		string message;
	public:
		Error(string msg) : message(msg) {}
		virtual const char* what() const throw() {
			return message.c_str();
		}	
};

bool is_open_port(string &host, int port);
void scanner(param scan, vector<int> &open_ports, mutex &mtx);
string dns(string &hostname);
param init(int argc, char **argv);
range ports(string input);

