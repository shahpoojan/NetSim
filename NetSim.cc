// Main program for NetSim
// ECE8893 Final Project, Fall 2012

//#include "Simulator.h"
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
#include <set>

#define G_DELAY 0.01

using namespace std;

template<class ForwardIterator>
void Print(ForwardIterator b, ForwardIterator e, bool addEndl = true)
{
	while(b!=e)
	{
		cout << (*b)->time;
		
		(*b++);
		if(addEndl) cout << endl;
	}
}

void CreateTopology(Node* H_nodes, Node* R_nodes, Node* G_nodes)
{
	for(int i=0; i<4; i++)
	{
		G_nodes[i] = new Node(i);
		for(int j=0;j<5;j++)
		{
			NetworkInterface* interface = new NetworkInterface(10000000)
			G_nodes[i]->AddInterface(interface)
		}
	}

	for(int i=0; i< 8; i++)
	{
		R_nodes[i] = new Node(i+4);
                for(int j=0;j<3;j++)
                {
                        NetworkInterface* interface = new NetworkInterface(1000000)
                        R_nodes[i]->AddInterface(interface)
                }

	}

	for(int i=0; i<16; i++)
        {
                H_nodes[i] = new Node(i+12);
                NetworkInterface* interface = new NetworkInterface(10000000)
                H_nodes[i]->AddInterface(interface)

        }
	
}

int main()
{
	//running the simulation point 2 (Added by Charmi)
	double r=0.5; //default value
	double rate0=r*10000000; //rate is r times 10Mbps
	double meanOffTime0=(float)rand()/(float)RAND_MAX; //time in seconds range 0 to 1 sec
	double meanOnTime0=(float)rand()/(float)RAND_MAX;

	Simulator* sim = new Simulator();
	sim->StopAt(100);

	Node* H_nodes[16];
	Node* R_nodes[8];
	Node* G_nodes[4];

	CreateTopology(H_nodes, R_nodes, G_nodes);

	//OnOffApplication OnOff(rate0, meanOffTime0, meanOnTime0);
	for(int i=0; i<16; i++)
	{
		//H_nodes[i] = new Node(i);
		double meanOffTime0=(float)rand()/(float)RAND_MAX; //time in seconds range 0 to 1 sec
		double meanOnTime0=(float)rand()/(float)RAND_MAX;
		OnOffApplication *OnOff = new OnOffApplication(rate0, meanOffTime0, meanOnTime0);

		PacketSyncApplication *SinkApp = new PacketSyncApplication();
		H_nodes[i]->AddApplication(OnOff);
		H_nodes[i]->applications[0]->AttachToNode(H_nodes[i]);
		((OnOffApplication*)H_nodes[i]->applications[0])->sim = sim;
		H_nodes[i]->AddApplication(SinkApp);

		double start_time = (float)rand()/(float)RAND_MAX;
		//Event2<OnOffApplication, OnOffApplication*, Node*, int> event = new Event2(start_time, &OnOffApplication::Handle(Node*, int),  H_nodes[i]->applications[0], H_nodes[i], 0)

		sim->Schedule(start_time, &OnOffApplication::Handle, (OnOffApplication*)(H_nodes[i]->applications[0]), H_nodes[i], 0);
	}

	/*int size = sim->events.size();
	set::iterator i = events.begin();
	for(i!=events.end())
	{
		cout << i->first->time << endl;
		i++;
	}*/
	Print(sim->events.begin(), sim->events.end());
	Simulator::Run();
}
