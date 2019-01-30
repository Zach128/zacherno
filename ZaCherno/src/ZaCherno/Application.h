#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "ZaCherno/Events/ApplicationEvent.h"

#include "Window.h"

namespace ZaCherno {

	class ZACHERNO_API Application
	{

	public:
		Application();
		virtual ~Application();	// To be overriden by deriving classes so as to prevent memory leaks

		void Run();
		
		void OnEvent(Event& e);
	private:
		bool OnWindowClosed(WindowCloseEvent& e);
		
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	// Must be defined in client
	Application* CreateApplication();

}
