// Definition of Node class
// ECE8893, Final Project, Fall 2012

#ifndef __NODE_H__
#define __NODE_H__

#include <vector>
#include "Packet.h"
#include "Handler.h"

class NetworkInterface;
class Application;

class Node : public Handler
{
public:
  Node(int addr); // Constructor
  void ComputeRoutes(std::vector<Node*> nodes);     // Populate the routing table
  void AddNeighbor(Node*);  // Add a new interface, p2p link and neighbor node
  void AddInterface  (NetworkInterface*);
  void AddApplication(Application*);
  void Send(int count, int dest);  // Send count bytes to specified destination
  void Receive(int count, int source);  // Received count bytes from specified source
  int getNodeCount();
  static int NodeCount;
  void Handle(Event*, Time_t);
  std::vector<Application*>      applications;

private:
  unsigned int                   address;    // This node's address
  std::vector<NetworkInterface*> interfaces;
//  std::vector<Application*>      applications;
  std::vector<Node*>		 neighbors;
  std::vector<int>               nextHopRoutes;
//  static int NodeCount;
};
  
#endif
