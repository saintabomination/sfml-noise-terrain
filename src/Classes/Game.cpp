#include "../Headers/Game.h"

// Initialisers

void Game::initWindow()
{
  this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "SFML");
  this->window->setFramerateLimit(60);
  this->window->setVerticalSyncEnabled(false);
}

void Game::initWorld()
{
  for (int y = 0; y < 10; y++)
  {
    for (int x = 0; x < 10; x++)
    {
      this->world[y][x] = x % 2;
    }
  }
}

// Constructor and Destructor

Game::Game()
{
  this->initWindow();
  this->initWorld();
}

Game::~Game()
{
  delete this->window;
}

// Update Functions

void Game::updateSFMLEvents()
{
  while (this->window->pollEvent(this->sfEvent))
  {
    switch (this->sfEvent.type)
    {
      case sf::Event::Closed:
        this->window->close();
        break;

      default:
        break;
    }
  }
}

void Game::update()
{
  this->updateSFMLEvents();
}

// Render Functions

void Game::renderWorld()
{
  for (int y = 0; y < 10; y++)
  {
    for (int x = 0; x < 10; x++)
    {
      sf::RectangleShape tile(sf::Vector2f(10.f, 10.f));
      tile.setPosition(sf::Vector2f(x * 10.f, y * 10.f));

      if (world[y][x] == 1)
      {
        tile.setFillColor(sf::Color::Blue);
      }
      else
      {
        tile.setFillColor(sf::Color::Green);
      }

      this->window->draw(tile);
    }
  }
}

void Game::render()
{
  this->window->clear();
  this->renderWorld();
  this->window->display();
}

// Functions

void Game::run()
{
  while (this->window->isOpen())
  {
    this->update();
    this->render();
  }
}
