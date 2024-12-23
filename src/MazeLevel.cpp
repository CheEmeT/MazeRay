#include "MazeLevel.h"


MazeLevel::MazeLevel(){
	clearLevel();
}

void MazeLevel::clearLevel(){
	for (size_t y = 0; y < m_height; y++)
		for (size_t x = 0; x < m_width; x++)
		{
			if (x == 0 || y == 0 || x == m_width - 1 || y == m_height - 1)
				m_levelData[x + y * m_width] = 0;
			else
			m_levelData[x + y * m_width] = 1;
		}
}

void MazeLevel::tileLevel(){
	for (size_t i = 0; i < MAX_MAZE_SIZE * MAX_MAZE_SIZE; i++) {
		if (i / m_width == 0 || i / m_width == m_width - 1 || i % m_height == 0 || i % m_height == m_height - 1)
			continue;
		uint8_t s = (i / m_width + i) % 2;
		m_levelData[i] = s;
	}
}

void MazeLevel::setTile(uint32_t x, uint32_t y, uint8_t v)
{
	if (x == 0 || y == 0 || x == m_width - 1 || y == m_height - 1)
		return;
	m_levelData.at(x + y * m_width) = v;
}

bool MazeLevel::isBorder(uint32_t x, uint32_t y)
{
	return x == 0 || y == 0 || x == m_width - 1 || y == m_height - 1;
}
