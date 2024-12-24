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

MouseState Window::getMouseState(){
	MouseState state{};
	state.mouseX = GetMouseX();
	state.mouseY = GetMouseY();

	state.left = UP;
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		state.left = PRESSED;
	else if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
		state.left = DOWN;
	else if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
		state.left = RELEASED;

	state.right = UP;
	if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
		state.right = PRESSED;
	else if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
		state.right = DOWN;
	else if (IsMouseButtonReleased(MOUSE_BUTTON_RIGHT))
		state.right = RELEASED;

	return state;
}

bool Window::isResized()
{
	return IsWindowResized();
}
