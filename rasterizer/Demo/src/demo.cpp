#include "Application.h"

#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")

using namespace rs;

int main(int argc, char *argv[])
{
  Application* app = Application::getInstance();
  app->initialize(800, 600, "Demo");
  app->setPos(200, 200);
  app->run();
  return 0;
}