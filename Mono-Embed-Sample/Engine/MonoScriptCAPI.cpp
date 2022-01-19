#include "MonoScriptCAPI.h"
#include "SampleECS.h"

#include <iostream>
namespace SLives
{

	void CPrintData()
	{
		ECS::PrintData();
	}

	void CAddData(MonoString* _data)
	{
		ECS::AddData(std::string{ mono_string_to_utf8(_data) });
	}

	void CTestPrint()
	{
		std::cout << "Hello Internal Call!\n";
	}
}
