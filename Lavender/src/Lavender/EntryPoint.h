#pragma once

#ifdef LV_PLATFORM_WINDOWS

extern Lv::Application* Lv::CreateApplication();

int main(int argc, char** argv) {
	Lv::Log::Init();
	LV_CORE_INFO("Logger initialization succeeded");
	Lv::Application* app = Lv::CreateApplication();
	app->Run();
	delete app;

	std::cin.get();
	return 0;
}

#endif