#include "Collectible.h"

void Collectible::Render(sf::RenderWindow& window)
{
 
    sf::CircleShape shape(10.0f);

    shape.setFillColor(m_Colour);
    shape.setPosition(m_Position);

    window.draw(shape);
}

void Collectible::Spawn(sf::Vector2f pos, sf::Color col)
{
    m_Position = pos;
    m_Colour = col;
    m_Score = rand() % 5 + 1;
    m_Alive = true;
    if (m_Score == 1)
    {
        m_Colour = sf::Color::Red;
    }
    if (m_Score == 2)
    {
        m_Colour = sf::Color::Blue;
    }
    if (m_Score == 3)
    {
        m_Colour = sf::Color::Cyan;
    }
    if (m_Score == 4)
    {
        m_Colour = sf::Color::Green;
    }
    if (m_Score == 5)
    {
        m_Colour = sf::Color::Magenta;
    }
}