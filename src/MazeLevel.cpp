#include <filesystem>
#include <fstream>

#include "MazeLevel.h"
#include "Globals.h"
#include <bitset>

MazeLevel::MazeLevel(){
	clearLevel(1);
}

void MazeLevel::clearLevel(uint8_t v){
	for (size_t y = 0; y < m_height; y++)
		for (size_t x = 0; x < m_width; x++)
		{
			if (x == 0 || y == 0 || x == m_width - 1 || y == m_height - 1)
				m_levelData[x + y * m_width] = 0;
			else
			m_levelData[x + y * m_width] = v;
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

bool MazeLevel::isBorder(uint32_t x, uint32_t y) const
{
	return x == 0 || y == 0 || x == m_width - 1 || y == m_height - 1;
}

bool saveLevel(const MazeLevel& level, std::string& fileName)
{
	std::ofstream file{ fileName, std::ios::binary | std::ios::out};
	if (!file.is_open())
		return false;

	//Level size information
	file << level.getWidth() << level.getHeight();

	//Level data
	size_t size = level.getWidth() * level.getHeight();
	auto& data = level.getLevelData();

	uint8_t byteToSave = 0;

	for (size_t i = 0; i < size; i++)
	{
		if (i != 0 && i % 8 == 0) {
			file << byteToSave;
			byteToSave = 0;
		}
		byteToSave |= data[i] << (i % 8); 
	}

	//Checking if last byte should be written
	if (size % 8 != 0)
		file << byteToSave;

	return true;
}

bool loadLevel(MazeLevel& loadTo, const std::string& fileName)
{
	std::ifstream file{ fileName, std::ios::binary | std::ios::in };
	if (!file.is_open())
		return false;

	file >> loadTo.m_width >> loadTo.m_height;

	size_t size = loadTo.m_width * loadTo.m_height;

	uint8_t byteToRead = 0;

	for (size_t i = 0; i < size; i++)
	{
		if (i % 8 == 0) {
			file >> byteToRead;
		}
		loadTo.m_levelData[i] = (byteToRead >> (i % 8)) & 1Ui8;
	}

	return true;
}
