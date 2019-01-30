#include "zcpch.h"
#include "Application.h"

#include "ZaCherno/Log.h"

#include <GLFW/glfw3.h>

namespace ZaCherno
{

#define BIND_EVENT_FN(t) std::bind(&Application::t, this, std::placeholders::_1)

Application::Application()	// Constructor
{
	m_Window = std::unique_ptr<Window>(Window::Create());

	// Bind the OnEvent function to the Eventcallback of the window
	m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
}


Application::~Application()	// Destructor
{
	
}

void Application::OnEvent(Event & e)
{

	// Call the OnWindowClosed function if the given Event 'e' is a WindowCloseEvent
	EventDispatcher dispatcher(e);
	dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClosed));

	ZC_CORE_TRACE("{0}", e);
}

void Application::Run()		// The Applications 'main' function
{
	while (m_Running)
	{
		glClearColor(1, 0, 1, 1);
		glClear(GL_COLOR_BUFFER_BIT);
		m_Window->OnUpdate();

	}
}

bool Application::OnWindowClosed(WindowCloseEvent& e)
{
	m_Running = false;
	return true;
}

}