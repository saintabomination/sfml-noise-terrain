#include "Headers.h"

int main()
{
  sf::RenderWindow window(sf::VideoMode(800, 600), "SFML");
  sf::Event sfEvent;
  sf::CircleShape shape(40.f);
  shape.setFillColor(sf::Color::Blue);

  while (window.isOpen())
  {
    while (window.pollEvent(sfEvent))
    {
      switch (sfEvent.type)
      {
        case sf::Event::Closed:
          window.close();
          break;

        default:
          break;
      }
    }

    window.clear();
    window.draw(shape);
    window.display();
  }

  return 0;
}
