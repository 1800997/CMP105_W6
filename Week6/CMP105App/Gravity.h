#pragma once
#include <SFML/Graphics.hpp>
#include "Framework/GameObject.h"
class Gravity: public GameObject
{
public:
	Gravity();
	~Gravity();

	float scale;
	sf::Vector2f jumpVector;
	bool isJumping;
	sf::Vector2f gravity;
	void update(float,int);
	void handleInput(float);

};

