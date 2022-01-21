#ifndef SCRIPTSYSTEM_H
#define SCRIPTSYSTEM_H

#include <mono/jit/jit.h>

namespace SLives
{
	class ScriptingSystem
	{
	public:
		void Startup();
		void Update();
		void Shutdown();

		MonoDomain* domain{nullptr};
		MonoAssembly* scriptAssembly{nullptr};
		MonoImage* scriptImage{nullptr};
		MonoClass* vectorClass{nullptr};
	};
}

#endif
