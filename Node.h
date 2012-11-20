// Definition of Node class
// ECE8893, Final Project, Fall 2012

#ifndef __NODE_H__
#define __NODE_H__

#include <vector>

class NetworkInterface;
class Application;

class Node 
{
public:
  Node(); // Constructor
  void ComputeRoutes();     // Populate the routing table
  void AddNeighbor(Node*);  // Add a new interface, p2p link and neighbor node
  void AddInterface  (NetworkInterface*);
  void AddApplication(Application*);
  void Send(int count, int dest);  // Send count bytes to specified destination
  void Receive(int count, int source);  // Received count bytes from specified source
private:
  unsigned int                   address;    // This node's address
  std::vector<NetworkInterface*> interfaces;
  std::vector<Application*>      applications;
  std::vector<int>               nextHopRoutes;
};
  
#endif
