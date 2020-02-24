#pragma once
#include "Framework/Vector.h"
#include "Framework/GameObject.h"
class Moving: public GameObject
{
public:
	Moving();
	~Moving();

	float speed, acceleration;
	sf::Vector2f target;
	sf::Vector2f direction;
	void update(float);

};

