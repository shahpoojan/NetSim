#include "Node.h"
#include <iostream>
#include "NetworkInterface.h"
#include <iostream>
#include "Simulator.h"
#include "DropTailQueue.h"
#include "NetworkLink.h"
#include "Packet.h"
#include "Application.h"

using namespace std;


#define INFINITY 10000000

using namespace std;

Node::Node(int addr)
{
	this->address = addr;
	sim = NULL;
	distance = 20;
	solved = 0;
	path_from = NULL;
	nextHopRoutes.reserve(28);
}

int Node::getNodeCount()
{
	//	return Node::NodeCount;
}

int Node::GetSize()
{
	return neighbors.size();	
}

int Node::GetAddr()
{
	return address;
}

int Node:: getNextHopRoute(int i)
{
	return nextHopRoutes[i];
}

NetworkInterface* Node::GetInterface(int i)
{
	if(!interfaces.empty())
		return this->interfaces[i];
	else
	{
		cout << "Null Interface" << endl;
		return NULL;
	}
}


/// Charmi's code! Not my code!

void Node::djikstra(vector<Node*>nodes, int addr)
{
	list<Node*>computed_route;
	Node* dest = nodes[addr];
	//cout<<"dest="<<addr<<endl;
	computed_route.push_back(dest);
	//cout<<"prev node="<<dest->path_from->GetAddr()<<endl;
	Node* prev_node=dest->path_from;
	do
	{
		list<Node*>::const_iterator cii = path.begin();
		for(; cii!=path.end(); cii++)
		{
			if(prev_node->GetAddr()==(*cii)->GetAddr())
			{
				Node* add=(*cii);
				computed_route.push_back(add);
			//	path.pop_front();
			//	path.push_back(add);
				prev_node=add->path_from;	
		//		cout<<"prev node="<<prev_node->GetAddr()<<endl;			
				break;
			}
		}			
	}while(prev_node!=NULL);

	computed_route.pop_back();
	Node* next_node = computed_route.back();
	nextHopRoutes[addr] = next_node->GetAddr();
}

void Node::bsf(vector<Node*>nodes)
{
	//dijakstra's algorithmy
	Node* source=this;
	int added=0;
	source->distance=0;
	source->solved=1;
	path.push_back(source);
	int distance=20;
	//cout<<"source addr="<<source->GetAddr()<<endl;
	do
	{
		int solved_num=path.size();
		//cout<<"path size="<<solved_num<<endl;
		Node* add_to_path;		
		for(int k=0; k<solved_num; k++)
		{
			if(k==0)
				distance=20;
			Node* solved;
			solved=path.front();
			path.pop_front();
			path.push_back(solved);
		//	cout<<"\ncurrent solved node="<<solved->GetAddr()<<endl;
			int size=solved->neighbors.size();
		//	cout<<"neighbor size="<<size<<endl;
			for(int l=0; l<size; l++)
			{
				Node* neighbour =solved->neighbors.front();
				solved->neighbors.pop_front();
				solved->neighbors.push_back(neighbour);
			//	cout<<"distance="<<distance<<endl;
				if(neighbour->solved==1)
					continue;
			//	cout<<"neighbour addr="<<neighbour->GetAddr()<<endl;
				if(distance>solved->distance+1)
				{
					distance=solved->distance+1;
					add_to_path=neighbour;
					neighbour->path_from=solved;
					 //cout<<"current solved node="<<solved->GetAddr()<<endl;
					 //cout<<"neighbor size="<<size<<endl;
					//cout<<"\nadd to path="<<neighbour->GetAddr()<<endl;
					//cout<<"new distance="<<distance<<endl;
					added=1;
				}
			}		
		}
		if(added==1)
		{
			added=0;
			add_to_path->distance=distance;
			add_to_path->solved=1;
			path.push_back(add_to_path);
		}

	}while(path.size() != nodes.size());
}

void Node::ComputeRoutes(vector<Node*> nodes)
{

	 bsf(nodes);
	for(int i=0;i<nodes.size();i++)
	{
		if(i!=this->address)
			djikstra(nodes,i);
		else
			nextHopRoutes[i] = 0;
	}
	/*int* dist = new int(nodes.size());
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

	}*/

}

void Node::AddInterface(NetworkInterface* interface)
{
	if(interface != NULL)
		this->interfaces.push_back(interface);
	else
		cout << "ERROR!\nNull Interface" << endl;
}

void Node::AddNeighbor(int interface_a, Node* n, int interface_b)
{
	if(n != NULL)
	{
		cout << "Pushing the neighbors" << endl;
		//Node::NodeCount++;
		neighbors.push_back(n);
		nextHopRoutes.push_back(n->address);
		
		n->neighbors.push_back(this);
		n->nextHopRoutes.push_back(this->address);
	}
	else
	cout << "ERROR!\nNULL node" << endl;	
	CreateBiDirLinks(this->GetInterface(interface_a),n->GetInterface(interface_b));
        cout << address << " Neigh size = " << neighbors.size() << endl;
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
	/// Actually get the packet generated by the application the application
	// Packet *p = applications[0].generate()
	//// Look into routing table
	int index = 0;			//need to include routing table input
	interfaces[index]->queue->Enque(p);
	NetworkInterface* temp = interfaces[index];
	NetworkLink* temp_link = temp->link;
	double data_rate = temp_link->dataRate;
	Time_t transmit_time = (double)(((interfaces[index]->queue)->getLength())*PACKET_SIZE)/data_rate;
	sim->Schedule(transmit_time, &NetworkInterface::Handle, interfaces[index]);		//add transmit complete event to queue
}

void Node::Receive(int count, int source)
{
	Packet *p = new Packet(source, this->address, count);
	// Send it to the ApplicationSync
}

void Node::PacketGenerationComplete(int peer_addr, int size)
{
	cout << "Node handle called for " << address  << endl;
	this->Send(size, peer_addr);
}

/*void Node::Handle(Event* ev, Time_t t)
{
	if(ev->EventType == 0)
	{
		int size = neighbors.size();
		int dest = rand()%size;
		int count = rand()%100;

		this->Send(count, dest);
	}	
}*/

void CreateBiDirLinks(NetworkInterface* a, NetworkInterface* b)
{

	NetworkLink* link1 = new NetworkLink();		// a -> b
	a->link = link1;
	a->AddP2PLink(a->link, b);

	NetworkLink* link2 = new NetworkLink();		// b -> a
	b->link = link2;
	b->AddP2PLink(b->link, a);

}
