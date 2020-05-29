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
	sf::Color m_Color;
	eDirection m_Direction{ eDirection::eNorth };
	int m_GrowAmount{ 4 };
public:
	Snake(sf::Vector2f pos, sf::Color col);
	void ChangeDirection(eDirection newDirection);
	void Update();
	void Render(sf::RenderWindow& window);
	void Eat();
	bool CheckCollision(Snake& other);
};