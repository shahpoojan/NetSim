#include "NetworkInterface.h"
#include "Queue.h"

long unsigned int num_dropped_pkts = 0;
//Default Constructor for NIC
NetworkInterface::NetworkInterface()
{
	queue = NULL;
	link = NULL;
	node = NULL;
	busy = false;
	interface_data_rate = 0;		//cannot send data
}

//Constructor for Network Interface. The AddNeighbor function will pass the required NIC data rate as argument.
NetworkInterface::NetworkInterface(double i_data_rate)
{
	queue = NULL;
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


void Send(Packet* pkt) // Send specified packet to p2p peer
{
	if(pkt != NULL)
	{
		if(Enque(pkt) == false)		//if queue is full, the packet is dropped, hence increment count
			num_dropped_pkts++;
		
		//add transmit event to the event list
	}
}
 
void Handle(Event*, Time_t) // Handle event
{
	
}