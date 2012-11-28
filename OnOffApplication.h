// Definition of OnOffApplication class
// ECE8893, Final Project, Fall 2012

#ifndef __ON_OFF_APPLICATION_H__
#define __ON_OFF_APPLICATION_H__

#include "Application.h"
//#include "Handler.h"
class Node;
//class Simulator;

//typedef std::multiset <EventBase*, event_less> EventSet_t;

class OnOffApplication  : public Application
{
  public:
  OnOffApplication(double rate0, double meanOffTime0, double meanOnTime0);
  void         SetPeerAddress(int peerAddr);
  virtual void Start(); // Start the application
  virtual void Stop();  // Stop the application
  virtual void Handle();
  //Simulator *sim;

  private:
  double rateWhenOn;
  double meanOffTime;
  double meanOnTime;
  int    peerAddress;
};

#endif
