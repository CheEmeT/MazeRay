#include "Application.h"

Application::Application():
	m_window(WIDTH, HEIGHT, TITLE),
	m_renderer(WIDTH, HEIGHT),
	m_mainMenuScene(&m_renderer),
	m_editorScene(&m_renderer),
	m_currentScene(&m_mainMenuScene)
{}

void Application::run(){


	while (!m_window.shouldClose() && !m_exitRequest) {
		//Scene's change logic
		if (m_requestedScene) {
			m_currentScene = m_requestedScene;
			m_requestedScene = nullptr;
		}
		//TODO: Figure out better way of begin and end drawing
		BeginDrawing();

		//Process input and update
		m_window.pollEvents();
		m_currentScene->update();

		//Draw
		m_currentScene->draw();

		EndDrawing();
	}

}

void Application::requestSceneChangeToEditor(){
	m_requestedScene = &m_editorScene;
}

void Application::requestSceneChangeToMainMenu(){
	m_requestedScene = &m_mainMenuScene;
}
