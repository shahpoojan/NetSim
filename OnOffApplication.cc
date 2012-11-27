#include"OnOffApplication.h"

OnOffApplication::OnOffApplication(double rate0, double meanOffTime0, double meanOnTime0):Application()
{
      rateWhenOn=rate0;
      meanOffTime=meanOffTime0;
      meanOnTime=meanOnTime0;
}

void OnOffApplication::SetPeerAddress(int peerAddr)
{
      peerAddress=peerAddr;
}
