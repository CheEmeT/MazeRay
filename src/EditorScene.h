#ifndef MAZERAY_EDITORSCENE
#define MAZERAY_EDITORSCENE


#include "Scene.h"
#include "UIManager.h"
#include "MazeLevel.h"

class EditorScene : public Scene {
public:
	EditorScene( Renderer* renderer );
	virtual void draw() override;
	virtual void update() override;

private:
	UIManager m_uiManager;
	UIElements::Level* m_uiMazelevel = nullptr;
	UIElements::TileHighlighter* m_highlighter = nullptr;
	MazeLevel m_level;
private:
	void processMouseInput(const MouseState& state);
};

static void callbackBack();
static void callbackLevel(UIElements::Level& level, uint8_t xi, uint8_t yi);

#endif // !MAZERAY_EDITORSCENE
