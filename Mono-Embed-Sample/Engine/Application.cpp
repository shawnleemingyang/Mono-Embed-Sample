#include "Application.h"
#include "SampleECS.h"

#include <iostream>
#include <string>

namespace SLives
{
	void Application::Startup()
	{
		std::cout << "Application Startup...\n";

		// Test ECS
		/*ECS::AddData(std::string{ "Data0" });
		ECS::PrintData();*/

		//! Testing Mono setup
		
	}

	void Application::GameLoop()
	{
		std::cout << "Fake gameloop\n";
	}

	void Application::Shutdown()
	{
		std::cout << "Shutdown\n";
	}
}
