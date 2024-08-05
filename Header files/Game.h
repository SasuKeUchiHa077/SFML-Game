#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include <vector>

/*
- Class which acts as game engine.
- Wrapper class.
*/

class Game {
private:
    //Variables 
    sf::RenderWindow *window;
    sf::VideoMode videoMode;
    sf::Event event;

    //Mouse position
    sf::Vector2i mousePosition;

    //Game logic
    int points;
    float enemySpawnTimer;
    float enemySpawnTimerMax ;
    int maxEnemies;

    //Game objects
    std::vector<sf::RectangleShape> enemies;
    sf::RectangleShape enemy;

    //Private Functions
    void InitVariables();
    void InitWindow();
    void InitEnemy();

public:
    //Constructor/destructor
    Game();
    ~Game();

    //Accessors
    bool const Running() const;

    //Public Functions------------------]
    void PollEvents();

    //Update Functions
    void UpdateMousePosition();
    void UpdateEnemy();
    void Update();

    //Render functions
    void RenderEnemy();
    void Render();
};

#endif // !GAME_H
