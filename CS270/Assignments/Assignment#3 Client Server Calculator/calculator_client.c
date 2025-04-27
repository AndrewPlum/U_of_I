/*
Andrew Plum
Professor Bolden
CS 270
11/13/22
*/

    /*
    ***Assignment #3 - calculator_client.c***
    */

// Libraries

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>

// Prototypes

void error(const char *);

// Main

int main(int argc, char *argv[]){

    // variable declarations for socket

    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[256];

    // client side server code

    if(argc < 3){
        fprintf(stderr,"usage %s hostname port\n", argv[0]);
        exit(0);
    }
    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        error("ERROR opening socket");
    }
    server = gethostbyname(argv[1]);
    if(server == NULL){
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);
    if(connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0){
        error("ERROR connecting");
    }
    printf("Enter equation you want calculated in postfix: ");
    bzero(buffer, 256);
    fgets(buffer, 255, stdin);
    n = write(sockfd, buffer, strlen(buffer));
    if(n < 0){
        error("ERROR writing to socket");
    }
    bzero(buffer, 256);
    n = read(sockfd, buffer, 255);
    if(n < 0){
        error("ERROR reading from socket");
    }

    // print answer sent from server on client side and close socket

    printf("Client side:\n"); // print message to signify message is from client side
    printf("%s\n", buffer); // print what is sent from server
    close(sockfd);

    // end of program

    return 0;
}

// Definitions

void error(const char *msg){
    perror(msg);
    exit(0);
}
