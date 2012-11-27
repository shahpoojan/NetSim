#include"Application.h"
#include <cstddef>
Application::Application()
{
      node=NULL;
}

void Application::AttachToNode(Node* newNode)
{
      node=newNode;
}
