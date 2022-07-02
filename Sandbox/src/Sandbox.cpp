#include <Zephox.h>
#include <Zephox/Events/KeyEvent.h>
#include <Zephox/Events/Event.h>

class Sandbox : public Zephox::Application {
public:
	Sandbox() {
		PushLayer(new TestLayer());
	}

	~Sandbox() {

	}
};

Zephox::Application* Zephox::CreateApplication() {
	return new Sandbox();
}