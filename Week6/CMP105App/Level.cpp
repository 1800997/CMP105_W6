#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	
	
	gravityBallTexture.loadFromFile("gfx/Beach_Ball.png");
	gravityBall.setTexture(&gravityBallTexture);

	gravityBall.setSize(sf::Vector2f(100,100));
	gravityBall.setPosition(10, 10);
	gravityBall.setInput(in);

	movingBallTexture.loadFromFile("gfx/MushroomTrans.png");
	movingBall.setTexture(&movingBallTexture);

	movingBall.setSize(sf::Vector2f(50, 50));
	movingBall.setPosition(0, 0);
	movingBall.setInput(in);
	
	angryMumTexture.loadFromFile("gfx/Mum.png");
	angryMum.setTexture(&angryMumTexture);

	angryMum.setSize(sf::Vector2f(580/4.8, 643/4.8)); //580 x 643
	angryMum.setPosition(200, 380);
	angryMum.setInput(in);
	
	backroundTexture.loadFromFile("gfx/Backround.jpg");
	backround.setTexture(&backroundTexture);

	backround.setSize(sf::Vector2f(1440/0.7, 900/0.7));
	backround.setPosition(-100,-350);


}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	gravityBall.handleInput(dt);
	angryMum.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	windowY = window->getSize().y;
	windowX = window->getSize().x;
	gravityBall.update(dt, windowY);
	movingBall.update(dt);
	angryMum.update(dt, windowY,windowX);
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(backround);
	//window->draw(gravityBall);
	//window->draw(movingBall);
	window->draw(angryMum);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}