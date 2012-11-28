# Makefile for NetSim
# ECE8893 Final Project, Fall 2012

OBJECTS = NetSim.o OnOffApplication.o PacketSyncApplication.o DropTailQueue.o Packet.o NetworkLink.o NetworkInterface.o Node.o Simulator.o Application.o


NetSim:	$(OBJECTS)
	g++ -o NetSim $(OBJECTS)

.cpp.o:
	$(CC) $(CXX) $< -o $@

clean:
	rm -f $(OBJECTS) NetSim


