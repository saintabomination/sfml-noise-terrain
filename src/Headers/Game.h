#ifndef GAME_H
#define GAME_H

#include "../Headers.h"

class Game {
  private:
    sf::RenderWindow* window;
    sf::Event sfEvent;

    // Initialisers
    void initWindow();

  public:
    // Constructor
    Game();

    // Update Functions
    void updateSFMLEvents();
    void update();

    // Render Functions
    void render();

    // Functions
    void run();
};

#endif // GAME_H
