#ifndef MAZERAY_UIDESCRIPTORS
#define MAZERAY_UIDESCRIPTORS

namespace UIDescriptors {

	struct Color {
		uint8_t r;
		uint8_t g;
		uint8_t b;
		uint8_t a;
	};

	inline const Color Black	= { 0, 0, 0, 255 };
	inline const Color White	= { 255, 255, 255, 255 };
	inline const Color Red		= { 240, 30, 30, 255 };

	struct Border {
		Color color;
		uint8_t thickness;
	};

	struct Box {
		Color fillColor;
		Border border;
	};


	struct Font {
		Color color;
		uint32_t size;
	};

	struct ButtonState {
		Box box;
		Font font;
	};

	struct Level {
		Color background;
	};

	struct Button {
		ButtonState idle;
		ButtonState hovered;
		ButtonState clicked;
	};

	typedef Border TileHighlighter;

	inline Button DEFAULT_BUTTON_DESCRIPTOR = {
		.idle = {
			.box = {
				.fillColor = {222, 33, 20, 255},
				.border{
					.color = {0, 0, 0, 255},
					.thickness = 3
				}
			},
			.font = {
				.color = {0, 0, 0, 255},
				.size = 40
			}
		},
		.hovered = {
			.box = {
				.fillColor = {48, 25, 224, 255},
				.border{
					.color = {0, 0, 0, 255},
					.thickness = 3
				}
			},
			.font = {
				.color = {0, 0, 0, 255},
				.size = 45
			}
		},
		.clicked = {
			.box = {
				.fillColor = {214, 217, 30, 255},
				.border{
					.color = {0, 0, 0, 255},
					.thickness = 3
				}
			},
			.font = {
				.color = {0, 0, 0, 255},
				.size = 40
			}
		}
	};

	inline Level DEFAULT_LEVEL_DESCRIPTOR = {
		.background{ 165, 165, 165, 255 },
	};

	inline TileHighlighter DEFAULT_TILEHIGHLIGHTER_DESCRIPTOR{
		.color{ 186, 142, 47, 255 },
		.thickness = 3
	};
}

#endif // !MAZERAY_UIDESCRIPTORS
