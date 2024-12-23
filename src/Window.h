#ifndef MAZERAY_WINDOW
#define MAZERAY_WINDOW

#include <cstdint>

#include "raylib.h"

enum MouseButtonState {
	UP,
	PRESSED,
	DOWN,
	RELEASED,
};

struct MouseState
{
	uint32_t mouseX;
	uint32_t mouseY;
	MouseButtonState left;
	MouseButtonState right;
};

class Window {
public:
	Window(uint32_t width, uint32_t height, const char* title);
	void pollEvents();
	bool shouldClose();

	MouseState getMouseState();
	uint32_t getWidth() const { return m_width; }
	uint32_t getHeight() const { return m_height; }
private:
	uint32_t m_width;
	uint32_t m_height;
	const char* m_title;
};

#endif