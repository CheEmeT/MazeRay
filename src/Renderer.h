#ifndef MAZERAY_RENDERER
#define MAZERAY_RENDERER

#include <cstdint>

#include "raylib.h"
#include "UIManager.h"

class Renderer {
public:
	Renderer(uint32_t width, uint32_t height);

	void clear(Color background);
	void drawUI(const UIManager& ui);
	void drawCircle(int x, int y, int radius, Color color);

	uint32_t getWidth() const { return m_width; }
	uint32_t getHeight() const { return m_height; }
private:
	uint32_t m_width;
	uint32_t m_height;
};


#endif // !MAZERAY_RENDERER
