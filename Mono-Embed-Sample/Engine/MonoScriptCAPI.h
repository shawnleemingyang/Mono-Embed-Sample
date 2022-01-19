#ifndef MONOCAPI_H
#define MONOCAPI_H

//#include <mono/metadata/assembly.h>
#include <mono/jit/jit.h>

namespace SLives
{

	struct Vector3
	{
		float x, y, z;
	};

	void CPrintData();

	void CAddData(MonoString* _data);

	void CTestPrint();
}

#endif
