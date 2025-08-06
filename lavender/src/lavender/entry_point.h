#pragma once

extern lv::application* lv::create_application();

int entry_point(int argc, char** argv) {
	lv::application* app = lv::create_application();
	app->run();
	delete app;
	return 0;
}

#if defined(LV_WINDOWS) and defined(LV_DIST)

INT APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, INT cmdshow) {
	return entry_point(__argc, __argv);
}

#else

int main(int argc, char** argv) {
	return entry_point(argc, argv);
}

#endif