// Definition of NetworkInterface class
// ECE8893, Final Project, Fall 2012

#ifndef __NETWORK_LINK_H__
#define __NETWORK_LINK_H__

#include "CommonDefs.h"
#include "NetworkInterface.h"

#define G_G_DELAY 		0.01			// in seconds
#define OTHER_DELAY		0.001			// in seconds

class Node;
class Packet;
class Simulator;

class NetworkLink 
{
	public:
	NetworkLink(); // Construtor
	NetworkLink(double delay0, double dataRate0); // Construct with delay and data rate
	void SetPeer(NetworkInterface* , NetworkInterface* );
	void Send(Packet*, NetworkInterface*);   // Send a packet to peer
	
	public:
	Simulator* sim;
	NetworkInterface* Peer1;
	NetworkInterface* Peer2;
	double delay; // Speed of light delay on this link
	double dataRate; // Bits per second on this link
};
#endif
