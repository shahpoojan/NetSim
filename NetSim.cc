// Main program for NetSim
// ECE8893 Final Project, Fall 2012

//#include "Simulator.h"
#include "Application.h"
#include "CommonDefs.h"
#include "DropTailQueue.h"
#include "Handler.h"
#include "NetworkInterface.h"
#include "NetworkLink.h"
#include "Node.h"
#include "OnOffApplication.h"
#include "Packet.h"
#include "PacketSyncApplication.h"
#include "Queue.h"
#include "Simulator.h"
#include <iostream>
#include <cstdlib>
#include <set>


using namespace std;

vector<Node*>nodes;
int node_count = 0;
template<class ForwardIterator>
void Print(ForwardIterator b, ForwardIterator e, bool addEndl = true)
{
	while(b!=e)
	{
		cout << (*b)->time;
		
		(*b++);
		if(addEndl) cout << endl;
	}
}



void CreateTopology(Node** H_nodes, Node** R_nodes, Node** G_nodes)
{
	for(int i=0; i<4; i++)
	{
		Node* temp = new Node(i);
		G_nodes[i] = temp;
 		for(int j=0;j<5;j++)
		{
			NetworkInterface* interface = new NetworkInterface(G_INTF_DATA_RATE,G_nodes[i]);
			G_nodes[i]->AddInterface(interface);
			G_nodes[i]->node_type = G_NODE;
		}
		nodes.push_back(G_nodes[i]);
	}

	for(int i=0; i< 8; i++)
	{
		Node* temp = new Node(i + 4);
		R_nodes[i] = temp;
                for(int j=0;j<3;j++)
                {
			NetworkInterface* interface = new NetworkInterface(R_INTF_DATA_RATE, R_nodes[i]);
			R_nodes[i]->AddInterface(interface);
			R_nodes[i]->node_type = R_NODE;
                }
		nodes.push_back(R_nodes[i]);

	}

	for(int i=0; i<16; i++)
        {
		Node* temp = new Node(i + 12);
		H_nodes[i] = temp;
		NetworkInterface* interface = new NetworkInterface(H_INTF_DATA_RATE, H_nodes[i]);
		H_nodes[i]->AddInterface(interface);
		H_nodes[i]->node_type = H_NODE;
		nodes.push_back(H_nodes[i]);

        }
        
        
        /************************ G - G LINKS ****************************/
	
	G_nodes[0]->AddNeighbor(0,G_nodes[1],0);			//arguments: self interface, other node, other node 's interface
	//CreateBiDirLinks(G_nodes[0]->GetInterface(0),G_nodes[1]->GetInterface(0));

	G_nodes[0]->AddNeighbor(1,G_nodes[2],0);
	//CreateBiDirLinks(G_nodes[0]->GetInterface(1),G_nodes[2]->GetInterface(0));
	
	G_nodes[0]->AddNeighbor(2,G_nodes[3],0);
	//CreateBiDirLinks(G_nodes[0]->GetInterface(2),G_nodes[3]->GetInterface(0));
	
	G_nodes[1]->AddNeighbor(1,G_nodes[2],1);
	//CreateBiDirLinks(G_nodes[1]->GetInterface(1),G_nodes[2]->GetInterface(1));
	
	G_nodes[1]->AddNeighbor(2,G_nodes[3],1);
	//CreateBiDirLinks(G_nodes[1]->GetInterface(2),G_nodes[3]->GetInterface(1));
	
	G_nodes[2]->AddNeighbor(2,G_nodes[3],2);
	//CreateBiDirLinks(G_nodes[2]->GetInterface(2),G_nodes[3]->GetInterface(2));
	
	
	/************************ G - R LINKS ****************************/
	
	G_nodes[0]->AddNeighbor(3,R_nodes[0],0);
	//CreateBiDirLinks(G_nodes[0]->GetInterface(3),R_nodes[0]->GetInterface(0));
	
	G_nodes[0]->AddNeighbor(4,R_nodes[1],0);
	//CreateBiDirLinks(G_nodes[0]->GetInterface(4),R_nodes[1]->GetInterface(0));
	
	G_nodes[1]->AddNeighbor(3,R_nodes[2],0);
	//CreateBiDirLinks(G_nodes[1]->GetInterface(3),R_nodes[2]->GetInterface(0));
	
	G_nodes[1]->AddNeighbor(4,R_nodes[3],0);
	//CreateBiDirLinks(G_nodes[1]->GetInterface(4),R_nodes[3]->GetInterface(0));
	
	G_nodes[2]->AddNeighbor(3,R_nodes[4],0);
	//CreateBiDirLinks(G_nodes[2]->GetInterface(3),R_nodes[4]->GetInterface(0));
	
	G_nodes[2]->AddNeighbor(4,R_nodes[5],0);
	//CreateBiDirLinks(G_nodes[2]->GetInterface(4),R_nodes[5]->GetInterface(0));
	
	G_nodes[3]->AddNeighbor(3,R_nodes[6],0);
	//CreateBiDirLinks(G_nodes[3]->GetInterface(3),R_nodes[6]->GetInterface(0));
	
	G_nodes[3]->AddNeighbor(4,R_nodes[7],0);
	//CreateBiDirLinks(G_nodes[3]->GetInterface(4),R_nodes[7]->GetInterface(0));
	
	/************************ R - H LINKS ****************************/
	
	R_nodes[0]->AddNeighbor(1,H_nodes[0],0);
	//CreateBiDirLinks(R_nodes[0]->GetInterface(1),H_nodes[0]->GetInterface(0));
	
	R_nodes[0]->AddNeighbor(2,H_nodes[1],0);
	//CreateBiDirLinks(R_nodes[0]->GetInterface(2),H_nodes[1]->GetInterface(0));
	
	R_nodes[1]->AddNeighbor(1,H_nodes[2],0);
	//CreateBiDirLinks(R_nodes[1]->GetInterface(1),H_nodes[2]->GetInterface(0));
	
	R_nodes[1]->AddNeighbor(2,H_nodes[3],0);
	//CreateBiDirLinks(R_nodes[1]->GetInterface(2),H_nodes[3]->GetInterface(0));
	
	R_nodes[2]->AddNeighbor(1,H_nodes[4],0);
	//CreateBiDirLinks(R_nodes[2]->GetInterface(1),H_nodes[4]->GetInterface(0));
	
	R_nodes[2]->AddNeighbor(2,H_nodes[5],0);
	//CreateBiDirLinks(R_nodes[2]->GetInterface(2),H_nodes[5]->GetInterface(0));
	
	R_nodes[3]->AddNeighbor(1,H_nodes[6],0);
	//CreateBiDirLinks(R_nodes[3]->GetInterface(1),H_nodes[6]->GetInterface(0));
	
	R_nodes[3]->AddNeighbor(2,H_nodes[7],0);
	//CreateBiDirLinks(R_nodes[3]->GetInterface(2),H_nodes[7]->GetInterface(0));
	
	R_nodes[4]->AddNeighbor(1,H_nodes[8],0);
	//CreateBiDirLinks(R_nodes[4]->GetInterface(1),H_nodes[8]->GetInterface(0));
	
	R_nodes[4]->AddNeighbor(2,H_nodes[9],0);
	//CreateBiDirLinks(R_nodes[4]->GetInterface(2),H_nodes[9]->GetInterface(0));
	
	R_nodes[5]->AddNeighbor(1,H_nodes[10],0);
	//CreateBiDirLinks(R_nodes[5]->GetInterface(1),H_nodes[10]->GetInterface(0));
	
	R_nodes[5]->AddNeighbor(2,H_nodes[11],0);
	//CreateBiDirLinks(R_nodes[5]->GetInterface(2),H_nodes[11]->GetInterface(0));
	
	R_nodes[6]->AddNeighbor(1,H_nodes[12],0);
	//CreateBiDirLinks(R_nodes[6]->GetInterface(1),H_nodes[12]->GetInterface(0));
	
	R_nodes[6]->AddNeighbor(2,H_nodes[13],0);
	//CreateBiDirLinks(R_nodes[6]->GetInterface(2),H_nodes[13]->GetInterface(0));
	
	R_nodes[7]->AddNeighbor(1,H_nodes[14],0);
	//CreateBiDirLinks(R_nodes[7]->GetInterface(1),H_nodes[14]->GetInterface(0));
	
	R_nodes[7]->AddNeighbor(2,H_nodes[15],0);
	//CreateBiDirLinks(R_nodes[7]->GetInterface(2),H_nodes[15]->GetInterface(0));

}

int main()
{
	//running the simulation point 2 (Added by Charmi)
	double r=0.5; //default value
	double rate0=r*10000000; //rate is r times 10Mbps
	double meanOffTime0=(float)rand()/(float)RAND_MAX; //time in seconds range 0 to 1 sec
	double meanOnTime0=(float)rand()/(float)RAND_MAX;

	Simulator* sim = new Simulator();
	sim->StopAt(100);

	Node* H_nodes[16];
	Node* R_nodes[8];
	Node* G_nodes[4];


	CreateTopology(H_nodes, R_nodes, G_nodes);
	cout << "*********************************************************" << endl;
	for(int i = 0; i < 4; i++)
		cout << "G neighbor size: " << G_nodes[i]->GetSize() << endl;
	for(int i = 0;i < 8; i++)
		cout << "R neighbor size: " << R_nodes[i]->GetSize() << endl;
	for(int i = 0;i < 8; i++)
		cout << "H neighbor size: " << H_nodes[i]->GetSize() << endl;

	for(int i=0; i<16; i++)
	{
		double meanOffTime0=(float)rand()/(float)RAND_MAX; //time in seconds range 0 to 1 sec
		double meanOnTime0=(float)rand()/(float)RAND_MAX;
		OnOffApplication *OnOff = new OnOffApplication(rate0, meanOffTime0, meanOnTime0);

		
		H_nodes[i]->AddApplication(OnOff);
		H_nodes[i]->applications[0]->AttachToNode(H_nodes[i]);
		((OnOffApplication*)H_nodes[i]->applications[0])->sim = sim;


		double start_time = (float)rand()/(float)RAND_MAX;
		sim->Schedule(start_time, &OnOffApplication::Handle, (OnOffApplication*)(H_nodes[i]->applications[0]), H_nodes[i],0);
		
		PacketSyncApplication *SyncApp = new PacketSyncApplication();
		H_nodes[i]->AddApplication(SyncApp);
	}
	

//	Print(sim->events.begin(), sim->events.end());


	cout << "Computing routes" << endl;
	for(int i=0; i<nodes.size(); i++)
	{
		nodes[i]->ComputeRoutes(nodes);
		cout << "computed for " << i << endl;
	}
	/*for(int i=0; i<nodes[0]->path.size(); i++)
	{
	Node* newnode=nodes[0]->path.front();
	nodes[0]->path.pop_front();
	nodes[0]->path.push_back(newnode);
	}*/

	/*cout << "Routes computes" << endl;
	for(int i=0;i<28; i++)
	{
		cout << i << " = " << nodes[1]->getNextHopRoute(i) << endl;
	}*/
	//Simulator::Run();
}
