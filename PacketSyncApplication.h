// Definition of PacketSyncApplication class
// ECE8893, Final Project, Fall 2012

#ifndef __PACKET_SYNC_APPLICATION_H__
#define __PACKET_SYNC_APPLICATION_H__

#include "Application.h"
//#include "Handler.h"

class Node;

class PacketSyncApplication  : public Application
{
  public:
  PacketSyncApplication();
  //void         SetPeerAddress(int peerAddr); //Commented by Charmi
  void ReceivedData(int count0);
  void Start(Node*);
  void Stop(Node*);
  void Handle(Node*, int); // Handle events
private:
  int totalPacketsReceived;  // statistics
  int totalBytesReceived;
  int sentPackets;
  int sentBytes;
};
#endif
