#include <MiniGameEngine.h>

class Sandbox : public MiniGameEngine::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

MiniGameEngine::Application* MiniGameEngine::CreateApplication()
{
	return new Sandbox();
}
