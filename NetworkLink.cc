#include "NetworkLink.h"
#include "Simulator.h"
#include <iostream>

using namespace std;
NetworkLink::NetworkLink() // Construct with delay and data rate
{
	
}

void NetworkLink::SetPeer(NetworkInterface* peer1, NetworkInterface* peer2)
{
	Sender = peer1;
	Receiver = peer2;
}

NetworkLink::NetworkLink(double delay0, double dataRate0) // Construct with delay and data rate
{
	delay = delay0;
	dataRate = dataRate0;
}

void NetworkLink::Send(Packet* p)
{
	sim->Schedule(delay, &NetworkInterface::Receive, Receiver, p);
	/*if (Peer1 == source)
	{
		sim->Schedule(delay, &NetworkInterface::Receive, Peer2, p);
	}
	else 
	{
		sim->Schedule(delay, &NetworkInterface::Receive, Peer1, p);
	}*/
	//add receive event to the sorted container
}
