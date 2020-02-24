#include "Angry.h"

Angry::Angry()
{
	scale = 200.0f;
	gravity = sf::Vector2f(0, 9.8f) * scale;

};

Angry::~Angry()
{



};

void Angry::update(float dt,int maxY,int maxX)
{

	if (throwBird)
	{

		sf::Vector2f pos = velocity * dt + 0.5f * gravity * dt * dt;
		velocity += gravity * dt;
		setPosition(getPosition() + pos);

		if (getPosition().y >= maxY - 100)
		{
			setPosition(getPosition().x, maxY - 100);
			velocity.y = (-velocity.y) / 1.2f;
		}

		if (getPosition().x >= maxX - 100)
		{
			setPosition(maxX - 100, getPosition().y);
			velocity.x = (-velocity.x)/1.8f;
		}

		if (getPosition().y <= 0)
		{
			setPosition(getPosition().x, 0);
			velocity.y = (-velocity.y);
		}

		if (getPosition().x <= 0)
		{
			setPosition(0, getPosition().y);
			velocity.x = (-velocity.x)/1.8f;
		}
	}

};

void Angry::handleInput(float dt)
{
	

	if (input->isMouseLDown()&& !mouseDown)
	{
		x = input->getMouseX();
		y = input->getMouseY();
		mouseDown = true;
	}

	if (input->isMouseLDown())
	{
		int x2 = input->getMouseX();
		int y2 = input->getMouseY();
		setPosition(sf::Vector2f(x2-40, y2-40));
	}

	if (!input->isMouseLDown() && mouseDown)
	{
		x1 = input->getMouseX();
		y1 = input->getMouseY();
		mouseDown = false;
		throwBird = true;
		velocity.x = (x - x1)*15;
		velocity.y = (y - y1)*15;
	}


};