#include "NetworkLink.h"
#include "Simulator.h"

NetworkLink::NetworkLink() // Construct with delay and data rate
{
	
}

void NetworkLink::SetPeer(NetworkInterface* peer1, NetworkInterface* peer2)
{
	Peer1 = peer1;
	Peer2 = peer2;
}

NetworkLink::NetworkLink(double delay0, double dataRate0) // Construct with delay and data rate
{
	delay = delay0;
	dataRate = dataRate0;
}

void NetworkLink::Send(Packet* p, NetworkInterface* source)
{
	if (Peer1 == source)
	{
		sim->Schedule(delay, &NetworkInterface::Receive, Peer2, p);
	}
	else 
	{
		sim->Schedule(delay, &NetworkInterface::Receive, Peer1, p);
	}
	//add receive event to the sorted container
}
