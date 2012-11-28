// Definition of PacketSyncApplication class
// ECE8893, Final Project, Fall 2012

#ifndef __PACKET_SYNC_APPLICATION_H__
#define __PACKET_SYNC_APPLICATION_H__

#include "Application.h"
#include "Handler.h"

class PacketSyncApplication  : public Application
{
  public:
  PacketSyncApplication();
  //void         SetPeerAddress(int peerAddr); //Commented by Charmi
  void ReceivedData(int count0);
  virtual void Start(); // Start the application
  virtual void Stop();  // Stop the application
  virtual void Handle(Event*, Time_t);
private:
  int totalPacketsReceived;  // statistics
  int totalBytesReceived;
};
#endif
