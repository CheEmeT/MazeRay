#ifndef MAZERAY_MAINMENUSCENE
#define MAZERAY_MAINMENUSCENE

#include "Scene.h"
#include "UIManager.h"

class MainMenuScene : public Scene {
public:
	MainMenuScene(Application& app, Renderer* renderer);
	virtual void draw() override;
	virtual void update() override;
private:
	UIManager m_uiManager;
};

void callbackClassic();
void callbackSurvival();
void callbackLevelCreator();
void callbackOption();
void callbackExit();

#endif // !MAZERAY_MAINMENUSCENE
