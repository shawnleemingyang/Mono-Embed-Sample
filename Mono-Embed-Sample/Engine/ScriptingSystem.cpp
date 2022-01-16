#include "ScriptingSystem.h"
#include "SampleECS.h"
#include "MonoScriptCAPI.h"

#include <iostream>

#include <mono/metadata/assembly.h>
#include <mono/jit/jit.h>
#include <mono/metadata/debug-helpers.h>

namespace SLives
{
	void ScriptingSystem::Startup()
	{
		//! INITIALIZING MONO
		std::cout << "[C/C++] ---Starting Scripting Engine---\n";
		// Set directory for Mono. Indicate installation path of lib and etc folders
		mono_set_dirs("Mono\\lib", "Mono\\etc");

		// Create Scripting CS Domain
		MonoDomain* domain = mono_jit_init("CSharp_Domain");

		// Load binaries as Assembly
		MonoAssembly* scriptAssembly = mono_domain_assembly_open(domain, "MonoScript.dll");

		// If main exists.... (Not for DLLs of course)
		//mono_jit_exec(domain, csAssembly, argc, argv);

		//! ADDING INTERNAL CALLS
		mono_add_internal_call("MonoScript.ScriptAPI::PrintData", &CPrintData);
		mono_add_internal_call("MonoScript.ScriptAPI::AddData", &CAddData);

		//! GET MONOMETHODS FROM C# CLASS
		// Get image(component of assemblies holding CIL code and metadata) of assembly
		MonoImage* scriptImage = mono_assembly_get_image(scriptAssembly);
		// Get class
		MonoClass* scriptClass = mono_class_from_name(scriptImage, "MonoScript", "ScriptAPI");
		// Get Method via method description
		MonoMethodDesc* testPrintMethodDesc = mono_method_desc_new("MonoScript.ScriptAPI:TestPrint()", true);
		MonoMethod* testPrintMethod = mono_method_desc_search_in_class(testPrintMethodDesc, scriptClass);
		mono_method_desc_free(testPrintMethodDesc);
		// Execute method
		std::cout << "[C/C++] INVOKING SCRIPT FROM CS\n";
		mono_runtime_invoke(testPrintMethod, NULL, NULL, NULL);

		////! CALLING C CODE FROM C# -> PrintData C++ code -> PrintData C# code -> Invoke
		//MonoMethodDesc* printDataDesc = mono_method_desc_new("MonoScript.ScriptAPI:PrintData()", true);
		//MonoMethod* printDataMethod = mono_method_desc_search_in_class(printDataDesc, scriptClass);
		//mono_method_desc_free(printDataDesc);
		//mono_runtime_invoke(printDataMethod, NULL, NULL, NULL);

		
	}

	void ScriptingSystem::Update()
	{

	}

	void ScriptingSystem::Shutdown() {}

}
