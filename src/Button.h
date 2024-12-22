#ifndef MAZERAY_BUTTON
#define MAZERAY_BUTTON

#include <cstdint>

#include "UIDescriptors.h"

namespace UIElements {

	enum class ButtonState {
		NONE,
		IDLE,
		HOVERED,
		CLICKED,
	};

	class Button {
	public:
		Button() = default;
		Button(uint32_t x, uint32_t y, uint32_t width, uint32_t height, const char* label,
			const UIDescriptors::Button* descriptor);
		Button(uint32_t x, uint32_t y, uint32_t width, uint32_t height, const char* label,
			const UIDescriptors::Button* descriptor, void (*callback)());

		void triggerCallback();

		uint32_t getX() const { return m_posX; }
		uint32_t getY() const { return m_posY; }
		uint32_t getWidth() const { return m_width; }
		uint32_t getHeight() const { return m_height; }
		const char* getLabel() const { return m_label; }
		const UIDescriptors::Button* getDescriptor() const{ return m_descriptor; }

		void setDescriptor(const UIDescriptors::Button* descriptor) { m_descriptor = descriptor; }
		void setState(ButtonState state) { m_state = state; }
		ButtonState getState() const { return m_state; }
		void setCallback(void (*callback)()) { m_callback = callback; }

	private:
		uint32_t m_posX;
		uint32_t m_posY;
		uint32_t m_width;
		uint32_t m_height;
		const char* m_label = nullptr;

		ButtonState m_state = ButtonState::IDLE;
		const UIDescriptors::Button* m_descriptor = nullptr;
		void (*m_callback)();
	};

}
#endif // !MAZERAY_BUTTON
