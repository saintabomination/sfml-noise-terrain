#ifndef GAME_H
#define GAME_H

#include "../Headers.h"
#include "PerlinNoise.hpp"

class Game {
  private:
    sf::RenderWindow* window;
    sf::Event sfEvent;
    float world[160][120];

    // Initialisers
    void initWindow();
    void initWorld();

  public:
    // Constructor and Destructor
    Game();
    virtual ~Game();

    // Update Functions
    void updateSFMLEvents();
    void update();

    // Render Functions
    void renderWorld();
    void render();

    // Functions
    void run();
};

#endif // GAME_H
