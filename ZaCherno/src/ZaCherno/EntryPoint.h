#pragma once

#ifdef ZC_PLATFORM_WINDOWS

extern ZaCherno::Application * ZaCherno::CreateApplication();

int main(int argc, int** argv)
{

	printf("zaCherno engine starting up.");

	auto app = ZaCherno::CreateApplication();
	app->Run();
	delete app;
}

#endif