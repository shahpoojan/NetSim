// Definition of Simulator class
// ECE8893, Final Project, Fall 2012

#ifndef __SIMULATOR_H__
#define __SIMULATOR_H__

#include "CommonDefs.h"
#include "Handler.h"


class Event;

class Simulator : public Handler // Simulator is a subclass of handler
{
public:
  Simulator();
  void Stop(); // Stop executing events and exit
  void Run();  // Starting executing events
  void StopAt(Time_t);
  void Schedule(Handler*, Event*, Time_t); // Schedule a new future event
  void ComputeRoutes();                    // Compute routing tables at every node
  // Inherited from Handler
  virtual void Handle(Event*, Time_t);     // Handle the specified event
public:
  // Your member variables here
};
#endif
