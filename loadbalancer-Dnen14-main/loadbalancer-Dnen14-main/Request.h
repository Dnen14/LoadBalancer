/**
 * @file Request.h
 * @brief Declaration of the Request class, representing an HTTP request.
 * 
 * This file contains the definition of the Request class, which stores details 
 * about an HTTP request such as the HTTP method, URL, headers, and body. It provides 
 * setters for these properties and a function to print the request details.
 * 
 * The Request class is designed to be used as a container for storing and managing 
 * information related to an HTTP request.
 * 
 */

#ifndef REQUEST_H
#define REQUEST_H

#include <string>
using std::string;

class Request {
private:
    string method;
    string url;
    string headers;
    string body;
    int taskTime = 0;

public:
    /**
     * @brief Default constructor for Request.
     * 
     * Initializes an empty Request object.
     */
    Request();

    /**
     * @brief Destructor for Request.
     * 
     * Cleans up any resources used by the Request object.
     */
    ~Request();

    /**
     * @brief Sets the HTTP method for the request.
     * 
     * @param method The HTTP method (e.g., GET, POST).
     */
    void set_method(const string& method);

    /**
     * @brief Sets the URL for the request.
     * 
     * @param url The URL to be set for the request.
     */
    void set_url(const string& url);

    /**
     * @brief Sets the headers for the request.
     * 
     * @param headers The headers to be set for the request.
     */
    void set_headers(const string& headers);

    /**
     * @brief Sets the body content for the request.
     * 
     * @param body The body content to be set for the request.
     */
    void set_body(const string& body);

    /**
     * @brief Prints the details of the request.
     * 
     * Outputs the method, URL, headers, and body to the console.
     */
    void print_request() const;

    /**
     * @brief decrement the task time by 1 cycle.
     * 
     */
    void decrement_task_time();

    /**
     * @brief check if the request is completed
     * 
     */
    bool is_completed() const;

    /**
     * @brief Sets the task time for the request.
     * 
     * @param time The time to be set for the request.
     */
    void set_task_time(int time);

    /**
     * @brief Gets task time for the request.
     */
    int get_task_time() const;
};

#endif
