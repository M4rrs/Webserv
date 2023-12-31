#pragma once

#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/stat.h>
#include <stdexcept>
#include <unistd.h>
#include <iostream>
#include <cstring>
#include <dirent.h>
#include <sstream>
#include <fstream>
#include <netdb.h>
#include <fcntl.h>
#include <vector>
#include <cctype>
#include <ctime>
#include <map>
#include <sys/types.h>
#include <sys/wait.h>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define GREEN_BOLD "\033[32;1m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define CLEAR "\033[0m"

#define HOST "Host"
#define CON "Connection"
#define UIR "Upgrade-Insecure-Requests"
#define UA "User-Agent"
#define ACCEPT "Accept"

#define ROOT_DEFAULT "root_folder"
#define INDEX_DEFAULT "/index.html"
#define e404_DEFAULT "root_folder/404.html"
#define e405_DEFAULT "root_folder/405.html"
#define e501_DEFAULT "root_folder/501.html"
#define MAXCLIENTBODYSIZE_DEFAULT 20000000

#define ISE_500 "HTTP/1.1 500 Internal Server Error\r\nContent-Type: text/html\r\nContent-Length: "
#define ISE_MESSAGE "\r\n\r\n<!DOCTYPE html>\n<html>\n<head>\n<title>Internal Server Error.</title>\n</head>\n<body>\n<h1>500 Internal Server Error</h1>\n<p>The Trinity Server has encountered an error and was unable to complete your request.</p>\n</body>\n</html>"
#define PTL_413 "HTTP/1.1 413 Payload too Large\r\nContent-Type: text/html"
#define PTL_MESSAGE "\r\n\r\n<!DOCTYPE html><html><head><title>Payload too large.</title><style>body {display: flex;justify-content: center;align-items: center;height: 100vh;margin: 0;background-color: #f090ff;font-family: Arial, Helvetica, sans-serif;}.fancy {font-family: \"Open Sans\", sans-serif;font-size: 16px;letter-spacing: 2px;text-decoration: none;text-transform: uppercase;color: #000;cursor: pointer;border: 3px solid;padding: 0.25em 0.5em;box-shadow: 1px 1px 0px 0px, 2px 2px 0px 0px, 3px 3px 0px 0px, 4px 4px 0px 0px, 5px 5px 0px 0px;position: relative;user-select: none;-webkit-user-select: none;touch-action: manipulation;}.fancy:active {box-shadow: 0px 0px 0px 0px;top: 5px;left: 5px;}</style></head><body><div><h2>413 Payload too Large</h2><p>Tf you trying to send? Why is it so big\?\?</p><button class=\"fancy\" onclick=\"window.location.href=\'/upload\'\">Return to Upload</button></div></body></html>"

enum serverBlock {
	notDefined = 0,
	listenenum = 1,
	server_name = 2,
	root = 3,
	location = 4,
	indexServ = 5,
	errorPages = 6,
	max_body_size = 7,
	start = 8,
	ended = 9
};

struct Location {
	std::string					uri;
	std::string 				index;
	std::vector<std::string>	allowedMethods;
	bool autoindex;
};

struct ServerConfig {
	int							listen;
	std::string					name;
	std::string					root;
	std::vector<Location>		locations;
	std::string 				index;
	std::map<int, std::string>	errorPages;
	int							maxClientBodySize;
};