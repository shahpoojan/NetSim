#include "NetworkLink.h"

#define LINK_TEST 1
void NetworkLink::NetworkLink(double delay0, double dataRate0) // Construct with delay and data rate
{
	delay = delay0;
	dataRate = dataRate0;
}



void NetworkLink::SetPeer(Node* peer)
{
	peerNode = peer;
}

void NetworkLink::Send(Packet*)
{
	
	//add receive event to the sorted container
#ifdef LINK_TEST
	
#endif
}