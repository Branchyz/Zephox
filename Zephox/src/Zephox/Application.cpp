#include "zppch.h"
#include "Application.h"

#include <GLFW/glfw3.h>

namespace Zephox {
	
	Application::Application() {
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application() {

	}

	void Application::Run() {
		while (m_Running) {
			m_Window->OnUpdate();
		}
	}
}