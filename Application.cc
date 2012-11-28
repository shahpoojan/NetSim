#include"Application.h"
#include <cstddef>

Application::Application()
{
      node=NULL;
      sim = NULL;
}

void Application::AttachToNode(Node* newNode)
{
      node=newNode;
}
