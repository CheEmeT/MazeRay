#ifndef MAZERAY_WINDOW
#define MAZERAY_WINDOW

#include <cstdint>

#include "raylib.h"

class Window {
public:
	Window(uint32_t width, uint32_t height, const char* title);
	void pollEvents();
	bool shouldClose();
private:
	uint32_t m_width;
	uint32_t m_height;
	const char* m_title;
};

#endif