// Definition of DropTail Queue class
// ECE8893, Final Project, Fall 2012

#include "Queue.h"

#ifndef __DROP_TAIL_QUEUE_H__
#define __DROP_TAIL_QUEUE_H__

#include <list>

using namespace std;

class DropTailQueue : public Queue
{
public:
  //DropTailQueue();
  DropTailQueue(int maxLth);    // Create with specified maximum length (packets)
  //virtual bool Enque(Packet*);  // Add a packet to the queue, true if successful
  //virtual Packet* Deque();      // Remove a packet from the queue
  bool Enque(Packet*);  // Add a packet to the queue, true if successful
  Packet* Deque();      // Remove a packet from the queue
private:
  list<Packet*> PacketQueue;
  int max_length;
  int length;

  // define the actual queue here (deque or vector?)
};

#endif



