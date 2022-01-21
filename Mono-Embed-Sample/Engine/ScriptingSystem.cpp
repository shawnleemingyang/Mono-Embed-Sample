#include "ScriptingSystem.h"
#include "SampleECS.h"
#include "MonoScriptCAPI.h"
#include "Application.h"

#include <iostream>

#include <mono/metadata/assembly.h>
#include <mono/jit/jit.h>
#include <mono/metadata/debug-helpers.h>
#include <iostream>


namespace SLives
{

	

	MonoObject* CReturnVec3()
	{
		MonoAssembly* scriptAPIAssembly = mono_domain_assembly_open(application.mScriptingSystem->domain, "ScriptAPI.dll");
		MonoImage* scriptAPIImage = mono_assembly_get_image(scriptAPIAssembly);
		MonoClass* vectorClass = mono_class_from_name(scriptAPIImage, "ScriptAPI", "Vector3");
		MonoObject* vectorObj = mono_object_new(application.mScriptingSystem->domain, vectorClass);
		//todo Init object...
		mono_runtime_object_init(vectorObj);
		float x{ 1.f }, y{ 2.f }, z{ 3.f };
		MonoClassField* fieldX = mono_class_get_field_from_name(vectorClass, "xData");
		MonoClassField* fieldY = mono_class_get_field_from_name(vectorClass, "yData");
		MonoClassField* fieldZ = mono_class_get_field_from_name(vectorClass, "zData");
		mono_field_set_value(vectorObj, fieldX, &x);
		mono_field_set_value(vectorObj, fieldY, &y);
		mono_field_set_value(vectorObj, fieldZ, &z);


		mono_image_close(scriptAPIImage);
		mono_assembly_close(scriptAPIAssembly);
		return vectorObj;

	}

	void ScriptingSystem::Startup()
	{
		//! INITIALIZING MONO
		std::cout << "[C/C++] ---Starting Scripting Engine---\n";
		// Set directory for Mono. Indicate installation path of lib and etc folders
		mono_set_dirs("Mono\\lib", "Mono\\etc");

		// Create Scripting CS Domain
		domain = mono_jit_init("CSharp_Domain");

		// Load binaries as Assembly
		scriptAssembly = mono_domain_assembly_open(domain, "MonoScript.dll");
		//MonoAssembly* scriptAPIAssembly = mono_domain_assembly_open(domain, "ScriptAPI.dll");
		scriptImage = mono_assembly_get_image(scriptAssembly);
		// If main exists.... (Not for DLLs of course)
		//mono_jit_exec(domain, csAssembly, argc, argv);

		//! ADDING INTERNAL CALLS
		//mono_add_internal_call("MonoScript.ScriptAPI::PrintData", &CPrintData);
		//mono_add_internal_call("MonoScript.ScriptAPI::AddData", &CAddData);
		mono_add_internal_call("ScriptAPI.ScriptAPIClass::TestPrint", (const void*)&CTestPrint);
		mono_add_internal_call("ScriptAPI.ScriptAPIClass::ReturnVec3", (const void*)&CReturnVec3);


		//! GET MONOMETHODS FROM C# CLASS
		// Get image(component of assemblies holding CIL code and metadata) of assembly
		
		// Get class
		MonoClass* mockScriptClass = mono_class_from_name(scriptImage, "MonoScript", "MockScript");
		// Create object
		MonoObject* mockScriptObject = mono_object_new(domain, mockScriptClass);
		// Get Method via method description
		MonoMethodDesc* onAwakeDesc = mono_method_desc_new("MonoScript.MockScript:OnAwake()", true);
		MonoMethod* onAwakeMethod = mono_method_desc_search_in_class(onAwakeDesc, mockScriptClass);
		mono_method_desc_free(onAwakeDesc);

		MonoMethodDesc* onRetVec3Desc = mono_method_desc_new("MonoScript.MockScript:RetVec3()", true);
		MonoMethod* onRetVec3 = mono_method_desc_search_in_class(onRetVec3Desc, mockScriptClass);
		mono_method_desc_free(onRetVec3Desc);

		// Execute method
		std::cout << "[C/C++] INVOKING SCRIPT FROM CS\n";
		if (onAwakeMethod)
			mono_runtime_invoke(onAwakeMethod, mockScriptObject, NULL, NULL);
		else
			std::cout << "Cannot find method\n";

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
