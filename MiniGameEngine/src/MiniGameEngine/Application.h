#pragma once

#include "Core.h"

namespace MiniGameEngine {

	class MGE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in Client
	Application* CreateApplication();
} // namespace MiniGameEngine
