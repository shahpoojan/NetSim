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

void PacketSyncApplication::SentData (int count0)
{
	sentPackets++;
    sentBytes+=count0;
}

int PacketSyncApplication::getReceived()
{
	return totalPacketsReceived;
}

int PacketSyncApplication::getSent()
{
	return sentPackets;
}

/************************************* Event Handlers ****************************************/
void PacketSyncApplication::Handle(Node* n, int type)
{

}


void PacketSyncApplication::Start(Node* n )
{

}

void PacketSyncApplication::Stop(Node* n)
{

}

