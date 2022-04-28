#include "../Headers/Game.h"

// Initialisers

void Game::initWindow()
{
  std::string windowTitle = "SFML";
  unsigned int windowWidth = 400;
  unsigned int windowHeight = 300;
  unsigned int windowFPS = 60;

  std::ifstream configFile("src/Config/Window.ini");
  if (!configFile.is_open())
  {
    std::cout << "ERROR::GAME::CANT_LOAD_WINDOW_CONFIG" << std::endl;
  }
  else
  {
    configFile >> windowTitle >> windowWidth >> windowHeight >> windowFPS;
  }

  this->window = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight), windowTitle);
  this->window->setFramerateLimit(windowFPS);
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
