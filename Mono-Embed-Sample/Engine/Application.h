#ifndef APPLICATION_H
#define APPLICATION_H

#include "ScriptingSystem.h"

#include <memory>

namespace SLives
{
	class Application
	{
	public:
		void Startup();
		void GameLoop();
		void Shutdown();

	private:
		std::shared_ptr<ScriptingSystem> mScriptingSystem{ nullptr };
	};
	
	extern Application application;
}

#endif
