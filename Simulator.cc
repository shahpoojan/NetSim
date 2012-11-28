#include <math.h>
#include <sys/time.h>
#include <iostream>
//#include <vector>
//#include <map>
//#include <set>
#include "Simulator.h"

using namespace std;

Simulator::Simulator()
{
  instance = this;
}

void Simulator::Stop()
{
  stopped = true;
}

void Simulator::Run()
{
  while (!stopped && !events.empty())
    {
      // Get the next event
      EventBase* currentEvent = *events.begin();
      // Remove from queue
      events.erase(events.begin());
      // Advance Simulation Time
      now = currentEvent->time;  // Advance simulation time to time of event
      // call the event
      currentEvent->CallHandler();
    }
}

void Simulator::StopAt(Time_t t)
{
  Simulator::Schedule(t - Simulator::Now(), 
                      &Simulator::Stop, Simulator::instance);
}

Time_t Simulator::Now()
{
  return now;
}

// Simulator static objects
EventSet_t  Simulator::events;
bool        Simulator::stopped = false;
Time_t      Simulator::now = 0;
Simulator*  Simulator::instance = 0;
