#include "EditorScene.h"
#include "Globals.h"
#include "Window.h"


EditorScene::EditorScene( Renderer* renderer):
	Scene(renderer)
{
	m_backgroundColor = GRAY;

	int btnPad = 20;
	int btnWidth = 150;
	int btnHeight = 50;
	int btnX = (400 - btnWidth) / 2;
	int btnY = m_renderer->getHeight() - btnHeight - btnPad;

	//m_level.tileLevel();

	m_uiManager.addButton(btnX, btnY, btnWidth, btnHeight, "Back", &g_editorButtonsDscr, callbackBack);
	m_uiMazelevel = &m_uiManager.addLevel(400, 0, 900, 900, &m_level, &UIDescriptors::DEFAULT_LEVEL_DESCRIPTOR, callbackLevel);
	m_highlighter = &m_uiManager.addTileHighlighter(0, 0, 0, 0, &UIDescriptors::DEFAULT_TILEHIGHLIGHTER_DESCRIPTOR);
}

void EditorScene::draw()
{
	m_renderer->clear(m_backgroundColor);
	m_renderer->drawUI(m_uiManager);
}

void EditorScene::update()
{
	//if (IsKeyPressed(KeyboardKey::KEY_ESCAPE))
	//	g_application->requestSceneChangeToMainMenu();

	MouseState mouseState = g_application->getWindow().getMouseState();
	processMouseInput(mouseState);
}

void EditorScene::processMouseInput(const MouseState& state)
{
	m_uiManager.processMouseInput(state);

	if (m_uiMazelevel) {

	}
}

static void callbackBack() 
{
	g_application->requestSceneChangeToMainMenu();
}

static void callbackLevel(UIElements::Level& level, uint8_t xi, uint8_t yi)
{
	level.getMazeLevel()->setTile(xi, yi, level.getTilePaint());
}
