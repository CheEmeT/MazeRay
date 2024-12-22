#include "UIManager.h"

UIElements::Button& UIManager::addButton(uint32_t x, uint32_t y, uint32_t width, uint32_t height, const char* label,
	const UIDescriptors::Button* descriptor)
{
	UIElements::Button&button = m_buttons.emplace_back(x, y, width, height, label, descriptor);
	if(!descriptor)
		button.setDescriptor(&UIDescriptors::DEFAULT_BUTTON_DESCRIPTOR);
	return button;
}


void UIManager::processMouseInput(const MouseState& state){
	//Buttons
	for (size_t i = 0; i < m_buttons.size(); i++) {
		UIElements::Button& button = m_buttons[i];

		if (state.mouseX > button.getX() && state.mouseX < button.getX() + button.getWidth() &&
			state.mouseY > button.getY() && state.mouseY < button.getY() + button.getHeight()) 
		{		
			if (button.getState() == UIElements::ButtonState::CLICKED && state.left == MouseButtonState::DOWN)
				break;
			
			if (state.left == MouseButtonState::PRESSED) {
				button.setState(UIElements::ButtonState::CLICKED);
				button.triggerCallback();
				break;
			}

			button.setState(UIElements::ButtonState::HOVERED);
			break;
		}

		button.setState(UIElements::ButtonState::IDLE);
	}
}

