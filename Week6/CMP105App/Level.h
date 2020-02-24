#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include <string.h>
#include <iostream>
#include "Gravity.h"
#include "Moving.h"
#include "Angry.h"
#include "Backround.h"


class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float dt);
	void update(float dt);
	void render();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;

	// More level variables
	int windowY,windowX;
	Gravity gravityBall;
	sf::Texture gravityBallTexture;

	Moving movingBall;
	sf::Texture movingBallTexture;

	Angry angryMum;
	sf::Texture angryMumTexture;

	Backround backround;
	sf::Texture backroundTexture;
};