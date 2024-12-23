#include <cassert>

#include "UIElements.h"

namespace UIElements {

	Button::Button(uint32_t x, uint32_t y, uint32_t width, uint32_t height, const char* label,
		const UIDescriptors::Button* descriptor, void(*callbackClick)()) :
		m_posX(x),
		m_posY(y),
		m_width(width),
		m_height(height),
		m_label(label),
		m_callbackClick(callbackClick),
		m_descriptor(descriptor)
	{
		if (!descriptor)
			descriptor = &UIDescriptors::DEFAULT_BUTTON_DESCRIPTOR;
	}

	void Button::triggerCallback() 
	{
		if (m_callbackClick)
			m_callbackClick();
	}

	Level::Level(uint32_t x, uint32_t y, uint32_t width, uint32_t height,
		MazeLevel* mazeLevel, const UIDescriptors::Level* descriptor, void(*callbackCLick)(Level& level, uint8_t xi, uint8_t yi)):
		m_posX(x),
		m_posY(y),
		m_width(width),
		m_height(height),
		m_mazeLevel(mazeLevel),
		m_descriptor(descriptor),
		m_callbackClick(callbackCLick)
	{
		if (!descriptor)
			descriptor = &UIDescriptors::DEFAULT_LEVEL_DESCRIPTOR;
	}

	void Level::triggerCallback(uint8_t xi, uint8_t yi) {
		if (m_callbackClick)
			m_callbackClick(*this, xi, yi);
	}

	const LevelInnerDimensions Level::getInnerDims() const 
	{
		LevelInnerDimensions result;
		if (!m_mazeLevel)
			return result;

		const MazeLevel& mazeLevel = *m_mazeLevel;

		if (m_width / mazeLevel.getWidth() <= m_height / mazeLevel.getHeight()) {
			result.tileSize = m_width / mazeLevel.getWidth();
		}
		else {
			result.tileSize = m_height / mazeLevel.getHeight();
		}

		int offsetX = (m_width - result.tileSize * mazeLevel.getWidth()) / 2;
		int offsetY = (m_height - result.tileSize * mazeLevel.getHeight()) / 2;

		result.posX = m_posX + offsetX;
		result.posY = m_posY + offsetY;
		result.width = result.tileSize * mazeLevel.getWidth();
		result.height = result.tileSize * mazeLevel.getHeight();
		return result;
	}

	TileHighlighter::TileHighlighter(uint32_t x, uint32_t y, uint32_t width, uint32_t height,
		const UIDescriptors::TileHighlighter* descriptor):
		m_posX(x),
		m_posY(y),
		m_width(width),
		m_height(height),
		m_descriptor(descriptor)
	{}
}