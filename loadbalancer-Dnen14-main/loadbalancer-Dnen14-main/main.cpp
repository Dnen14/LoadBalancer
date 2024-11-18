#include "Webserver.h"
#include "LoadBalancer.h"
#include "Request.h"
#include "RequestQueue.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <thread>
#include <chrono>
#include <typeinfo>
#include <string>
#include <fstream>

/**
 * @file main.cpp
 * @brief Load balancer simulation using web servers and request handling.
 * 
 * This file implements a simple load balancer that manages multiple web servers
 * and simulates the processing of HTTP requests. It allows users to specify the
 * number of servers and the total number of cycles for the simulation. The load 
 * balancer randomly generates requests and distributes them among the available 
 * servers. The simulation logs the starting and ending status of the request queue,
 * including the active and inactive servers.
 * 
 * The main function handles user input, initializes the LoadBalancer instance, 
 * populates the request queue, and generates requests while displaying status updates.
 * 
 */

using std::cout, std::endl, std::cin, std::string, std::to_string, std::ofstream, std::cerr, std::streambuf;

    /** Number of servers to be used by the LoadBalancer. */
    int numServers;
    /** Maximum time for a task to be processed (in milliseconds). */
    int maxTaskTime = 5;
    /** Total number of cycles the LoadBalancer will run. */
    int totalCycles;
    /** Initial size of the request queue. */
    int initialQueueSize;
    /** Minimum time for a task to be processed (in milliseconds). */
    int minTaskTime = 1;

/**
 * @brief Prints the starting size of the request queue.
 */
void printStartingQueue(){
    cout << " [LOG] Starting queue size: " << initialQueueSize << endl;
}

/**
 * @brief Generates requests randomly and adds them to the LoadBalancer.
 *
 * This function runs for a specified number of cycles, generating new requests
 * based on random conditions, adding them to the LoadBalancer, and distributing
 * requests to the servers. It also sleeps for a random amount of time between
 * task processing.
 *
 * @param lb Reference to the LoadBalancer instance.
 */
void randomAddRequest(LoadBalancer &lb){
    for (int cycle = 0; cycle < totalCycles; ++cycle) {
        if (rand() < 107374182) {
            Request newReq;
            newReq.set_method("POST");
            newReq.set_url("/newtask" + to_string(cycle));
            newReq.set_headers("Host: loadbalancer.com\nUser-Agent: C++-Client");
            newReq.set_body("New request body at cycle " + to_string(cycle));
            //lb.add_request(newReq);
           //cout << "[LOG] New request generated at cycle " << cycle << endl;

           int randomTaskTime = rand() % maxTaskTime + minTaskTime;
           newReq.set_task_time(randomTaskTime);

            lb.add_request(newReq);
            cout << "[LOG] New request generated at cycle " << cycle 
                      << " with task time " << randomTaskTime << " cycles." << endl;
        }

        lb.distribute_requests();
    }
}

/**
 * @brief Prints the ending status of the LoadBalancer.
 *
 * Displays the ending queue size, the number of active servers, the number of inactive
 * servers, and prints any remaining requests in the queue.
 *
 * @param lb Reference to the LoadBalancer instance.
 */
void printEndingQueue(LoadBalancer &lb){
    cout << "[END STATUS] Ending queue size: " << lb.get_queue_size() << endl;
    cout << "[END STATUS] Active servers: " << lb.get_active_server_count() << endl;
    cout << "[END STATUS] In-active servers: " <<  numServers - lb.get_active_server_count() << endl;
    lb.print_remaining_requests();

}

/**
 * @brief Prints the range of task processing times.
 */
void printTaskRange(){
    cout << "Task time range: " << minTaskTime << " to " << maxTaskTime << " clock cycles" << endl;
}

/**
 * @brief The main function to run the load balancer simulation.
 *
 * * \mainpage My LoadBalancer Documentation
 * Prompts the user for input regarding the number of servers and total cycles,
 * initializes the LoadBalancer, populates the request queue, and starts generating
 * requests. Finally, it prints the ending status of the LoadBalancer.
 * 
 * @return 0 on successful execution.
 */
int main(void) {
    srand(static_cast<unsigned int>(time(nullptr)));

    cout << "Enter in the number of servers and the total cyles you want to run the load balancer in this format (serverSize time) not including the paratheses" << endl;
    cin >> numServers >> totalCycles;

    if(cin.fail()){
        cout << "Please enter a valid input" << endl;
        return 0;
    }
    initialQueueSize = numServers * 100;
    
    ofstream outFile("Log.txt");

    if(!outFile.is_open()){
        cerr << "Error opening file!" << endl;
        return 1;
    }

    streambuf* originalCoutBuffer = std::cout.rdbuf();
    cout.rdbuf(outFile.rdbuf());

    LoadBalancer lb(0, 8080, numServers);

    for (int i = 0; i < initialQueueSize; ++i) {
        int randomTaskTime = rand() % maxTaskTime + minTaskTime;
        Request req;
        req.set_method("GET");
        req.set_url("/task" + to_string(i));
        req.set_headers("Host: loadbalancer.com\nUser-Agent: C++-Client");
        req.set_body("Request body " + to_string(i));
        req.set_task_time(randomTaskTime);
        lb.add_request(req);
    }

    printStartingQueue();
    randomAddRequest(lb);
    printEndingQueue(lb);
    printTaskRange();

    outFile.close();
    cout.rdbuf(originalCoutBuffer);

    return 0;
}
