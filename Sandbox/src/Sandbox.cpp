#include <Zephox.h>

class Sandbox : public Zephox::Application {
public:
	Sandbox() {

	}

	~Sandbox() {

	}
};

Zephox::Application* Zephox::CreateApplication() {
	return new Sandbox();
}