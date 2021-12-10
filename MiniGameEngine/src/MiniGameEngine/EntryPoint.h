#pragma once

#ifdef MGE_PLATFORM_WINDOWS

extern MiniGameEngine::Application* MiniGameEngine::CreateApplication();

int main(int argc, char** argv)
{
	MiniGameEngine::Log::Init();
	MGE_CORE_WARN("Initialized Log!");
	int a = 5;
	MGE_INFO("Hello! Var={0}", a);



	auto app = MiniGameEngine::CreateApplication();
	app->Run();
	delete app;
	return 0;
}

#endif // MGE_PLATFORM_WINDOWS
