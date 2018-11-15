#pragma once

#include "Core.h"

namespace ZaCherno {

	class ZACHERNO_API Application
	{

	public:
		Application();
		virtual ~Application();	// To be overriden by deriving classes so as to prevent memory leaks

		void Run();

	};

	// Must be defined in client
	Application* CreateApplication();

}
