#include <cstddef>
#include <cstdlib>
#include"OnOffApplication.h"
#include "Simulator.h"
#include "Node.h"
#include <iostream>

//#include "Application.cc"


//typedef std::multiset <EventBase*, event_less> EventSet_t;
using namespace std;

OnOffApplication::OnOffApplication(double rate0, double meanOffTime0, double meanOnTime0):Application()
{
	rateWhenOn=rate0;
	meanOffTime=meanOffTime0;
	meanOnTime=meanOnTime0;
	node = NULL;
	//sim = NULL;
}

void OnOffApplication::SetPeerAddress(int peerAddr)
{
	peerAddress=peerAddr;
}


/*************************************Event Handlers*******************************************/

void OnOffApplication::Handle(Node* node , int event_type)
{
	if(event_type == 0)
		Start(node);
	else if(event_type == 1)
		Stop(node);
}


void OnOffApplication::Start(Node* node)
{
	cout << "Called start for " << node->GetAddr() << " "  << Simulator::now << endl;
	sim->Schedule(Simulator::now+meanOnTime, &OnOffApplication::Handle, (OnOffApplication*)(node->applications[0]), node,1);
	
	int num_packets = meanOnTime*rateWhenOn/(PACKET_SIZE*8);
	Time_t curr_time = 0;

	for(int i=0; i<num_packets; i++)
	{
		//Create Events
		curr_time = curr_time + PACKET_SIZE/rateWhenOn;
		peerAddress = rand()%28;
		while(peerAddress == node->GetAddr())
			peerAddress = rand()%28;

		sim->Schedule(curr_time, &Node::PacketGenerationComplete, node, node->GetAddr(), peerAddress, PACKET_SIZE);

	}
}

void OnOffApplication::Stop(Node* node)
{
        cout << "Called stop for " << node->GetAddr() << " "  << Simulator::now << endl;
	sim->Schedule(Simulator::now+meanOffTime, &OnOffApplication::Handle, (OnOffApplication*)(node->applications[0]), node,0);
}
