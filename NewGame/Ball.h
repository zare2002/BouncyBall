#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include<iostream>
#include <ctime>
#include<cmath>
#include "environment.h"





class Ball {
private:
	bool jump;
	bool physicalball;
	float xpos;
	float ypos;
	float y0;
	float radius;
	float speed;
    float speed0;
	float h0;
	int n;
	float speedx;
	sf::CircleShape shape;
	
	
public:
	
	 Ball(float x, float y, float r, bool p, float v, float sx);
	~Ball();
	
	sf::CircleShape GetShape();
    void Move(sf::Event e);
	void Fall(float t, Environment env);
	
};
