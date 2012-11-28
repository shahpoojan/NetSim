// Definition of NetworkInterface class
// ECE8893, Final Project, Fall 2012

#ifndef __NETWORK_INTERFACE_H__
#define __NETWORK_INTERFACE_H__

#include "CommonDefs.h"
#include "Event.h"
//#include "Handler.h"

class NetworkLink;
class Packet;
class Queue;
class Node;

class NetworkInterface// : public Handler
{
public:
  NetworkInterface(); // Constructor
  NetworkInterface(double); //Constructor with data rate as argument (makes the implementation flexible)
  void AddP2PLink(NetworkLink*, NetworkInterface*, double link_delay);
  void Send(Packet*); // Send specified packet to p2p peer
  void Handle(Event*, Time_t); // Handle event
public:
  NetworkLink*  link;
  Queue*        queue; // Associated node
  Node*         node;  // Associated node
  bool          busy;  // true if busy sending a packet
  //added by apkarande
  double interface_data_rate;	//data rate for each interface
  
};

#endif



