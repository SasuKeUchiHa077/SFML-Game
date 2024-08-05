#include "Header files/Game.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/WindowStyle.hpp>

//Private Functions---------------------------------------
void Game::InitVariables() {
    this->window = nullptr;
}

void Game::InitWindow() {
    this->videoMode.width = 800;
    this->videoMode.height = 600;
    
    this->window = new sf::RenderWindow(videoMode, "Game", sf::Style::Titlebar | sf::Style::Close);
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

void Game::Update() {
    this->PollEvents();
}

void Game::Render() {
    this->window->clear();
    this->window->draw(this->enemy);
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
