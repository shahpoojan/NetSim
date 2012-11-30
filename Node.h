// Definition of Node class
// ECE8893, Final Project, Fall 2012

#ifndef __NODE_H__
#define __NODE_H__

#include <vector>
#include <list>


#include "Packet.h"
//#include "Handler.h"

#define G_NODE 0
#define R_NODE 1
#define H_NODE 2

class NetworkInterface;
class Application;
class Simulator;

class Node //: public Handler
{
public:
  Node(int addr); // Constructor
  void ComputeRoutes(std::vector<Node*> nodes);     // Populate the routing table
  void AddNeighbor(int, Node*, int);  // Add a new interface, p2p link and neighbor node
  void AddInterface  (NetworkInterface*);
  void AddApplication(Application*);
  void Send(int count, int dest);  // Send count bytes to specified destination
  void Receive(int count, int source);  // Received count bytes from specified source
  int getNodeCount();
  static int NodeCount;
  unsigned char node_type;		//0: G, 1: R, 2: H
  int GetAddr();
  NetworkInterface* GetInterface(int);
  //void Handle(Event*, Time_t);
  std::vector<Application*>      applications;
  void PacketGenerationComplete(int peer_addr, int size);
  Simulator* sim;
  int getNextHopRoute(int);

std::list<Node*>               path;

private:
  void bsf();
  void djikstra(std::vector<Node*>,int);
  int distance;
  int solved;
  Node *path_from;
  unsigned int                   address;    // This node's address
  std::vector<NetworkInterface*> interfaces;
//  std::vector<Application*>      applications;
  std::list<Node*>		 neighbors;
  std::vector<int>               nextHopRoutes;
  //std::list<Node*> 		 path;
//  static int NodeCount;
};

void CreateBiDirLinks(NetworkInterface* a, NetworkInterface* b);

#endif
