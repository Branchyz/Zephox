#pragma once

#include "zppch.h"
#include "Events/ApplicationEvent.h"
#include "Core.h"
#include "LayerStack.h"
#include "Window.h"

namespace Zephox {
	class ZP_API Application {
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	// Defined in the Zephox App.
	Application* CreateApplication();
}


