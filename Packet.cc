#include "Packet.h"

Packet::Packet()
{
	this->source = -1;
	this->destination = -1;
	this->count = -1;
}

Packet::Packet(int src, int dst, int count)
{
	this->source = src;
	this->destination = dst;
	this->count = count;
}

Packet::timetolive = 64;
