// Definition of NetworkInterface class
// ECE8893, Final Project, Fall 2012

#ifndef __NETWORK_INTERFACE_H__
#define __NETWORK_INTERFACE_H__

#include "CommonDefs.h"
#include "Handler.h"

class NetworkLink;
class Packet;
class Queue;
class Node;

class NetworkInterface : public Handler
{
public:
  NetworkInterface(); // Constructor
  void AddP2PLink(NetworkLink*);
  void Send(Packet*); // Send specified packet to p2p peer
  void Handle(Event*, Time_t); // Handle event
public:
  NetworkLink*      link;
  Queue*            queue; // Associated node
  Node*             node;  // Associated node
  bool              busy;  // true if busy sending a packet
};

#endif



