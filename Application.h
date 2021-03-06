// Definition of Application abstract base class
// ECE8893, Final Project, Fall 2012

#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "CommonDefs.h"
//#include "Handler.h"
//#include "Simulator.h"

#define PACKET_SIZE 800
class Node;
class Simulator;

//typedef std::multiset <EventBase*, event_less> EventSet_t;

class Application// : public Handler
{
  public:
  Application(); // Default constructor
  void AttachToNode(Node*); // Attach this application to a node
  virtual void Start(Node*) = 0; // Start the application
  virtual void Stop(Node*)  = 0; // Stop the application
  virtual void Handle(Node*, int) = 0; // Handle events
public:
  Node* node;
  Simulator* sim;
};


#endif
