#include "Game.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Snake.h"
#include <time.h>
using namespace std;

void Game::run()
{
   // All SFML types and functions are contained in the sf namespace
    srand(static_cast<unsigned int>(time(0))); // Stops things spawning in same place every time
   // Create an instance of the SFML RenderWindow type which represents the display
   // and initialise its size and title text
    sf::RenderWindow window(sf::VideoMode(800, 600), "C++ Snake ICA : W9049120");

    // We can still output to the console window
    std::cout << "SnakeGame: Starting" << std::endl;

    vector<Snake*> snakes;
    
    for (int i = 0; i < 2; i++)
    {
        sf::Vector2f pos;
        pos.x = (float)(rand() % 40) * 20;
        pos.y = (float)(rand() % 30) * 20;
        snakes.push_back(new Snake(pos, sf::Color::Red));
    }

    sf::Clock clock;

    // Main loop that continues until we call window.close()
    while (window.isOpen())
    {
        // Handle any pending SFML events
        // These cover keyboard, mouse,joystick etc.
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            break;
            case sf::Event::KeyPressed:
                switch (event.key.code)
                {
                case sf::Keyboard::W:
                    snakes.front()->ChangeDirection(eDirection::eNorth);
                    break;
                case sf::Keyboard::D:
                    snakes.front()->ChangeDirection(eDirection::eEast);
                    break;
                case sf::Keyboard::S:
                    snakes.front()->ChangeDirection(eDirection::eSouth);
                    break;
                case sf::Keyboard::A:
                    snakes.front()->ChangeDirection(eDirection::eWest);
                break;
                }
            break;
            default:
                break;
            }
        }

        // SIM
        for (Snake* s : snakes)
            s->Update();

        if (rand() % 10 == 5)
        {
            for (int i = 0; i < 5; i++)
            {
                if (!m_Food[i].IsAlive())
                {
                    sf::Vector2f pos;

                    pos.x = (float)(rand() % 40) * 20;
                    pos.y = (float)(rand() % 30) * 20;

                    m_Food[i].Spawn(pos);
                    break;
                }
            }
        }

        // VIS
        // We must clear the window each time around the loop
        window.clear();

        for (Snake* s : snakes)
            s->Render(window);

        for (int i = 0; i < 5; i++)
        {
            if (m_Food[i].IsAlive())
                m_Food[i].Render(window);
        }

        // Get the window to display its contents
        window.display();

        while (clock.getElapsedTime().asMilliseconds() < 500);
        clock.restart();
    }

    std::cout << "SnakeGame: Finished" << std::endl;

    for (Snake* s : snakes)
        delete s;
}