#include <cstddef>
#include <cstdlib>
#include"OnOffApplication.h"
#include "Simulator.h"
#include "Node.h"
#include <iostream>

//#include "Application.cc"
#define PACKET_SIZE 18000

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

void OnOffApplication::Start()
{
	int num_packets = meanOnTime*rateWhenOn/(PACKET_SIZE*8);
	Time_t curr_time = Simulator::now;

	for(int i=0; i<num_packets; i++)
	{
		//Create Events
		//double time = curr_time + ((float)PACKET_SIZE/(float)rateWhenOn); 
		//sim->Schedule(curr_time + ((float)PACKET_SIZE/(float)rateWhenOn), &OnOffApplication::Handle, this);
		curr_time = curr_time + PACKET_SIZE/rateWhenOn;
		sim->Schedule(curr_time, &Node::Handle, node, peerAddress, PACKET_SIZE);

	}

}

void OnOffApplication::Stop()
{
        cout << "Called stop for " << node->GetAddr() << " "  << Simulator::now << endl;

	 sim->Schedule(Simulator::now+meanOffTime, &OnOffApplication::Handle, (OnOffApplication*)(node->applications[0]), node, 0);
}

void OnOffApplication::Handle(Node* n, int type)
{
	if(type == 0)
	{
        	cout << "Called start for " << n->GetAddr() << " "  << Simulator::now << endl;
		sim->Schedule(Simulator::now+meanOnTime, &OnOffApplication::Handle, (OnOffApplication*)(node->applications[0]), node, 1);
		n->applications[0]->Start();
	}

	if(type == 1)
	{
		this->Stop();
	}
}
