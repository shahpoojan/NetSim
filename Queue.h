// Definition of Queue abstract base class
// ECE8893, Final Project, Fall 2012

#ifndef __QUEUE_H__
#define __QUEUE_H__

class Packet;

class Queue 
{
  public:
  Queue();                          // Default Constructor
  virtual bool Enque(Packet*) = 0;  // Add a packet to the queue, true if successful
  virtual Packet* Deque() = 0;      // Remove a packet from the queue
};

#endif

