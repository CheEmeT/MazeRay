#ifndef MAZERAY_UIMANAGER
#define MAZERAY_UIMANAGER

#include <vector>

#include "Button.h"
#include "UIDescriptors.h"

enum MouseButtonState {
	UP,
	PRESSED,
	DOWN,
	RELEASED,
};

struct MouseState
{
	uint32_t mouseX;
	uint32_t mouseY;
	MouseButtonState left;
	MouseButtonState right;
};


class UIManager
{
public:
	UIManager() = default;

	UIElements::Button& addButton(uint32_t x, uint32_t y, uint32_t width, uint32_t height, const char* label, const UIDescriptors::Button *descriptor);

	void processMouseInput(const MouseState& state);

	const std::vector<UIElements::Button>& getButtons() const { return m_buttons; }
private:
	std::vector<UIElements::Button> m_buttons;
};

#endif // !MAZERAY_UIMANAGER
