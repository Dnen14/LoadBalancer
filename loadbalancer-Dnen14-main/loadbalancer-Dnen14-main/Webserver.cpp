#include "Webserver.h"

/**
 * @file Webserver.cpp
 * @brief Implementation of the WebServer class for simulating basic web server operations.
 * 
 * This file contains the implementation of the WebServer class methods. It provides basic 
 * functionality for initializing a web server on a specified port, starting and stopping the 
 * server, and managing the port configuration.
 * 
 * The WebServer class allows for the simulation of starting and stopping a server, 
 * along with setting and retrieving the server's port number.
 * 
 * @see WebServer
 * 
 */

/**
 * @class WebServer
 * @brief Simulates a basic web server with functionality to start, stop, and manage ports.
 * 
 * The WebServer class allows for the creation of a web server instance with a specified port 
 * number. It provides methods to start and stop the server, set a new port number, and retrieve 
 * the current port number. This class is primarily designed for simulating web server operations.
 * 
 * The server can be initialized with a custom port or the default port of 8080. 
 * It includes methods to simulate the start and stop operations.
 */

/**
 * @brief Constructs a WebServer object with a specified port.
 * 
 * @param port The port number the web server will use.
 */
WebServer::WebServer(int port) {
    this->port = port;
}

/**
 * @brief Default constructor for WebServer.
 * 
 * Initializes the web server to port 8080 by default.
 */
WebServer::WebServer(){
    this->port = 8080;
}

/**
 * @brief Destructor for WebServer.
 * 
 * Cleans up any resources when the WebServer object is destroyed.
 */
WebServer::~WebServer() {
}

/**
 * @brief Starts the web server.
 * 
 * Simulates the start of the server.
 */
void WebServer::start() {
}

/**
 * @brief Stops the web server.
 * 
 * Simulates the stop of the server.
 */
void WebServer::stop() {
}

/**
 * @brief Sets the port number of the web server.
 * 
 * @param value The new port number to be set.
 */
void WebServer::set_port(int value){
    this->port = value;
}

/**
 * @brief Gets the current port number of the web server.
 * 
 * @return int The current port number of the web server.
 */
int WebServer::get_port(){
    return port;
}