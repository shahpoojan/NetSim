// Definition of PacketSyncApplication class
// ECE8893, Final Project, Fall 2012

#ifndef __ON_OFF_APPLICATION_H__
#define __ON_OFF_APPLICATION_H__

#include "Application.h"
#include "Handler.h"

class PacketSyncApplication  : public Application
{
  public:
  PacketSyncApplication();
  void         SetPeerAddress(int peerAddr);
  virtual void Start(); // Start the application
  virtual void Stop();  // Stop the application
  virtual void Handle(Event*, Time_t);
private:
  int totalPacketsReceived;  // statistics
  int totalBytesReceived;
};
#endif
