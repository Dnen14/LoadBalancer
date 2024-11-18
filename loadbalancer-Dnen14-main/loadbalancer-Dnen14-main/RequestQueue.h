#ifndef REQUEST_QUEUE_H
#define REQUEST_QUEUE_H
#include "Request.h"
#include <queue>
using std::queue;

/**
 * @file RequestQueue.h
 * @brief Defines the RequestQueue class, which manages a queue of HTTP requests.
 * 
 * This class encapsulates the functionality for handling a queue of HTTP requests, 
 * providing methods to add, remove, process, and query requests in the queue.
 */

/**
 * @class RequestQueue
 * @brief A class that manages a queue of HTTP requests.
 * 
 * The RequestQueue class provides functionality to add requests to the queue, 
 * remove and process the next request in line, and check the current status 
 * of the queue (such as size and emptiness).
 */
class RequestQueue {
private:

    /**
     * @brief A queue to hold Request objects.
     */
    queue<Request> requestQueue;

public:

    /**
     * @brief Default constructor for the RequestQueue class.
     * 
     * Initializes an empty request queue.
     */
    RequestQueue();

    /**
     * @brief Destructor for the RequestQueue class.
     */
    ~RequestQueue();

    /**
     * @brief Adds a new request to the queue.
     * 
     * @param request The Request object to be added to the queue.
     */
    void add_request(const Request& request);

    /**
     * @brief Removes the front request from the queue.
     */
    void remove_request();

    /**
     * @brief Processes the next request in the queue.
     * 
     * Processes the front request by simulating its handling and then removing it from the queue.
     */
    void process_next_request();

    /**
     * @brief Checks if the request queue is empty.
     * 
     * @return True if the queue is empty, false otherwise.
     */
    bool is_empty() const;

    /**
     * @brief Gets the current size of the request queue.
     * 
     * @return The number of requests currently in the queue.
     */
    int get_size() const;

    /**
     * @brief returns a reference
     */
    Request& get_front_request();
};

#endif
