#ifndef WEBSERVER_H
#define WEBSERVER_H
#include <iostream>

/**
 * @file Webserver.h
 * @brief Defines the WebServer class, which simulates a basic web server.
 *
 * This file contains the definition of the WebServer class, providing functionality
 * to start and stop the server, manage ports, and handle basic server operations.
 * The class includes constructors for custom and default ports, as well as methods
 * for setting and retrieving the server port.
 */

/**
 * @class WebServer
 * @brief A class that simulates a web server instance.
 * 
 * This class provides basic functionality for starting and stopping a web server, 
 * as well as managing server ports.
 */
class WebServer {
private:
    int port;

public:

    /**
     * @brief Constructs a WebServer object with a specified port number.
     * @param port The port number for the web server.
     */
    WebServer(int port);

    /**
     * @brief Constructs a WebServer object with the default port (80).
     */
    WebServer();

    /**
     * @brief Destroys the WebServer object.
     */
    ~WebServer();

    /**
     * @brief Starts the web server.
     */
    void start();

    /**
     * @brief Stops the web server.
     */
    void stop();

    /**
     * @brief Sets the port number for the web server.
     * @param value The port number to set.
     */
    void set_port(int value);

    /**
     * @brief Gets the port number of the web server.
     * @return The current port number.
     */
    int get_port();
};

#endif