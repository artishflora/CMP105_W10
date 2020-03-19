#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	player.setWindow(window);
	player.setInput(input);
	playerWalk.loadFromFile("gfx/animZombie.png");
	player.setSize(sf::Vector2f(55, 108));
	player.setPosition(0, 0);
	player.setTexture(&playerWalk);

	mapTiles.setPlayer(&player);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	player.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	player.update(dt);
	mapTiles.update();
}

// Render level
void Level::render()
{
	beginDraw();

	mapTiles.setWindow(window);
	window->draw(player);

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