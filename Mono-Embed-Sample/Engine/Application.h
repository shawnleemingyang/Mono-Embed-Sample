#ifndef APPLICATION_H
#define APPLICATION_H

namespace SLives
{
	class Application
	{
	public:
		void Startup();
		void GameLoop();
		void Shutdown();
	};
	
	extern Application application;
}

#endif
