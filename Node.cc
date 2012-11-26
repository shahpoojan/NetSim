#include "Node.h"
#include <iostream>
#include "NetworkInterface.h"
//#include "Packet.cc"

#define INFINITY 10000000

using namespace std;

Node::Node(int addr)
{
	this->address = addr;
}

int Node::getNodeCount()
{
//	return Node::NodeCount;
}

void Node::ComputeRoutes(vector<Node*> nodes)
{
	int* dist = new int(nodes.size());
	int* prev = new int(nodes.size());

	for(int i=0; i<nodes.size(); i++)
	{
		dist[i] = INFINITY;
		prev[i] = -1;
	}

	for(int i=0; i<neighbors.size(); i++)
	{
		dist[neighbors[i]->address] = 1;
		dist[neighbors[i]->address] = this->address;
	}

	while(!nodes.empty())
	{	
		int min = INFINITY;
		int index = -1;
		for(int i=0; i<nodes.size(); i++)
		{
			if(min < dist[i])
			{
				index = i;
				min = dist[i];
			}
			
		}

		for(int i=0; i<nodes[index]->neighbors.size(); i++)
		{
			if(dist[nodes[index]->neighbors[i]->address] > (min + 1))
			{
				dist[nodes[index]->neighbors[i]->address] = min + 1;
				prev[nodes[index]->neighbors[i]->address] = nodes[index]->address;
			}
		}

		/// Do the Swapping
		//int temp = dist[index];
		//dist[index];

	}
		
}

void Node::AddInterface(NetworkInterface* interface)
{
	if(interface != NULL)
		this->interfaces.push_back(interface);
	else
		cout << "ERROR!\nNull Interface" << endl;
}

void Node::AddNeighbor(Node* n)
{
	if(n != NULL)
	{
		//Node::NodeCount++;
		neighbors.push_back(n);
		nextHopRoutes.push_back(n->address);
	}
	else
		cout << "ERROR!\nNULL node" << endl;	
}

void Node::AddApplication(Application* app)
{
	if(app != NULL)
	{
		applications.push_back(app);
	}
	else
		cout << "ERROR!\nNull Application" << endl;
	
}

void Node::Send(int count, int dest)
{
	Packet *p = new Packet(this->address, dest, count);
	//// Look into routing table
	int index = 0;
	interfaces[index]->Send(p);
}
