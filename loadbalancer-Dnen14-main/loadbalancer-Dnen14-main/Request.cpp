/**
 * @file Request.cpp
 * @brief Implementation of the Request class for managing HTTP requests.
 * 
 * This file contains the implementation of the Request class, which represents an HTTP 
 * request. It provides methods for setting the HTTP method, URL, headers, and body of 
 * the request, as well as printing the request details.
 * 
 * The Request class is designed to encapsulate the essential components of an HTTP 
 * request and allows for easy manipulation and display of request data.
 * 
 * @see Request
 * 
 */

#include "Request.h"
#include <iostream>
#include <thread>
#include <chrono>

/**
 * @class Request
 * @brief Represents an HTTP request with method, URL, headers, and body.
 * 
 * The Request class encapsulates the details of an HTTP request, including its method, 
 * URL, headers, and body content. It provides methods to set these components and print 
 * the request details. This class is essential for simulating and managing HTTP 
 * requests in web applications.
 */

/**
 * @brief Default constructor for the Request class.
 * 
 * Initializes an empty Request object with default values for the method, URL, headers, and body.
 */
Request::Request() : method(""), url(""), headers(""), body("") {}

/**
 * @brief Destructor for the Request class.
 * 
 * Responsible for cleaning up resources used by the Request object.
 */
Request::~Request() {}

/**
 * @brief Sets the HTTP method for the request.
 * 
 * @param method The HTTP method (e.g., GET, POST) to be assigned to the request.
 */
void Request::set_method(const string& method) {
    this->method = method;
}

/**
 * @brief Sets the URL for the request.
 * 
 * @param url The URL to be assigned to the request.
 */
void Request::set_url(const string& url) {
    this->url = url;
}

/**
 * @brief Sets the headers for the request.
 * 
 * @param headers The headers to be assigned to the request.
 */
void Request::set_headers(const string& headers) {
    this->headers = headers;
}

/**
 * @brief Sets the body content for the request.
 * 
 * @param body The body content to be assigned to the request.
 */
void Request::set_body(const string& body) {
    this->body = body;
}

/**
 * @brief Prints the details of the request to the console.
 * 
 * Outputs the method, URL, headers, and body of the request to the console.
 */
void Request::print_request() const {
}

/**
 * @brief decrement the task time by 1 cycle.
 * 
 */
void Request::decrement_task_time() {
    if (taskTime > 0) taskTime--;
}

/**
 * @brief check if the request is completed
 * 
 */
bool Request::is_completed() const {
    return taskTime <= 0;
}

/**
 * @brief Sets the task time for the request.
 * 
 * @param time The time to be set for the request.
 */
void Request::set_task_time(int time){
    taskTime = time;
}

/**
 * @brief Gets task time for the request.
 */
int Request::get_task_time() const {
    return taskTime;
}

