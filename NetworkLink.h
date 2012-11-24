// Definition of NetworkInterface class
// ECE8893, Final Project, Fall 2012

#ifndef __NETWORK_INTERFACE_H__
#define __NETWORK_INTERFACE_H__

#include "CommonDefs.h"

class Node;

class NetworkLink 
{
	public:
	NetworkLink(); // Construtor
	NetworkLink(double delay0, double dataRate0); // Construct with delay and data rate
	void SetPeer(Node*);
	void Send(Packet*);   // Send a packet to peer
	
	public:
	Node* peerNode;
	double delay; // Speed of light delay on this link
	double dataRate; // BIts per second on this link
}
#endif
