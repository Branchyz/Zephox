#pragma once

#include "zppch.h"
#include "Core.h"

namespace Zephox {
	class ZP_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// Defined in the Zephox App.
	Application* CreateApplication();
}


