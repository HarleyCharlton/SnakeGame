#include "Collectible.h"

void Collectible::Render(sf::RenderWindow& window)
{
 
    sf::CircleShape shape(10.0f);

    shape.setFillColor(sf::Color::Red);
    shape.setPosition(m_Position);

    window.draw(shape);
}

void Collectible::Spawn(sf::Vector2f pos)
{
    m_Position = pos;
    m_Score = rand() % 5 + 1;
    m_Alive = true;
    if (m_Score == 1)
    {
        sf::Color::Red;
    }
    if (m_Score == 2)
    {
        sf::Color::Blue;
    }
    if (m_Score == 3)
    {
        sf::Color::Cyan;
    }
    if (m_Score == 4)
    {
        sf::Color::Green;
    }
    if (m_Score == 5)
    {
        sf::Color::Magenta;
    }



}