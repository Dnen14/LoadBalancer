CC = g++
CFLAGS = -Wall -Werror -std=c++17

all: myprogram
myprogram: main.o utils.o RequestQueue.o LoadBalancer.o Request.o Webserver.o
	$(CC) $(CFLAGS) -o myprogram main.o utils.o RequestQueue.o LoadBalancer.o Request.o Webserver.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

utils.o: utils.cpp
	$(CC) $(CFLAGS) -c utils.cpp

RequestQueue.o: RequestQueue.cpp
	$(CC) $(CFLAGS) -c RequestQueue.cpp

LoadBalancer.o: LoadBalancer.cpp
	$(CC) $(CFLAGS) -c LoadBalancer.cpp

Request.o: Request.cpp
	$(CC) $(CFLAGS) -c Request.cpp

Webserver.o: Webserver.cpp
	$(CC) $(CFLAGS) -c Webserver.cpp

clean:
	rm -f myprogram *.o
