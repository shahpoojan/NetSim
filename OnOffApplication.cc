#include <cstddef>
#include <cstdlib>
#include"OnOffApplication.h"
#define PACKET_SIZE 8

OnOffApplication::OnOffApplication(double rate0, double meanOffTime0, double meanOnTime0):Application()
{
      rateWhenOn=rate0;
      meanOffTime=meanOffTime0;
      meanOnTime=meanOnTime0;
      node = NULL;
}

void OnOffApplication::SetPeerAddress(int peerAddr)
{
      peerAddress=peerAddr;
}

void OnOffApplication::Start()
{
	float start_time = (float)rand()/(float)RAND_MAX;
	float curr_time = start_time;
	
	if(curr_time < 100.0)
	{
		int num_packets = meanOnTime*rateWhenOn/PACKET_SIZE;
			
		for(int i=0; i<num_packets; i++)
		{
			//Create Events
			float time = curr_time + ((float)PACKET_SIZE/(float)rateWhenOn); 
			EventSet_t.schedule(time, Handle);
			
		}

		curr_time = curr_time + meanOnTime + meanOffTime;
	}
}

void OnOffApplication::Handle(Event* ev, Time_t t)
{
	
}
