#include <cstddef>
#include <cstdlib>
#include"OnOffApplication.h"
#include "Simulator.h"
//#include "Application.cc"
#define PACKET_SIZE 8

//typedef std::multiset <EventBase*, event_less> EventSet_t;

OnOffApplication::OnOffApplication(double rate0, double meanOffTime0, double meanOnTime0):Application()
{
      rateWhenOn=rate0;
      meanOffTime=meanOffTime0;
      meanOnTime=meanOnTime0;
      node = NULL;
      //sim = NULL;
}

void OnOffApplication::SetPeerAddress(int peerAddr)
{
      peerAddress=peerAddr;
}

void OnOffApplication::Start()
{
	float start_time = (float)rand()/(float)RAND_MAX;
	double curr_time = start_time;
	
	if(curr_time < 100.0)
	{
		int num_packets = meanOnTime*rateWhenOn/PACKET_SIZE;
			
		for(int i=0; i<num_packets; i++)
		{
			//Create Events
			double time = curr_time + ((float)PACKET_SIZE/(float)rateWhenOn); 
			sim->Schedule(curr_time + ((float)PACKET_SIZE/(float)rateWhenOn), &OnOffApplication::Handle, this);
			
		}

		curr_time = curr_time + meanOnTime + meanOffTime;
	}
}

void OnOffApplication::Stop()
{

}

void OnOffApplication::Handle()
{
	
}
