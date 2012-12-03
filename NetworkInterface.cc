#include "NetworkInterface.h"
#include "NetworkLink.h"
#include "DropTailQueue.h"
#include <cstddef>
#include <iostream>
#include "Node.h"
#include "Simulator.h"
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
NetworkInterface::NetworkInterface(double i_data_rate, Node* assoc_node)
{
	queue = new DropTailQueue(1000);
	link = NULL;
	node = assoc_node;
	busy = false;
	interface_data_rate = i_data_rate;		//determined by AddNeighbor() based on node type, but is more flexible than static assignment
}


//AddP2PLink: Find the minimum NIC data rate and assign that to the link speed 
void NetworkInterface::AddP2PLink(NetworkLink* new_link, NetworkInterface* end_interface)
{

	if(this->interface_data_rate <= end_interface->interface_data_rate)
		new_link->dataRate = this->interface_data_rate;
	else
		new_link->dataRate = end_interface->interface_data_rate;

	if (this->node->node_type == G_NODE && end_interface->node->node_type == G_NODE)
		new_link->delay = G_G_DELAY;
	else
		new_link->delay = OTHER_DELAY;
}


void NetworkInterface::Send(Packet* pkt) // Send specified packet to p2p peerorkLink::Send(Packet*)
{
	if(pkt != NULL)
	{
		
		//add transmit event to the event list
	}
}

void NetworkInterface::Send() //Send specified packet to p2p off the
{
	Packet* p = queue->Deque();
	cout << p->source << " sent to " << p->destination << " at " << Simulator::Now() << endl;
	link->Send(p);
}

void NetworkInterface::Receive(Packet* p)
{
	node->Receive(p);
}
 
void NetworkInterface::Handle() // Handle event
{
	cout << "Interface handle called" << endl;	
}
