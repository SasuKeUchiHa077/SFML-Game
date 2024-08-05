#include "Header files/Game.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/WindowStyle.hpp>
//gu
//Private Functions---------------------------------------
void Game::InitVariables() {
    //window variable
    this->window = nullptr;

    //Game logic variables
    this->points = 0;
    this->enemySpawnTimerMax = 1000.f;
    this->enemySpawnTimer = this->enemySpawnTimerMax;
    this->maxEnemies = 5;
}

void Game::InitWindow() {
    this->videoMode.width = 800;
    this->videoMode.height = 600;
    
    this->window = new sf::RenderWindow(videoMode, "Game", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(60);
}

void Game::InitEnemy() {
    const float enemySize = 50.f;
    this->enemy.setSize(sf::Vector2f(enemySize, enemySize));
    this->enemy.setFillColor(sf::Color::Cyan);
    this->enemy.setOutlineColor(sf::Color::Red);
    this->enemy.setOutlineThickness(2.f);
}

//Public Functions---------------------------------------
bool const Game::Running() const {
    return  this->window->isOpen();
}

//Main game Functions
void Game::PollEvents() {
    while (this->window->pollEvent(this->event)) {
        if (this->event.type == sf::Event::Closed) {
            this->window->close();
        }
    }
}

void Game::UpdateMousePosition() {
    /* Fuction to Update Mouse Position
    */

    this->mousePosition = sf::Mouse::getPosition(*this->window);
}

void Game::UpdateEnemy() {
    //Update Enemies
}

void Game::Update() {
    this->PollEvents();
    this->UpdateMousePosition();
    this->UpdateEnemy();
}

void Game::RenderEnemy() {
    //Render Enemies
}

void Game::Render() {
    this->window->clear();
    this->RenderEnemy();
    this->window->display();
}

//Contructor/Distructor---------------------------------------
Game::Game() {
    this->InitVariables();
    this->InitWindow();
    this->InitEnemy();
}

Game::~Game() {
    delete this->window;
}
