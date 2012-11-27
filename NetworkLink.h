// Definition of NetworkInterface class
// ECE8893, Final Project, Fall 2012

#ifndef __NETWORK_LINK_H__
#define __NETWORK_LINK_H__

#include "CommonDefs.h"

class Node;
class Packet;

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
};
#endif
