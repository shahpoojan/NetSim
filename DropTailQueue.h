// Definition of DropTail Queue class
// ECE8893, Final Project, Fall 2012

#ifndef __DROP_TAIL_QUEUE_H__
#define __DROP_TAIL_QUEUE_H__

#include "Queue.h"

class DropTailQueue : public Queue
{
public:
  DropTailQueue(int maxLth);    // Create with specified maximum length (packets)
  virtual bool Enque(Packet*);  // Add a packet to the queue, true if successful
  virtual Packet* Deque();      // Remove a packet from the queue
private:
  // define the actual queue here (deque or vector?)
};

#endif



