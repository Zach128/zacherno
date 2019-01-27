#include "zcpch.h"
#include "Application.h"

#include "ZaCherno/Events/ApplicationEvent.h"
#include "ZaCherno/Log.h"

#include <GLFW/glfw3.h>

namespace ZaCherno
{

Application::Application()	// Constructor
{
	m_Window = std::unique_ptr<Window>(Window::Create());
}


Application::~Application()	// Destructor
{
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

}