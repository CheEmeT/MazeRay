#ifndef MAZERAY_GLOBALS
#define MAZERAY_GLOBALS

#include "Application.h"
#include "UIDescriptors.h"

inline std::unique_ptr<Application> g_application;


inline UIDescriptors::Button g_mainMenuButtonsDscr{
	.idle{
		.box{
			.fillColor{ 235, 57, 45, 255 },
				.border{
					.color = {0, 0, 0, 255},
					.thickness = 3
				}
		},
		.font{
			.color { 0, 0, 0, 255 },
			.size = 80
		}
	},
	.hovered{
		.box{
			.fillColor{ 235, 83, 73, 255 },
				.border{
					.color = {0, 0, 0, 255},
					.thickness = 3
				}
		},
		.font{
			.color { 0, 0, 0, 255 },
			.size = 90
		}
	},
	.clicked{
		.box{
			.fillColor{ 240, 143, 137, 255 },
				.border{
					.color = {0, 0, 0, 255},
					.thickness = 3
				}
		},
		.font{
			.color { 0, 0, 0, 255 },
			.size = 80
		}
	}
};

inline UIDescriptors::Button g_editorButtonsDscr{
	.idle{
		.box{
			.fillColor{ 235, 57, 45, 255 },
				.border{
					.color = {0, 0, 0, 255},
					.thickness = 3
				}
		},
		.font{
			.color { 0, 0, 0, 255 },
			.size = 40
		}
	},
	.hovered{
		.box{
			.fillColor{ 235, 83, 73, 255 },
				.border{
					.color = {0, 0, 0, 255},
					.thickness = 3
				}
		},
		.font{
			.color { 0, 0, 0, 255 },
			.size = 45
		}
	},
	.clicked{
		.box{
			.fillColor{ 240, 143, 137, 255 },
				.border{
					.color = {0, 0, 0, 255},
					.thickness = 3
				}
		},
		.font{
			.color { 0, 0, 0, 255 },
			.size = 40
		}
	}
};

inline UIDescriptors::Border g_editorHighlighterDscr{
	.color = { 186, 142, 47, 255 },
	.thickness = 4
};


#endif // !MAZERAY_GLOBALS
