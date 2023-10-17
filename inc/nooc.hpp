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

using namespace std;

typedef struct param {
	string 	host;
	int 		first_port;
	int 		last_port;
} param;

#define ERR -1
#define MAX_PORT 65535

bool is_open_port(string &host, int port);
void scanner(param scan, vector<int> &open_ports, mutex &mtx);
string dns_resolve(string &hostname);
param init(int argc, char **argv);

