/**
 * @file LoadBalancer.h
 * @brief Declaration of the LoadBalancer class, responsible for managing and distributing requests to web servers.
 * 
 * This file contains the definition of the LoadBalancer class, which handles the distribution of incoming
 * requests across multiple web servers. It ensures efficient use of resources by dynamically adjusting 
 * the number of active servers based on the size of the request queue. The class supports adding servers, 
 * removing servers, and processing requests from a queue.
 * 
 * The LoadBalancer class works closely with the WebServer and RequestQueue classes to manage web traffic 
 * and optimize server performance.
 * 
 * @see WebServer
 * @see RequestQueue
 *
 */

#ifndef LOADBALANCER_H
#define LOADBALANCER_H

#include "Webserver.h"
#include "RequestQueue.h"


/**
 * @class LoadBalancer
 * @brief Manages a set of web servers and distributes incoming requests among them.
 *
 * The LoadBalancer class handles the addition and distribution of requests to
 * multiple web servers, ensuring optimal use of available resources.
 */
class LoadBalancer {
private:
    std::vector<WebServer*> servers;
    RequestQueue requestQueue;
    int currentServer;
    int numServers;
    int maxServers;
    int activeServers;
    int count;

public:

    /**
     * @brief Constructs a LoadBalancer with a specified number of servers.
     * 
     * @param numServers Number of initial servers to create.
     * @param portBase Base port number for the servers.
     * @param maxServers Maximum allowable servers.
     */
    LoadBalancer(int numServers, int portBase, int maxServers);

    /**
     * @brief Destructor for the LoadBalancer class.
     * 
     * Cleans up any resources associated with the LoadBalancer.
     */
    ~LoadBalancer();

    /**
     * @brief Adds a request to the queue.
     * 
     * @param request The request to be added to the queue.
     */
    void add_request(const Request& request);

    /**
     * @brief Distributes requests among the available servers.
     * 
     * Processes requests in the queue by delegating them to available web servers.
     */
    void distribute_requests();

    /**
     * @brief Gets the current size of the request queue.
     * 
     * @return The number of requests currently in the queue.
     */
    int get_queue_size();

    /**
     * @brief Adjusts the number of active servers based on the request queue size.
     * 
     * Adds or removes servers depending on the current demand.
     */
    void adjust_servers();

    /**
     * @brief Adds a new server to the LoadBalancer.
     * 
     * If the maximum number of servers has not been reached, a new server is created and added.
     */
    void add_server();

    /**
     * @brief Removes a server from the LoadBalancer.
     * 
     * If more than one server is active, the last server is removed.
     */
    void remove_server();

    /**
     * @brief Gets the count of currently active servers.
     * 
     * @return The number of active servers.
     */
    int get_active_server_count();

    /**
     * @brief Prints the number of remaining requests in the queue.
     * 
     * Outputs the current size of the request queue to the console.
     */
    void print_remaining_requests();
};

#endif
