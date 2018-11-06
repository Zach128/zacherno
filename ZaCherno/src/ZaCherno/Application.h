#pragma once

#include "Core.h"

namespace ZaCherno {

	class ZACHERNO_API Application
	{

	public:
		Application();
		virtual ~Application();

		void Run();

	};

	//Must be defined in client
	Application * CreateApplication();

}
