#pragma once

#include "Core.h"

#include "Window.h"
#include "ZaCherno/LayerStack.h"
#include "ZaCherno/Events/Event.h"
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

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }
	private:
		bool OnWindowClosed(WindowCloseEvent& e);
		
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	private:
		static Application* s_Instance;
	};

	// Must be defined in client
	Application* CreateApplication();

}
