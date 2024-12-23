#ifndef MAZERAY_RENDERER
#define MAZERAY_RENDERER

#include <cstdint>

#include "raylib.h"
#include "UIManager.h"
#include "MazeLevel.h"

class Renderer {
public:
	Renderer(uint32_t width, uint32_t height);

	void clear(Color background);
	void drawUI(const UIManager& ui);
	//Draws MazeLevel in the center presrving square aspect ratio of tiles

	uint32_t getWidth() const { return m_width; }
	uint32_t getHeight() const { return m_height; }
private:
	uint32_t m_width;
	uint32_t m_height;
private:
	void drawUIButton(const UIElements::Button& button);
	void drawUILevel(const UIElements::Level& level);
	void drawMazeLevel(const UIElements::Level& level, bool withBorders);
	void drawTileHighlighter(const UIElements::TileHighlighter& tileTileHighlighter);
};


#endif // !MAZERAY_RENDERER
