#ifndef GAME_H
#define GAME_H

#include "../Headers.h"

class Game {
  private:
    sf::RenderWindow* window;
    sf::Event sfEvent;
    int world[10][10];

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
