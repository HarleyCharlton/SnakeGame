#include "Snake.h"

constexpr float kStepSize{ 20.0f };

Snake::Snake(sf::Vector2f pos, sf::Color col) : m_Color(col)
{
    m_Segments.push_back(pos);

    m_Direction = (eDirection)(rand() % 4);
}

void Snake::Render(sf::RenderWindow& window)
{
    sf::CircleShape shape(kStepSize/2.0f); //Makes sure the size of the snakes head is always the same as how much it moves.
    shape.setFillColor(m_Color);
    for (sf::Vector2f pos: m_Segments)
    {
        shape.setPosition(pos);
        window.draw(shape);
    }
}

void Snake::ChangeDirection(eDirection newDirection)
{
    m_Direction = newDirection;
}

void Snake::Update()
{
    sf::Vector2f pos = m_Segments.front();

    switch (m_Direction)
    {
    case eDirection::eNorth:
        pos.y -= kStepSize;
        break;
    case eDirection::eEast:
        pos.x += kStepSize;
        break;
    case eDirection::eSouth:
        pos.y += kStepSize;
        break;
    case eDirection::eWest:
        pos.x -= kStepSize;
        break;
    default:
        break;
    }

    m_Segments.push_front(pos);
    if (m_GrowAmount == 0)
        m_Segments.pop_back();
    else
        m_GrowAmount--;
}

