#include <Bomberman/Window/Helpers.hpp>
#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window( sf::VideoMode(800, 600), "Bomberman" );

	bmb::maximizeWindow(window);	

	while(window.isOpen())
	{
		sf::Event windowEvent;
		while (window.pollEvent(windowEvent))
		{
			if (windowEvent.type == sf::Event::Closed)
				window.close();
		}

		window.clear( { 44, 44, 44 } );

		window.display();
	}
}