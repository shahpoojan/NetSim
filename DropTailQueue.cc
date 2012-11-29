#include "DropTailQueue.h"
#include <cstddef>

DropTailQueue::DropTailQueue(int max_length):Queue()
{
	//PacketQueue = new list<Packet>;
	this->max_length = max_length;
	this->length = 0;
}

bool DropTailQueue::Enque(Packet* pkt)
{
	if((pkt != NULL) && (length != max_length))
	{
		PacketQueue.push_back(pkt);
		length++;
		return true;
	}

	return false;
}

Packet* DropTailQueue::Deque()
{
	Packet* pkt;
	if(!PacketQueue.empty())
	{
		pkt = PacketQueue.front();
		PacketQueue.pop_front();
		length--;
		return pkt;
	}

	return NULL;
}

int DropTailQueue::getLength()
{
	return length;
}
