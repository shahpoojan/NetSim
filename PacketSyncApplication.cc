#include"PacketSyncApplication.h"
//#include "Application.cc"

PacketSyncApplication::PacketSyncApplication():Application()
{
      totalPacketsReceived=0; // statistics
      totalBytesReceived=0;
}

//Added by Charmi
void PacketSyncApplication::ReceivedData(int count0)
{
      totalPacketsReceived++;
      totalBytesReceived+=count0;
}

void PacketSyncApplication::Start()
{

}

void PacketSyncApplication::Stop()
{

}

void PacketSyncApplication::Handle(Node*, int)
{

}
