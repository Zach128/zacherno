#include "zcpch.h"
#include "Application.h"

#include "ZaCherno/Log.h"

#include <glad/glad.h>

namespace ZaCherno
{

#define BIND_EVENT_FN(t) std::bind(&Application::t, this, std::placeholders::_1)

	Application* Application::s_Instance = nullptr;

Application::Application()	// Constructor
{

	ZC_CORE_ASSERT(!s_Instance, "Application already exists!");
	s_Instance = this;

	m_Window = std::unique_ptr<Window>(Window::Create());

	// Bind the OnEvent function to the Eventcallback of the window
	m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
}


Application::~Application()	// Destructor
{
	
}

void Application::PushLayer(Layer* layer)
{
	m_LayerStack.PushLayer(layer);
	layer->OnAttach();
}

void Application::PushOverlay(Layer* overlay)
{
	m_LayerStack.PushOverlay(overlay);
	overlay->OnAttach();
}

void Application::OnEvent(Event & e)
{

	// Call the OnWindowClosed function if the given Event 'e' is a WindowCloseEvent
	EventDispatcher dispatcher(e);
	dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClosed));

	for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
	{
		(*--it)->OnEvent(e);
		if (e.Handled)
			break;
	}

}

void Application::Run()		// The Applications 'main' function
{
	while (m_Running)
	{
		glClearColor(1, 0, 1, 1);
		glClear(GL_COLOR_BUFFER_BIT);

		for (Layer* layer : m_LayerStack)
			layer->OnUpdate();

		m_Window->OnUpdate();

	}
}

bool Application::OnWindowClosed(WindowCloseEvent& e)
{
	m_Running = false;
	return true;
}

}