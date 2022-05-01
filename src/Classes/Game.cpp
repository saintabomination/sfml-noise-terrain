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
  float NOISE_SCALE_X = 0.01f;
  float NOISE_SCALE_Y = 0.01f;
  unsigned int NOISE_OCTAVES = 2;

  std::ifstream configFile("src/Config/Noise.ini");
  if (!configFile.is_open())
  {
    std::cout << "ERROR::GAME::CANT_LOAD_NOISE_CONFIG" << std::endl;
  }
  else
  {
    configFile >> NOISE_SCALE_X >> NOISE_SCALE_Y >> NOISE_OCTAVES;
  }

  for (int y = 0; y < 600; y++)
  {
    for (int x = 0; x < 800; x++)
    {
      this->world[y][x] = (float)(perlin.octave2D_01(x * NOISE_SCALE_X, y * NOISE_SCALE_Y, NOISE_OCTAVES));
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
  for (int y = 0; y < 600; y++)
  {
    for (int x = 0; x < 800; x++)
    {
      sf::RectangleShape tile(sf::Vector2f(1.f, 1.f));
      tile.setPosition(sf::Vector2f(x, y));

      if (world[y][x] < 0.2f)
      {
        tile.setFillColor(sf::Color(14, 37, 107));
      }
      else if (world[y][x] < 0.45f)
      {
        tile.setFillColor(sf::Color(20, 52, 150));
      }
      else if (world[y][x] < 0.5f)
      {
        tile.setFillColor(sf::Color(199, 201, 68));
      }
      else if (world[y][x] < 0.6f)
      {
        tile.setFillColor(sf::Color(41, 135, 71));
      }
      else if (world[y][x] < 0.75f)
      {
        tile.setFillColor(sf::Color(21, 89, 43));
      }
      else if (world[y][x] < 0.85f)
      {
        tile.setFillColor(sf::Color(140, 140, 140));
      }
      else if (world[y][x] < 0.95f)
      {
        tile.setFillColor(sf::Color(170, 170, 170));
      }
      else {
        tile.setFillColor(sf::Color(240, 240, 240));
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
