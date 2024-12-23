#include "MainMenuScene.h"
#include "Globals.h"

MainMenuScene::MainMenuScene( Renderer* renderer ):
	Scene(renderer)
{
	m_backgroundColor = GRAY;
	//m_userInterface.addButton(100, 100, 400, 100, "Test label").setCallback([]() { g_application->requestExit(); });

	int btnW = 400;
	int btnH = 100;
	int btnStartX = (m_renderer->getWidth() - btnW )/2;
	int btnStartY = 100;
	int btnPad = 120;
	m_uiManager.addButton(btnStartX, btnStartY + 0 * btnPad, btnW, btnH, "Classic", &g_mainMenuButtonsDscr, nullptr);
	m_uiManager.addButton(btnStartX, btnStartY + 1 * btnPad, btnW, btnH, "Survival", &g_mainMenuButtonsDscr, nullptr);
	m_uiManager.addButton(btnStartX, btnStartY + 2 * btnPad, btnW, btnH, "Editor", &g_mainMenuButtonsDscr, callbackEditor);
	m_uiManager.addButton(btnStartX, btnStartY + 3 * btnPad, btnW, btnH, "Option", &g_mainMenuButtonsDscr, nullptr);
	m_uiManager.addButton(btnStartX, btnStartY + 4 * btnPad, btnW, btnH, "Exit", &g_mainMenuButtonsDscr, callbackExit);
}

void MainMenuScene::draw(){
	m_renderer->clear(m_backgroundColor);
	//m_renderer->drawCircle(m_renderer->getWidth() / 2, m_renderer->getHeight() / 2, 300, RED);
	m_renderer->drawUI(m_uiManager);
}

void MainMenuScene::update(){
	MouseState state = g_application->getWindow().getMouseState();
	m_uiManager.processMouseInput(state);
}

static void callbackClassic() {

}

static void callbackSurvival() {

}

static void callbackEditor() {
	g_application->requestSceneChangeToEditor();
}

static void callbackOption() {

}

static void callbackExit(){
	g_application->requestExit();
}
