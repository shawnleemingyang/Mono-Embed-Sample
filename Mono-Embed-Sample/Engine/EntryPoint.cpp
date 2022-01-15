#include <iostream>
#include "Application.h"

int main()
{
	SLives::application.Startup();
	SLives::application.GameLoop();

	return 0;
}
