#include "UIManager.h"



UIElements::Button& UIManager::addButton(uint32_t x, uint32_t y, uint32_t width, uint32_t height, const char* label,
	const UIDescriptors::Button* descriptor, void (*callback)())
{
	return m_buttons.emplace_back(x, y, width, height, label, descriptor, callback);
}

UIElements::Level& UIManager::addLevel(uint32_t x, uint32_t y, uint32_t width, uint32_t height,
	MazeLevel* mazeLevel, UIDescriptors::Level* descriptor, void(*callbackClick)(UIElements::Level& level, uint8_t xi, uint8_t yi))
{
	m_level = new UIElements::Level( x, y, width, height, mazeLevel, descriptor, callbackClick );
	return *m_level;
}

UIElements::TileHighlighter& UIManager::addTileHighlighter(uint32_t x, uint32_t y, uint32_t width, uint32_t height, const UIDescriptors::TileHighlighter* descriptor)
{
	m_highlighter = new UIElements::TileHighlighter( x,  y, width, height, descriptor );
	return *m_highlighter;
}

void UIManager::processMouseInput(const MouseState& state)
{
	//Buttons
	for (size_t i = 0; i < m_buttons.size(); i++) {
		UIElements::Button& button = m_buttons[i];

		if (state.mouseX >= button.getX() && state.mouseX <= button.getX() + button.getWidth() &&
			state.mouseY >= button.getY() && state.mouseY <= button.getY() + button.getHeight()) 
		{		
			//TODO: Try ro improve logic
			if (button.getState() == UIElements::UIElementState::CLICKED)
				if(state.left == MouseButtonState::DOWN)
					break;
				else if (state.left == MouseButtonState::RELEASED) {
					button.triggerCallback();
					break;
				}
			
			if (state.left == MouseButtonState::PRESSED) {
				button.setState(UIElements::UIElementState::CLICKED);
				break;
			}

			button.setState(UIElements::UIElementState::HOVERED);
			break;
		}

		button.setState(UIElements::UIElementState::IDLE);
	}

	//Level

	if (m_level)
	{
		//If mouse inside
		UIElements::LevelInnerDimensions dims = m_level->getInnerDims();
		if(	state.mouseX >= dims.posX && state.mouseX <= dims.posX + dims.width &&
			state.mouseY >= dims.posY && state.mouseY <= dims.posY + dims.height)
		{
			switch (state.left) 
			{
			case MouseButtonState::PRESSED:
				m_level->setState(UIElements::UIElementState::CLICKED);
				break;
			case MouseButtonState::DOWN:
				break;
			case MouseButtonState::UP:
				m_level->setState(UIElements::UIElementState::HOVERED);
				break;
			default:
				break;
			}

			if (m_highlighter)
			{
				int xi = (state.mouseX - dims.posX) / dims.tileSize;
				int yi = (state.mouseY - dims.posY) / dims.tileSize;
				m_highlighter->setX(dims.posX + xi * dims.tileSize);
				m_highlighter->setY(dims.posY + yi * dims.tileSize);
				m_highlighter->setWidth(dims.tileSize);
				m_highlighter->setHeight(dims.tileSize);
				if(state.left == MouseButtonState::PRESSED)
					m_level->setTilePaint(!m_level->getMazeLevel()->getTile(xi, yi));

				if (m_level->getState() == UIElements::UIElementState::CLICKED) {
					m_level->triggerCallback(xi, yi);
				}
			}
		}
		//If mouse ourside
		else
			m_level->setState(UIElements::UIElementState::IDLE);
			
	}
}

UIManager::~UIManager(){
	if (m_level)
		delete m_level;
	if (m_highlighter)
		delete m_highlighter;
}
