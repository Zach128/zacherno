#include <ZaCherno.h>

class Sandbox : public ZaCherno::Application
{
public:
	Sandbox()
	{}

	~Sandbox()
	{}
};

ZaCherno::Application * ZaCherno::CreateApplication()
{
	return new Sandbox();
}