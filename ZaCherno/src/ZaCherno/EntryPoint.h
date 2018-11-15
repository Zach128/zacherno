#pragma once

#ifdef ZC_PLATFORM_WINDOWS

extern ZaCherno::Application* ZaCherno::CreateApplication();

int main(int argc, int** argv)
{

	// Initialise the logger system
	ZaCherno::Log::Init();
	ZC_CORE_WARN("Initialized Log!");
	ZC_INFO("Initialized Client Log!");

	// Test printing of variables
	char world[] = "World";
	ZC_INFO("Hello {0}!", world);

	auto app = ZaCherno::CreateApplication();
	app->Run();
	delete app;
}

#endif