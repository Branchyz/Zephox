#pragma once
#include "Application.h"

#ifdef ZP_PLATFORM_WINDOWS

extern Zephox::Application* Zephox::CreateApplication();

int main(int argc, char** argv) {
	auto app = Zephox::CreateApplication();
	app->Run();
	delete app;
}

#else
	#error Zephox currently only supports windows!
#endif
