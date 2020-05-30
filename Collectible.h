#pragma once
#include <SFML/Graphics.hpp>

class Collectible
{
private:
	sf::Vector2f m_Position;
	sf::Color m_Colour;
	int m_Score{ 0 };
	bool m_Alive{ false };
public:
	bool IsAlive() const { return m_Alive; }
	void Render(sf::RenderWindow& window);
	void Spawn(sf::Vector2f pos, sf::Color col);
};