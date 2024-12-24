#include <iostream>

#include "Application.h"
#include "Globals.h"
#include <bitset>

int main()
{
	//std::cout << "Hello Maze\n.";
	g_application = std::make_unique<Application>();
	g_application->run();
	return 0;
}
