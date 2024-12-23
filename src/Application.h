#ifndef MAZERAY_APPLICATION
#define MAZERAY_APPLICATION

#include <cstdint>
#include <memory>

#include "raylib.h"
#include "Window.h"
#include "Renderer.h"
#include "MainMenuScene.h"
#include "EditorScene.h"

constexpr uint32_t WIDTH = 1300u;
constexpr uint32_t HEIGHT = 900u;
constexpr const char* TITLE = "Maze";

class Application {
public:
	Application();
	void run();

	void requestExit() { m_exitRequest = true; }
	void requestSceneChangeToEditor();
	void requestSceneChangeToMainMenu();
	Window& getWindow() { return m_window; }

private:
	bool m_exitRequest = false;
	Window m_window;
	Renderer m_renderer;

	Scene* m_currentScene;
	Scene* m_requestedScene = nullptr;
	EditorScene m_editorScene;
	MainMenuScene m_mainMenuScene;
};

#endif // !MAZERAY_APPLICATION