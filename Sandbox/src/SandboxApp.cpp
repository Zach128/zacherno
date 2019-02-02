#include <ZaCherno.h>

class ExampleLayer : public ZaCherno::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		ZC_INFO("ExampleLayer::Update");
	}

	void OnEvent(ZaCherno::Event& event) override
	{
		ZC_TRACE("{0}", event);
	}
};

class Sandbox : public ZaCherno::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{
	}
};

ZaCherno::Application* ZaCherno::CreateApplication()
{
	return new Sandbox();
}