#include "Button.h"

UIElements::Button::Button(uint32_t x, uint32_t y, uint32_t width, uint32_t height, const char* label,
	const UIDescriptors::Button* descriptor):
	Button(x, y, width, height, label, descriptor, nullptr)
{}

UIElements::Button::Button(uint32_t x, uint32_t y, uint32_t width, uint32_t height, const char* label,
	const UIDescriptors::Button* descriptor, void(*callback)()):

	m_posX(x),
	m_posY(y),
	m_width(width),
	m_height(height),
	m_label(label),
	m_callback(callback),
	m_descriptor(descriptor)
{}

void UIElements::Button::triggerCallback(){
	if (m_callback)
		m_callback();
}
