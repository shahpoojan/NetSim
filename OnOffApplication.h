// Definition of OnOffApplication class
// ECE8893, Final Project, Fall 2012

#ifndef __ON_OFF_APPLICATION_H__
#define __ON_OFF_APPLICATION_H__

#include "Application.h"
#include "Handler.h"

class Node;
//class Simulator;

class OnOffApplication  : public Application
{
  public:
  OnOffApplication(double rate0, double meanOffTime0, double meanOnTime0);
  void         SetPeerAddress(int peerAddr);
  void Start(); // Start the application
  void Stop();  // Stop the application
  void Handle();
void foo();
  //Node *parentNode;
private:
  double rateWhenOn;
  double meanOffTime;
  double meanOnTime;
  int    peerAddress;
  //Simulator sim;
};

#endif
