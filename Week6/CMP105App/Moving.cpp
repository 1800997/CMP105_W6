#include "Moving.h"

Moving::Moving()
{
	speed = 10.f;
	acceleration = 5.f;

};

Moving::~Moving()
{



};

void Moving::update(float dt)
{
	target = sf::Vector2f(input->getMouseX()-25, input->getMouseY()-25);
	direction = target - getPosition();
	direction = Vector::normalise(direction);
	velocity += (direction * acceleration) * dt;
	setPosition(getPosition() + (velocity * dt));

	if (Vector::magnitude(target - getPosition()) < 55.f)
	{
		setPosition(target);
	}

	if (velocity.y > 500 && velocity.x > 500)
	{
		velocity = sf::Vector2f(500, 500);
	}

	if (getPosition() == target)
	{
		velocity = sf::Vector2f(0,0);
		acceleration = 10.f;
	}
	acceleration++;
};
