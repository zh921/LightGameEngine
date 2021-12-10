#pragma once

#ifdef MGE_PLATFORM_WINDOWS

extern MiniGameEngine::Application* MiniGameEngine::CreateApplication();

int main(int argc, char** argv)
{
	printf("---Mini Game Engine---\n");
	auto app = MiniGameEngine::CreateApplication();
	app->Run();
	delete app;
	return 0;
}

#endif