#include "zcpch.h"
#include "Application.h"

#include "ZaCherno/Events/ApplicationEvent.h"
#include "ZaCherno/Log.h"

namespace ZaCherno
{

Application::Application()	// Constructor
{
}


Application::~Application()	// Destructor
{
}

void Application::Run()		// The Applications 'main' function
{

	WindowResizeEvent e(1280, 720);
	ZC_TRACE(e);

	while (true);
}

}