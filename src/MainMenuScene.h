#ifndef MAZERAY_MAINMENUSCENE
#define MAZERAY_MAINMENUSCENE

#include "Scene.h"
#include "UIManager.h"

class MainMenuScene : public Scene {
public:
	MainMenuScene( Renderer* renderer );
	virtual void draw() override;
	virtual void update() override;
private:
	UIManager m_uiManager;
};

static void callbackClassic();
static void callbackSurvival();
static void callbackEditor();
static void callbackOption();
static void callbackExit();

#endif // !MAZERAY_MAINMENUSCENE
