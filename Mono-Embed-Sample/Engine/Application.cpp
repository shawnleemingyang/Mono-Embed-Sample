#include "Application.h"
#include "SampleECS.h"

#include <iostream>
#include <string>
#include <memory>

namespace SLives
{
	void Application::Startup()
	{
		std::cout << "[C/C++] Running Engine's Startup()\n";
		ECS::AddData("Data 0: Added from Engine.");
		mScriptingSystem = std::make_shared<ScriptingSystem>();
		mScriptingSystem->Startup();
		
		

	}

	void Application::GameLoop()
	{
		std::cout << "\n[C/C++] Running Engine's GameLoop()\n";
	}

	void Application::Shutdown()
	{
		std::cout << "\n[C/C++] Running Engine's Shutdown()\n";
	}
}
