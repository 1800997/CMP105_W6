#include "Gravity.h"

Gravity::Gravity()
{
	scale = 200.0f;
	gravity = sf::Vector2f(0, 9.8f) * scale;
	jumpVector = sf::Vector2f(0, -7.0f) * scale; 
	isJumping = false;
};

Gravity::~Gravity()
{



};


void Gravity::update(float dt, int maxY)
{

	sf::Vector2f pos = velocity * dt + 0.5f * gravity * dt * dt;
	velocity += gravity * dt;
	setPosition(getPosition() + pos);

	if (getPosition().y >= maxY-100)
	{
		isJumping = false;
		setPosition(getPosition().x, maxY-100);
		velocity = sf::Vector2f(0, 0);
	}


};

void Gravity::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Space)) 
	{ 
		if (!isJumping) 
		{ 
			velocity = jumpVector;
			isJumping = true; 
		} 
	}

	if (input->isMouseLDown())
	{
		
		setPosition(input->getMouseX()-50, input->getMouseY()-50);
	}
};