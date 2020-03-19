#pragma once
#include "Framework/GameObject.h"
#include "Framework/TileMap.h"

class MapTiles
{
	private:
		TileMap tileMap;
		sf::RenderWindow* window;
		GameObject* player;

	public:
		MapTiles();
		~MapTiles();

		void setWindow(sf::RenderWindow* win);
		void setPlayer(GameObject* _player) { player = _player; };
		void update();
};

