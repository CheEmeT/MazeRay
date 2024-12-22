#ifndef MAZERAY_UIDESCRIPTORS
#define MAZERAY_UIDESCRIPTORS

namespace UIDescriptors {

	struct Color {
		uint8_t r;
		uint8_t g;
		uint8_t b;
		uint8_t a;
	};

	struct Box {
		Color fillColor;
		Color borderColor;
		uint32_t borderThickness;
	};

	struct Font {
		Color color;
		uint32_t size;
	};

	struct ButtonState {
		Box box;
		Font font;
	};

	struct Button {
		ButtonState idle;
		ButtonState hovered;
		ButtonState clicked;
	};

	inline UIDescriptors::Button DEFAULT_BUTTON_DESCRIPTOR = {
		.idle = {
			.box = {
				.fillColor = {222, 33, 20, 255},
				.borderColor = {0, 0, 0, 255},
				.borderThickness = 3
			},
			.font = {
				.color = {0, 0, 0, 255},
				.size = 40
			}
		},
		.hovered = {
			.box = {
				.fillColor = {48, 25, 224, 255},
				.borderColor = {0, 0, 0, 255},
				.borderThickness = 3
			},
			.font = {
				.color = {0, 0, 0, 255},
				.size = 45
			}
		},
		.clicked = {
			.box = {
				.fillColor = {214, 217, 30, 255},
				.borderColor = {0, 0, 0, 255},
				.borderThickness = 3
			},
			.font = {
				.color = {0, 0, 0, 255},
				.size = 40
			}
		}
	};
}


#endif // !MAZERAY_UIDESCRIPTORS
