// Main program for NetSim
// ECE8893 Final Project, Fall 2012

#include "Application.h"
#include "CommonDefs.h"
#include "DropTailQueue.h"
#include "Handler.h"
#include "NetworkInterface.h"
#include "NetworkLink.h"
#include "Node.h"
#include "OnOffApplication.h"
#include "Packet.h"
#include "PacketSyncApplication.h"
#include "Queue.h"
#include "Simulator.h"
#include <iostream>
#include<cstdlib>

using namespace std;

int main()
{
      //running the simulation point 2 (Added by Charmi)
      double r=0.5; //default value
      double rate0=r*10000000; //rate is r times 10Mbps
      double meanOffTime0=(float)rand()/(float)RAND_MAX; //time in seconds range 0 to 1 sec
      double meanOnTime0=(float)rand()/(float)RAND_MAX;

      Simulator* sim = new Simulator();

      Node* H_nodes[16];
      OnOffApplication OnOff(rate0, meanOffTime0, meanOnTime0);
      for(int i=0; i<16; i++)
      {
	H_nodes[i] = new Node(i);
	double meanOffTime0=(float)rand()/(float)RAND_MAX; //time in seconds range 0 to 1 sec
      	double meanOnTime0=(float)rand()/(float)RAND_MAX;
	OnOffApplication *OnOff = new OnOffApplication(rate0, meanOffTime0, meanOnTime0);

	PacketSyncApplication *SinkApp = new PacketSyncApplication();
	H_nodes[i]->AddApplication(OnOff);
	H_nodes[i]->applications[0]->node = H_nodes[i];
	H_nodes[i]->applications[0]->sim = sim;
	H_nodes[i]->AddApplication(SinkApp);
      }
}
