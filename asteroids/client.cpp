/****************************************************************************
* Program:
*    Lab RockClientT2, Rock/Paper/Scissors with Sockets - Client Code
*    Brother Jones, CS 460
* Author:
*    Robert Dickerson
* Summary:
*    The client for a rock, paper, scissors game that plays with another
*    client through a server
*
*****************************************************************************/

#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <stdio.h>
#include <stdbool.h>

using namespace std;

void error(const char *);

int main(int argc, char *argv[])
{
   int sockfd, port, servlen, n;
   struct sockaddr_in  serv_addr;
   char buffer[256];
   struct hostent *server;

   // check to see if ip address and port were entered from the command line.
   /*if (argc == 3)
   {
      server = gethostbyname(argv[1]);
      port = atoi(argv[2]);
   }
   else
   {
      cout << "your need to enter the proper ip address then port number "
           << "from the command line" << endl;
           }*/

   server = gethostbyname("157.201.194.204");
   port = 6789;
   //create socket
   sockfd = socket(AF_INET, SOCK_STREAM, 0);  
   bzero((char *)&serv_addr,sizeof(serv_addr));
   serv_addr.sin_family = AF_INET;
   bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
   serv_addr.sin_port = htons(port);

   // create a socket and see if the server replied
   if ((sockfd = socket(AF_INET, SOCK_STREAM,0)) < 0)
       error("Creating socket");
   if (connect(sockfd, (struct sockaddr *)  
                        &serv_addr, sizeof(serv_addr)) < 0)
       error("Connecting");
    n = read(sockfd,buffer,255);

   printf("Time to play Rock Paper Scissors!!\n");

   // continuosly play rps until a client quits
   while(1)
   {
    
      bzero(buffer,256);
      fgets(buffer,255,stdin);

    
      write(sockfd,buffer,strlen(buffer));
   
      n = write(sockfd,buffer,strlen(buffer));
      bzero(buffer,256);
      n=read(sockfd,buffer,255);
       
      // tell the client if he won or lost!
      std :: cout << buffer << std :: endl;
    
   }


   
   close(sockfd);
   return 0;
}

void error(const char *msg)
{
    perror(msg);
    exit(0);
}

