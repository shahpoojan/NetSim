// Definition of Application abstract base class
// ECE8893, Final Project, Fall 2012

#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "CommonDefs.h"
#include "Handler.h"
#include "Simulator.h"
class Node;
//class Simulator;

class Application : public Handler
{
  public:
  Application(); // Default constructor
  void AttachToNode(Node*); // Attach this application to a node
  virtual void Start() = 0; // Start the application
  virtual void Stop()  = 0; // Stop the application
  virtual void Handle(Event*, Time_t); // Handle events
public:
  Node* node;
  Simulator* sim;
};


#endif
