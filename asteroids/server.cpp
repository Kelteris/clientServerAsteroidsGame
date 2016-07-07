/************************************************************************
 * SERVER.CPP
 *     The server should do the following:
 *     1. Recieve coordinates from ships and bullets
 *     2. Send back coordinates of ship and bullets to client
 * Authors:
 *    Jacob Casperson
 *    Robert Dickerson
 ***********************************************************************/
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <errno.h>

using namespace std;

struct Player {
   char buffer[256];
   int ConnectFD;
   bool connected;
   string statusString;
};

// we'll start as a 1 player game for now
Player one;

void parseString()
{


}

int main(int argc, char *argv[])
{
   // not sure what this is, but I think we need it (welcome socket?)
   struct sockaddr_in sa;

   // Socket (welcome socket or connection socket?)
   int SocketFD = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

   // let us know if something terrible happens and we can't create our socket
   if (SocketFD == -1) {
      perror("cannot create socket");
      exit(EXIT_FAILURE);
   }

   // Assign the port number
   /*if (argc < 2)
   {
      cout << "No args! Port number = 1100\n";
      sa.sin_port = htons(1100);
   }
   else
   {
      int portNumber = atoi(argv[1]);
      sa.sin_port = htons(portNumber);
      }*/

   int portNumber = 6789;
   sa.sin_port = htons(portNumber);

   
      // what is this?
   sa.sin_addr.s_addr = htonl(INADDR_ANY);

   // More error handling
   if (bind(SocketFD,(struct sockaddr *)&sa, sizeof sa) == -1) {
      perror("bind failed");
      close(SocketFD);
      exit(EXIT_FAILURE);
   }
  
   if (listen(SocketFD, 10) == -1) {
      perror("listen failed");
      close(SocketFD);
      exit(EXIT_FAILURE);
   }

   // what to do while no one is connected to the server
   while(one.connected == false)
   {
      if (one.connected == false){           
            one.ConnectFD = accept(SocketFD, NULL, NULL);
            one.connected = true;
      }
      
   }
   // what to do when you are connected
   while(true)
   {
      one.statusString = read(one.ConnectFD,one.buffer,255);
      parseString();
   }
      
   return 0;
}
