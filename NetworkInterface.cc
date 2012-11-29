#include "NetworkInterface.h"
#include "NetworkLink.h"
#include "DropTailQueue.h"
#include <cstddef>
#include <iostream>

using namespace std;
long unsigned int num_dropped_pkts = 0;
//Default Constructor for NIC
NetworkInterface::NetworkInterface()
{
	queue = new DropTailQueue(1000);
	link = NULL;
	node = NULL;
	busy = false;
	interface_data_rate = 0;		//cannot send data
}

//Constructor for Network Interface. The AddNeighbor function will pass the required NIC data rate as argument.
NetworkInterface::NetworkInterface(double i_data_rate)
{
	queue = new DropTailQueue(1000);
	link = NULL;
	node = NULL;
	busy = false;
	interface_data_rate = i_data_rate;		//determined by AddNeighbor() based on node type, but is more flexible than static assignment
}


//AddP2PLink: Find the minimum NIC data rate and assign that to the link speed 
void NetworkInterface::AddP2PLink(NetworkLink* new_link, NetworkInterface* end_interface, double link_delay)
{
	if(interface_data_rate <= end_interface->interface_data_rate)
		new_link->dataRate = interface_data_rate;
	else
		new_link->dataRate = end_interface->interface_data_rate;
	
	new_link->delay = link_delay;
}


void NetworkInterface::Send(Packet* pkt) // Send specified packet to p2p peerorkLink::Send(Packet*)
{
	if(pkt != NULL)
	{
		//add transmit event to the event list
	}
}
 
void NetworkInterface::Handle() // Handle event
{
	cout << "Interface handle called" << endl;	
}
