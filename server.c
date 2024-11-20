#include <errno.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080

int main(){
    //create socket
    //af_net is for tcp ipv4, sockstream is protocol
   int sockfd = socket(AF_INET, SOCK_STREAM, 0);
   // check for errors
    if (sockfd == -1) {
        perror("webserver (socket)");
        return 1;
    }
    printf("socket created successfully\n");
    // create address
    struct sockaddr_in host_addr;
    int host_addrlen = sizeof(host_addr);

    host_addr.sin_family = AF_INET;
    host_addr.sin_port = htons(PORT);
    host_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    // bind the socket to the address
    if (bind(sockfd, (struct sockaddr *)&host_addr, host_addrlen) != 0) {
        perror("webserver (bind)");
        return 1;
    }
    printf("socket successfully bound to address\n");

    return 0;
}