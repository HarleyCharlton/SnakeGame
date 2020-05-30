#pragma once
#include <SFML/Graphics.hpp>
#include <list>

enum class eDirection
{
	eNorth,
	eEast,
	eSouth,
	eWest,
};

class Snake
{
private:
	std::list<sf::Vector2f> m_Segments;
	sf::Color m_SColor;
	eDirection m_Direction{ eDirection::eNorth };
	int m_GrowAmount{ 4 };
public:
	Snake(sf::Vector2f pos, sf::Color col);
	void ChangeDirection(eDirection newDirection);
	void Update();
	void Render(sf::RenderWindow& window);
	const std::list<sf::Vector2f>& GetSegments()
	{
		return m_Segments;
	}
	bool CheckCollision(Snake& otherSnake);
};

