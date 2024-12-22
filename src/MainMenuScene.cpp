#include "MainMenuScene.h"
#include "Globals.h"

MainMenuScene::MainMenuScene(Application& app, Renderer* renderer):
	Scene(app, renderer)
{
	m_backgroundColor = GRAY;
	//m_userInterface.addButton(100, 100, 400, 100, "Test label").setCallback([]() { g_application->requestExit(); });

	int btnW = 400;
	int btnH = 100;
	int btnStartX = (m_renderer->getWidth() - btnW )/2;
	int btnStartY = 100;
	int btnPad = 120;
	m_uiManager.addButton(btnStartX, btnStartY + 0 * btnPad, btnW, btnH, "Classic", nullptr);
	m_uiManager.addButton(btnStartX, btnStartY + 1 * btnPad, btnW, btnH, "Survival", nullptr);
	m_uiManager.addButton(btnStartX, btnStartY + 2 * btnPad, btnW, btnH, "Level Creator", nullptr);
	m_uiManager.addButton(btnStartX, btnStartY + 3 * btnPad, btnW, btnH, "Option", nullptr);
	m_uiManager.addButton(btnStartX, btnStartY + 4 * btnPad, btnW, btnH, "Exit", nullptr).setCallback(callbackExit);
}

void MainMenuScene::draw(){
	m_renderer->clear(m_backgroundColor);
	//m_renderer->drawCircle(m_renderer->getWidth() / 2, m_renderer->getHeight() / 2, 300, RED);
	m_renderer->drawUI(m_uiManager);
}

static MouseState aggregateMouseState() {
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

void MainMenuScene::update(){
	MouseState state = aggregateMouseState();
	m_uiManager.processMouseInput(state);
}

void callbackClassic() {

}

void callbackSurvival(){

}

void callbackLevelCreator(){

}

void callbackOption(){

}

void callbackExit(){
	g_application->requestExit();
}
