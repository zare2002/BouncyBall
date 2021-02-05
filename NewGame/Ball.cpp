#include "Ball.h"



Ball::Ball(float x, float y, float r, bool p, float v,float sx)
	: shape(r)
{
	physicalball = p;
	xpos = x;
	ypos = y;
	radius = r;
	speed = v;
	speed0 = v;
	y0 = y;
	h0 = y;
	n = 0;
	speedx = sx;
	
	//sf::CircleShape shape(20.f);
	shape.setFillColor(sf::Color(200, 240, 190));
	shape.setPosition(xpos, ypos);
	
}

Ball::~Ball() {
	std::cout << "bye bye" << std::endl;
}
sf::CircleShape Ball:: GetShape() {
	return shape;
}
void Ball::Move(sf::Event e) 
	
{
	
	
	if (e.type == sf::Event::KeyPressed) {
		if (e.key.code == sf::Keyboard::Left&&xpos >= 6.f) {
			speedx = -3.f;
			
		}
		
		if (e.key.code == sf::Keyboard::Right && xpos <=344.f) {
			speedx = 3.f;
			
		}
		if (e.key.code == sf::Keyboard::Up) {
			speed0 = 150.f;
			speed = 150.f;
			jump = true;
			n = 0;
		}
		
	}
	//std::cout << speedx << "!" << std::endl;
	shape.setPosition(xpos, ypos);
}
void Ball::Fall(float t, Environment env) {
	
	if (ypos <= 496.f && physicalball == false) {
		ypos += speed;
		
	}
	else if (ypos <= 496.f && physicalball == true) {
		ypos = y0 - speed * t + env.g*t*t;
		//std::cout << speed << "!" << std::endl;
	}
	
   
	
	else if (ypos > 496.f) {
		y0 = 496.f;
		ypos = 496.f;
		n += 1;
		if (jump != true) {
			speed = pow(env.collision_damp, n)*(abs(speed0) + sqrt(200.f*(496.f - h0)));
		}
		else if (jump == true) {
			speed = pow(env.collision_damp, n)*(abs(speed0));
			std::cout << speed << "!!" <<n<< std::endl;
		}
		
		//std::cout << speed << "!!" <<n<< std::endl;
		if (speed < 5.f) {
			speed = 0.f;
		}
		//std::cout << y0<<"!!!" << std::endl;
	}
	if (xpos < 6) {
		xpos = 6.f;
		speedx = -speedx*0.8f;
	}
	else if (xpos > 344.f) {
		speedx = -speedx*0.8f;
		xpos = 344.f;
	}
	if (ypos == 496) {
		speedx -= env.friction*speedx;
	}
	if (speedx < 0.01f) {
		speedx == 0;
	}
	xpos += speedx;
	shape.setPosition(xpos, ypos);
}
