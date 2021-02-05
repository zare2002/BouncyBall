#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <windows.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include<fstream>
#include "Ball.h"
unsigned int WindowWidth = 350;
unsigned int WindowHeight = 500;
//sf::CircleShape shape1;
float t=0.f;



int main() {
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::Clock clock;
	sf::RenderWindow window(sf::VideoMode(WindowWidth, WindowHeight), "NewGame", sf::Style::Default, settings);
	window.setKeyRepeatEnabled(false);
	window.setVerticalSyncEnabled(true);
	Ball ball1(30.f, 450.f, 2.f, true, 0.f, 0.f);
	Environment e(0.01f, 0.7f, 60.f);
	while (window.isOpen()) {
		sf::Vector2f position = ball1.GetShape().getPosition();
		t = clock.getElapsedTime().asSeconds();
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
			ball1.Move(event);
		}
		if (position.y > 495.99f) {
			 clock.restart();
		}
		ball1.Fall(t,e);
		window.clear(sf::Color::Black);
		window.draw(ball1.GetShape());
		window.display();
		
	}

	return 0;
}
