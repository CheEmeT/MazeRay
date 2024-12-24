#ifndef MAZERAY_UIMANAGER
#define MAZERAY_UIMANAGER

#include <vector>
#include <memory>

#include "UIElements.h"
#include "UIDescriptors.h"
#include "Window.h"


class UIManager
{
public:
	UIManager() = default;
	~UIManager();

	UIElements::Button& addButton(uint32_t x, uint32_t y, uint32_t width, uint32_t height, const char* label, 
		const Descriptors::Button *descriptor, void (*callback)());

	UIElements::Level& addLevel(uint32_t x, uint32_t y, uint32_t width, uint32_t height,
		MazeLevel* mazeLevel, Descriptors::Level* descriptor, void (*callbackClick)(UIElements::Level& level, uint8_t xi, uint8_t yi));

	UIElements::TileHighlighter& addTileHighlighter(uint32_t x, uint32_t y, uint32_t width, uint32_t height, 
		const Descriptors::TileHighlighter* descriptor);

	void processMouseInput(const MouseState& state);

	const std::vector<UIElements::Button>& getButtons() const { return m_buttons; }
	const UIElements::Level* getLevel() const { return m_level; }
	const UIElements::TileHighlighter* getTileHighlighter() const { return m_highlighter; }
private:
	std::vector<UIElements::Button> m_buttons;
	UIElements::Level* m_level = nullptr;
	UIElements::TileHighlighter* m_highlighter = nullptr;
};

#endif // !MAZERAY_UIMANAGER
