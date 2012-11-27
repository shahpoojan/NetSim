#include"Application.h"

Application::Application()
{
      node=NULL;
}

Application::AttachToNode(Node* newNode)
{
      node=newNode;
}