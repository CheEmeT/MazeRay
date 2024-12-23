#ifndef MAZERAY_MAZELEVEL
#define MAZERAY_MAZELEVEL

#include <cstdint>
#include <array>

inline constexpr uint8_t MAX_MAZE_SIZE = 30;

class MazeLevel {
public:
	MazeLevel();

	void clearLevel();
	void tileLevel();

	uint8_t getWidth() const { return m_width; };
	uint8_t getHeight() const { return m_height; };
	uint8_t getTile(uint32_t x, uint32_t y) { return m_levelData.at(x + y * m_width); }
	void setTile(uint32_t x, uint32_t y, uint8_t v);
	const std::array<uint8_t, MAX_MAZE_SIZE* MAX_MAZE_SIZE>& getLevelData() const { return m_levelData; }

	bool isBorder(uint32_t x, uint32_t y);

private:
	uint8_t m_width = MAX_MAZE_SIZE;
	uint8_t m_height = MAX_MAZE_SIZE;
	std::array<uint8_t, MAX_MAZE_SIZE * MAX_MAZE_SIZE> m_levelData;
};

#endif // !MAZERAY_MAZELEVEL
