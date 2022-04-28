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
  const siv::PerlinNoise perlin;

  for (int y = 0; y < 120; y++)
  {
    for (int x = 0; x < 160; x++)
    {
      this->world[y][x] = (float)(perlin.octave2D_01(x * 0.1f, y * 0.1f, 4));
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
  for (int y = 0; y < 120; y++)
  {
    for (int x = 0; x < 160; x++)
    {
      sf::RectangleShape tile(sf::Vector2f(5.f, 5.f));
      tile.setPosition(sf::Vector2f(x * 5.f, y * 5.f));

      if (world[y][x] > 0.5f)
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
