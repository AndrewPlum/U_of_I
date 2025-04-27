/*
Andrew Plum
Professor Bolden
CS 270
11/13/22
*/

    /*
    ***Assignment #3 - calculator_server.c***
    */

// Libraries

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

// Prototypes

void error(const char *);

// Main

int main(int argc, char *argv[]){

    // variable declarations for calculator

    int num1, num2, answer;
    char *token;
    char string_answer_sent_to_client[256];

    // variable declarations for socket

    int sockfd, newsockfd, portno;
    socklen_t clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int n;

    // server side socket code

    if(argc < 2){
        fprintf(stderr,"ERROR, no port provided\n");
        exit(1);
    }
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        error("ERROR opening socket");
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    if(bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0){
        error("ERROR on binding");
    }
    listen(sockfd, 5);
    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0){
        error("ERROR on accept");
    }
    bzero(buffer, 256);
    n = read(newsockfd, buffer, 255);
    if(n < 0){
        error("ERROR reading from socket");
    }
    printf("Server received the equation: %s\n", buffer);

    // evaluate answer of equation received

    if(buffer[0] == '+'){
        token = strtok(buffer, " ");
        token = strtok(NULL, " ");
        num1 = atoi(token);
        token = strtok(NULL, " ");
        num2 = atoi(token);
        answer = num1 + num2;
    }
    if(buffer[0] == '-'){
        token = strtok(buffer, " ");
        token = strtok(NULL, " ");
        num1 = atoi(token);
        token = strtok(NULL, " ");
        num2 = atoi(token);
        answer = num1 - num2;
    }
    if(buffer[0] == '*'){
        token = strtok(buffer, " ");
        token = strtok(NULL, " ");
        num1 = atoi(token);
        token = strtok(NULL, " ");
        num2 = atoi(token);
        answer = num1 * num2;
    }
    if(buffer[0] == '/'){
        token = strtok(buffer, " ");
        token = strtok(NULL, " ");
        num1 = atoi(token);
        token = strtok(NULL, " ");
        num2 = atoi(token);
        answer = num1 / num2;
    }
    if(buffer[0] == '%'){
        token = strtok(buffer, " ");
        token = strtok(NULL, " ");
        num1 = atoi(token);
        token = strtok(NULL, " ");
        num2 = atoi(token);
        answer = num1 % num2;
    }

    // print answer calculated from equation on server side

    printf("Server side:\n"); // print message to signify message is from server side
    printf("Answer to the equation sent from client to server = %d\n", answer); // print answer on server side

    // put answer into string using sprintf();

    sprintf(string_answer_sent_to_client, "Answer to the equation sent from client to server = %d", answer);

    // send message to client and close socket

    n = write(newsockfd, string_answer_sent_to_client, 256); // send string answer to client
    if(n < 0){
        error("ERROR writing to socket");
    }
    close(newsockfd);
    close(sockfd);

    // end of program

    return 0;
}

// Definitions

void error(const char *msg){
    perror(msg);
    exit(1);
}
