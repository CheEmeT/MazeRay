#include "EditorScene.h"
#include "Globals.h"
#include "Window.h"
#include <functional>

//TODO: Is this a good way?
static MazeLevel* l_mazeLevel;

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
	m_uiManager.addButton(btnX - (btnWidth + btnPad)/2, btnY - 1 * (btnHeight + btnPad), btnWidth, btnHeight, "Clear", &g_editorButtonsDscr, callbackClear);
	m_uiManager.addButton(btnX + (btnWidth + btnPad) / 2, btnY - 1 * (btnHeight + btnPad), btnWidth, btnHeight, "Fill", &g_editorButtonsDscr, callbackFill);
	m_uiManager.addButton(btnX - (btnWidth + btnPad)/2, btnY - 2 * (btnHeight + btnPad), btnWidth, btnHeight, "Save", &g_editorButtonsDscr, callbackSave);
	m_uiManager.addButton(btnX + (btnWidth + btnPad) / 2, btnY - 2 * (btnHeight + btnPad), btnWidth, btnHeight, "Open", &g_editorButtonsDscr, callbackOpen);

	m_uiMazelevel = &m_uiManager.addLevel(400, 0, 900, 900, &m_level, &Descriptors::DEFAULT_LEVEL_DESCRIPTOR, callbackLevel);
	m_highlighter = &m_uiManager.addTileHighlighter(0, 0, 0, 0, &Descriptors::DEFAULT_TILEHIGHLIGHTER_DESCRIPTOR);
	l_mazeLevel = &m_level;
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

void callbackClear()
{
	l_mazeLevel->clearLevel(1);
}

void callbackFill()
{
	l_mazeLevel->clearLevel(0);
}

void callbackSave()
{
	saveLevel(*l_mazeLevel, g_defaultSaveName);
}

void callbackOpen()
{
	loadLevel(*l_mazeLevel, g_defaultSaveName);
}

static void callbackLevel(UIElements::Level& level, uint8_t xi, uint8_t yi)
{
	level.getMazeLevel()->setTile(xi, yi, level.getTilePaint());
}
