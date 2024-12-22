#include "Window.h"

Window::Window(uint32_t width, uint32_t height, const char* title){
	m_width = width;
	m_height = height;
	m_title = title;

	SetConfigFlags(FLAG_VSYNC_HINT);
	InitWindow(m_width, m_height, m_title);
	SetTargetFPS(60);
	SetExitKey(KEY_NULL);
}

void Window::pollEvents(){
	//PollInputEvents();
}

bool Window::shouldClose(){
    return WindowShouldClose();
}
