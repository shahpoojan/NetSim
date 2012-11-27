#include"PacketSyncApplication.h"

PacketSyncApplication::PacketSyncApplication():Application()
{
      totalPacketsReceived=0; // statistics
      totalBytesReceived=0;
}

//Added by Charmi
PacketSyncApplication::ReceivedData(int count0)
{
      totalPacketsReceived++;
      totalBytesReceived+=count0;
}