#pragma once

// Clib
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

// CPP
#include <iostream>
#include <vector>

using namespace std;

#define ERR -1
#define MAX_PORT 65535

bool is_open_port(string &host, int port);
vector<int> scanner(string host, int start, int end);
string dns_resolve(string &hostname);

