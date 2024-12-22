#include "Renderer.h"

Color static toRaylibColor(const UIDescriptors::Color& color) {
	return Color{ color.r, color.g, color.b, color.a };
}

Renderer::Renderer(uint32_t width, uint32_t height){
	m_width = width;
	m_height = height;
}

void Renderer::clear(Color background){
	ClearBackground(background);
}

void Renderer::drawUI(const UIManager& ui){
	const std::vector<UIElements::Button>& buttons = ui.getButtons();
	for (int i = 0; i < buttons.size(); i++) {
		const UIElements::Button& button = buttons[i];
		//Color fillColor;
		//Color borderColor;
		//Color fontColor;
		//int fontSize;
		//int borderThickness;
		
		//Getting apropriate state's descriptor
		const UIDescriptors::Button& descriptor = *button.getDescriptor();
		UIDescriptors::ButtonState stateDescriptor;
		switch (button.getState())		{
		case UIElements::ButtonState::IDLE:
			stateDescriptor = descriptor.idle;
			break;
		case UIElements::ButtonState::HOVERED:
			stateDescriptor = descriptor.hovered;
			break;
		case UIElements::ButtonState::CLICKED:
			stateDescriptor = descriptor.clicked;
			break;
		default:
			break;
		}

		//Drawing button
		Rectangle rect{
			(float)button.getX(),
			(float)button.getY(),
			(float)button.getWidth(),
			(float)button.getHeight()
		};

		DrawRectangleRec(rect, toRaylibColor(stateDescriptor.box.fillColor));
		DrawRectangleLinesEx(rect, 
			stateDescriptor.box.borderThickness, 
			toRaylibColor(stateDescriptor.box.borderColor));
		//Drawing text in the middle
		int textX = button.getX() +
			(button.getWidth() - MeasureText(button.getLabel(), stateDescriptor.font.size))/2;
		int textY = button.getY() + (button.getHeight() - stateDescriptor.font.size)/2;
		DrawText(button.getLabel(), textX, textY,
			stateDescriptor.font.size, toRaylibColor(stateDescriptor.font.color));
	}
}

void Renderer::drawCircle(int centerX, int centerY, int radius, Color color){
	DrawCircle(centerX, centerY, radius, color);
}

