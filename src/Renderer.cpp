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

void Renderer::drawUI(const UIManager& ui) {
	const std::vector<UIElements::Button>& buttons = ui.getButtons();
	//Draw buttons
	for (int i = 0; i < buttons.size(); i++) {
		drawUIButton(buttons[i]);
	}

	//Draw level
	const UIElements::Level* level = ui.getLevel();
	if (level) 
		drawUILevel(*level);	

	//Draw tile highlighter
	const UIElements::TileHighlighter* tileHighlighter = ui.getTileHighlighter();
	if (tileHighlighter)
		drawTileHighlighter(*tileHighlighter);
}

void Renderer::drawUIButton(const UIElements::Button& button) {
	//Getting apropriate descriptor for state
	//TODO Weak pointer
	const UIDescriptors::Button& descriptor = *button.getDescriptor();
	UIDescriptors::ButtonState stateDescriptor;
	switch (button.getState()) {
	case UIElements::UIElementState::IDLE:
		stateDescriptor = descriptor.idle;
		break;
	case UIElements::UIElementState::HOVERED:
		stateDescriptor = descriptor.hovered;
		break;
	case UIElements::UIElementState::CLICKED:
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
		stateDescriptor.box.border.thickness,
		toRaylibColor(stateDescriptor.box.border.color));
	//Drawing text in the middle
	int textX = button.getX() +
		(button.getWidth() - MeasureText(button.getLabel(), stateDescriptor.font.size)) / 2;
	int textY = button.getY() + (button.getHeight() - stateDescriptor.font.size) / 2;
	DrawText(button.getLabel(), textX, textY,
		stateDescriptor.font.size, toRaylibColor(stateDescriptor.font.color));
}

void Renderer::drawUILevel(const UIElements::Level& level) {	
	if (level.getMazeLevel()) {
		const UIDescriptors::Level& descriptor = *level.getDescriptor();

		DrawRectangle(level.getX(), level.getY(), level.getWidth(), level.getHeight(), 
			toRaylibColor(descriptor.background));

		drawMazeLevel(level, true);

	}
}

void Renderer::drawMazeLevel(const UIElements::Level& level, bool withBorders)
{
	const UIElements::LevelInnerDimensions innerDims = level.getInnerDims();
	const MazeLevel& mazeLevel = *level.getMazeLevel();
	auto& levelData = mazeLevel.getLevelData();
	for (size_t y = 0; y < mazeLevel.getHeight(); y++)
		for (size_t x = 0; x < mazeLevel.getWidth(); x++)
		{
			size_t index = x + y * mazeLevel.getWidth();
			Color col = levelData[index] ? WHITE : BLACK;
			DrawRectangle(
				innerDims.posX + x * innerDims.tileSize,
				innerDims.posY + y * innerDims.tileSize,
				innerDims.tileSize, innerDims.tileSize, col);

			if (withBorders) {

			}
		}
}

void Renderer::drawTileHighlighter(const UIElements::TileHighlighter& highlighter)
{
	Rectangle rec{ (float)highlighter.getX(), (float)highlighter.getY(), 
		(float)highlighter.getWidth(), (float)highlighter.getHeight() };
	const UIDescriptors::TileHighlighter& descriptor = *highlighter.getDescriptor();
	DrawRectangleLinesEx(rec, descriptor.thickness, toRaylibColor(descriptor.color));
}



