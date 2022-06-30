#pragma once

#include "zppch.h"
#include "Events/ApplicationEvent.h"
#include "Core.h"
#include "Window.h"

namespace Zephox {
	class ZP_API Application {
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		bool m_Running = true;
		std::unique_ptr<Window> m_Window;
	};

	// Defined in the Zephox App.
	Application* CreateApplication();
}


