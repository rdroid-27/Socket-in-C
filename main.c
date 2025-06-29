#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


int main(){

    int socketFD = socket(AF_INET, SOCK_STREAM, 0);

    char *ip = "64.233.180.27";

    struct sockaddr_in address;

    address.sin_port = htons(80);
    address.sin_family =  AF_INET;
    inet_pton(AF_INET,ip,&address.sin_addr.s_addr);

    int result = connect(socketFD,(const struct sockaddr *)(&address), sizeof(address));

    if(result==0) printf("COnnection SUccessfull!\n");

    return 0;
}