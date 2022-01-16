#include "MonoScriptCAPI.h"
#include "SampleECS.h"
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
}
