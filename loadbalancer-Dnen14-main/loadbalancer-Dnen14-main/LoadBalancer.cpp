/**
 * @file LoadBalancer.cpp
 * @brief Implementation of a LoadBalancer for managing web servers and request distribution.
 * 
 * This file contains the implementation of the LoadBalancer class, which is responsible
 * for managing multiple web servers and distributing incoming requests among them. It 
 * supports dynamic adjustment of the number of active servers based on the current 
 * load, allowing for efficient handling of HTTP requests. The LoadBalancer can add or
 * remove servers based on the request queue size and processes requests in a round-robin
 * fashion.
 * 
 */

/**
 * @class LoadBalancer
 * @brief Manages multiple web servers and distributes incoming requests among them.
 * 
 * The LoadBalancer class is responsible for maintaining a pool of web servers and
 * efficiently distributing HTTP requests to these servers. It dynamically adjusts 
 * the number of active servers based on the current load, ensuring optimal utilization
 * of resources. The class includes functionalities for adding and removing servers,
 * processing requests in a round-robin manner, and monitoring the status of the request queue.
 * 
 * Key Features:
 * - Dynamic server management based on request load.
 * - Round-robin request distribution to available servers.
 * - Monitoring and logging of active servers and remaining requests.
 * 
 * @note The LoadBalancer expects a minimum of one server and can handle multiple 
 * requests concurrently based on the configuration.
 */
#include "LoadBalancer.h"
#include "RequestQueue.h"
#include <iostream>
using std::cout, std::endl;


/**
 * @brief Constructs a LoadBalancer with a specified number of initial servers.
 *
 * @param initialServers Number of servers to initialize.
 * @param portBase Base port number for the servers.
 * @param maxServers Maximum allowable number of servers.
 */
LoadBalancer::LoadBalancer(int initialServers, int portBase, int maxServers)
    : currentServer(0), maxServers(maxServers) {
    for (int i = 0; i < initialServers; ++i) {
        servers.push_back(new WebServer(portBase + i));
    }
    activeServers = 0;
    count = 0;
}

/**
 * @brief Destructor for the LoadBalancer class.
 *
 * Cleans up any resources associated with the LoadBalancer.
 */
LoadBalancer::~LoadBalancer() {
}

/**
 * @brief Adds a request to the queue.
 *
 * @param request The request to be added to the queue.
 */
void LoadBalancer::add_request(const Request& request) {
    requestQueue.add_request(request);
}

/**
 * @brief Distributes requests among the available servers.
 *
 * Processes requests in the queue by delegating them to available web servers.
 * Increments the request processing count and logs the status to the console.
 */
void LoadBalancer::distribute_requests() {
   if (requestQueue.is_empty()) return;

    adjust_servers();
    WebServer* server = servers[currentServer];
    server->start();

    Request& request = requestQueue.get_front_request();
    request.decrement_task_time();

    cout << "[INFO] Processing request on server port " << server->get_port()
              << " (Remaining task time: " << request.get_task_time() << " cycles)" << endl;

    if (request.is_completed()) {
        cout << "[INFO] Request completed and removed from the queue." << endl;
        requestQueue.process_next_request();
    }

    server->stop();
    currentServer = (currentServer + 1) % servers.size();
}

/**
 * @brief Gets the current size of the request queue.
 *
 * @return The number of requests currently in the queue.
 */
int LoadBalancer::get_queue_size(){
    return requestQueue.get_size();
}

/**
 * @brief Gets the count of currently active servers.
 *
 * @return The number of active servers.
 */
int LoadBalancer::get_active_server_count(){
    return activeServers;
}

/**
 * @brief Prints the number of remaining requests in the queue.
 *
 * Outputs the current size of the request queue to the console.
 */
void LoadBalancer::print_remaining_requests() {
        cout << "[END STAUS] Remaining requests in queue: " << requestQueue.get_size() << endl;
}

/**
 * @brief Adds a new server to the LoadBalancer.
 *
 * If the maximum number of servers has not been reached, a new server is created and added.
 */
void LoadBalancer::add_server() {
    if ((int) servers.size() < maxServers) {
        int port = 8080 + servers.size();
        servers.push_back(new WebServer(port));
        activeServers++;
        cout << "[INFO] Added a new WebServer on port " << port << ". Total servers: " << servers.size() << endl;
    }
}

/**
 * @brief Removes a server from the LoadBalancer.
 *
 * If more than one server is active, the last server is removed,
 * and the current server index is adjusted accordingly.
 */
void LoadBalancer::remove_server() {
    if (servers.size() > 1) {
        WebServer* server = servers.back();
        int port = server->get_port();
        delete server;
        activeServers--;
        if(currentServer != 0){
            currentServer--;
        }
        servers.pop_back();
        cout << "[INFO] Removed WebServer on port " << port << ". Total servers: " << servers.size() << endl;
    }
}

/**
 * @brief Adjusts the number of active servers based on the request queue size.
 *
 * Adds or removes servers depending on the current demand based on the queue size.
 */
void LoadBalancer::adjust_servers() {
    int queueSize = get_queue_size();
    if (queueSize > (int) servers.size() * 5) {
        add_server();
    } else if ((queueSize < (int) servers.size() * 2) && servers.size() > 1) {
        remove_server();
    }
}