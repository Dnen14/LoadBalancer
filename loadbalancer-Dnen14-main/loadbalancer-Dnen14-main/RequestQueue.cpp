/**
 * @file RequestQueue.cpp
 * @brief Implementation of the RequestQueue class for managing HTTP requests.
 * 
 * This file contains the implementation of the RequestQueue class, which is responsible for 
 * storing and managing HTTP requests in a queue. It provides functionalities to add requests, 
 * process the next request, and check the status of the queue.
 * 
 * The RequestQueue class supports operations for adding, removing, and processing requests 
 * in a first-in, first-out (FIFO) manner.
 * 
 * @see RequestQueue
 * @see Request
 * 
 */

#include "RequestQueue.h"
#include "Request.h"
#include <iostream>
#include <thread>
#include <chrono>

/**
 * @class RequestQueue
 * @brief Manages a queue of HTTP requests for processing.
 * 
 * The RequestQueue class provides methods to add, remove, and process HTTP requests in 
 * a queue structure. It allows for checking whether the queue is empty and getting the 
 * current size of the queue. This class is primarily designed to handle incoming 
 * requests efficiently in a web server context.
 */

/**
 * @brief Default constructor for RequestQueue.
 * 
 * Initializes an empty request queue.
 */
RequestQueue::RequestQueue() {}

/**
 * @brief Destructor for RequestQueue.
 * 
 * Cleans up any resources when the RequestQueue object is destroyed.
 */
RequestQueue::~RequestQueue() {}

/**
 * @brief Adds a new request to the queue.
 * 
 * @param request The request object to be added to the queue.
 */
void RequestQueue::add_request(const Request& request) {
    requestQueue.push(request);
}

/**
 * @brief Processes the next request in the queue.
 * 
 * Removes the front request from the queue if it's not empty.
 */
void RequestQueue::process_next_request() {
    std::this_thread::sleep_for(std::chrono::milliseconds(rand() % (50 - 1 + 1) + 1));

    if (!(requestQueue.empty())) {
        requestQueue.pop();
    }
}

/**
 * @brief Removes a request from the queue.
 * 
 * Directly removes the front request from the queue without processing it.
 */
void RequestQueue::remove_request(){
    requestQueue.pop();
}

/**
 * @brief Checks if the queue is empty.
 * 
 * @return true If the queue is empty.
 * @return false If there are still requests in the queue.
 */
bool RequestQueue::is_empty() const {
    return requestQueue.empty();
}

/**
 * @brief Gets the current size of the queue.
 * 
 * @return int The number of requests in the queue.
 */
int RequestQueue::get_size() const {
    return requestQueue.size();
}

/**
 * @brief returns a reference
 */
Request& RequestQueue::get_front_request() {
    return requestQueue.front();
}
