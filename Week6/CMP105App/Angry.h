#pragma once
#include "Framework/GameObject.h"
#include "Framework/Vector.h"
class Angry: public GameObject
{
public:
	Angry();
	~Angry();

	float scale, speed, acceleration;
	sf::Vector2f gravity;
	int x, y, x1, y1;
	bool mouseDown = false;
	bool throwBird=false;
	void update(float,int,int);
	void handleInput(float);
};

