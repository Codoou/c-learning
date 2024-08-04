// Server side C program to demonstrate Socket
// programming
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#define PORT 8080

int main() {

    int sockfd, new_socket;
    ssize_t valread;
    struct sockaddr_in address;
    socklen_t addrelen = sizeof(address);
    char buffer[1024] = { 0 };
    char* hello = "Hello from server";

    sockfd = socket(AF_LOCAL, SOCK_STREAM, 0);

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    bind(sockfd, (struct sockaddr*)&address, sizeof(address));

    listen(sockfd, 3);
    
    while(1){
        new_socket = accept(sockfd, (struct sockaddr*)&address, &addrelen);

        valread = read(new_socket, buffer, 1024 - 1);
        send(new_socket, hello, strlen(hello), 0);
    }


    // closing the connected socket
    close(new_socket);
    // closing the listening socket
    close(sockfd);

    return 0;
}