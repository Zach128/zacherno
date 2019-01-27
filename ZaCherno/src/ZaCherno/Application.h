#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Window.h"

namespace ZaCherno {

	class ZACHERNO_API Application
	{

	public:
		Application();
		virtual ~Application();	// To be overriden by deriving classes so as to prevent memory leaks

		void Run();
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	// Must be defined in client
	Application* CreateApplication();

}
