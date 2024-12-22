#ifndef MAZERAY_APPLICATION
#define MAZERAY_APPLICATION

#include <cstdint>
#include <memory>

#include "raylib.h"
#include "Window.h"
#include "Renderer.h"
#include "MainMenuScene.h"

constexpr uint32_t WIDTH = 1300u;
constexpr uint32_t HEIGHT = 900u;
constexpr const char* TITLE = "Maze";

class Application {
public:
	Application();
	void run();

	void requestExit() { m_exitRequest = true; }
private:
	bool m_exitRequest = false;
	Window m_window;
	Renderer m_renderer;
	Scene* m_currentScene;
	MainMenuScene m_mainMenuScene;
};

#endif // !MAZERAY_APPLICATION