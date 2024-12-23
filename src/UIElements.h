#ifndef MAZERAY_UIELEMENTS
#define MAZERAY_UIELEMENTS

#include <cstdint>
#include <memory>

#include "UIDescriptors.h"
#include "MazeLevel.h"
#include "Window.h"

namespace UIElements {

	enum class UIElementState {
		NONE,
		IDLE,
		HOVERED,
		CLICKED,
	};

	class Button {
	public:

		Button(uint32_t x, uint32_t y, uint32_t width, uint32_t height, const char* label,
			const UIDescriptors::Button* descriptor, void (*callbackClick)());

		void triggerCallback();

		uint32_t getX() const { return m_posX; }
		uint32_t getY() const { return m_posY; }
		uint32_t getWidth() const { return m_width; }
		uint32_t getHeight() const { return m_height; }
		const char* getLabel() const { return m_label; }
		const UIDescriptors::Button* getDescriptor() const{ return m_descriptor; }

		void setDescriptor(const UIDescriptors::Button* descriptor) { m_descriptor = descriptor; }
		void setState(UIElementState state) { m_state = state; }
		UIElementState getState() const { return m_state; }
		void setCallback(void (*callbackClick)()) { m_callbackClick = callbackClick; }

	private:
		uint32_t m_posX;
		uint32_t m_posY;
		uint32_t m_width;
		uint32_t m_height;
		const char* m_label = nullptr;

		UIElementState m_state = UIElementState::IDLE;
		const UIDescriptors::Button* m_descriptor = nullptr;
		void (*m_callbackClick)();
	};

	struct LevelInnerDimensions {
		uint32_t posX = 0;
		uint32_t posY = 0;
		uint32_t width = 0;
		uint32_t height = 0;
		uint32_t tileSize = 0;
	};

	class Level {
	public:
		Level(uint32_t x, uint32_t y, uint32_t width, uint32_t height,
			MazeLevel* mazeLevel, const UIDescriptors::Level* descriptor, void (*callbackClick)(Level& level, uint8_t xi, uint8_t yi));

		void triggerCallback(uint8_t xi, uint8_t yi);
		uint32_t getX() const { return m_posX; }
		uint32_t getY() const { return m_posY; }
		uint32_t getWidth() const { return m_width; }		
		uint32_t getHeight() const { return m_height; }
		uint32_t getTilePaint() const { return m_tilePaint; }
		const LevelInnerDimensions getInnerDims() const;
		const UIDescriptors::Level* getDescriptor() const { return m_descriptor; }
		const MazeLevel* getMazeLevel() const { return m_mazeLevel; }
		MazeLevel* getMazeLevel() { return m_mazeLevel; }
		UIElementState getState() const { return m_state; }
		
		void setState(UIElementState state) { m_state = state; }
		void setTilePaint(uint8_t tilePaint) { m_tilePaint = tilePaint; }

	private:
		uint32_t m_posX;
		uint32_t m_posY;
		uint32_t m_width;
		uint32_t m_height;

		uint8_t m_tilePaint = 0;

		const UIDescriptors::Level* m_descriptor;
		UIElementState m_state = UIElementState::IDLE;
		//TODO: Handle nullptr in constructor (probably weak pointer)
		MazeLevel* m_mazeLevel = nullptr;

		void (*m_callbackClick)(Level& level, uint8_t xi, uint8_t yi);
	};

	class TileHighlighter {
	public:
		TileHighlighter(uint32_t x, uint32_t y, uint32_t width, uint32_t height, const UIDescriptors::TileHighlighter* descriptor);

		uint32_t getX() const { return m_posX; }
		uint32_t getY() const { return m_posY; }
		uint32_t getWidth() const { return m_width; }
		uint32_t getHeight() const { return m_height; }

		void setX(uint32_t posX) { m_posX = posX; }
		void setY(uint32_t posY) { m_posY = posY; }
		void setWidth(uint32_t width) { m_width = width; }
		void setHeight(uint32_t height) { m_height= height; }

		const UIDescriptors::TileHighlighter* getDescriptor() const { return m_descriptor; }
	private:
		uint32_t m_posX;
		uint32_t m_posY;
		uint32_t m_width;
		uint32_t m_height;

		const UIDescriptors::TileHighlighter* m_descriptor;
	};
}
#endif // !MAZERAY_UIELEMENTS
