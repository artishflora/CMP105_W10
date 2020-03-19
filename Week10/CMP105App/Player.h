#pragma once
#include "Framework/GameObject.h"
#include "Framework/Animation.h"

class Player :
	public GameObject
{
	private:
		float speed; 
		sf::Vector2f gravity;
		sf::Vector2f stepVelocity;

		Animation walk;
		Animation* currentAnimation;
		sf::RenderWindow* window;

	public:
		Player();
		~Player();

		void handleInput(float dt) override;
		void update(float dt) override;
		void setWindow(sf::RenderWindow* win) { window = win; };
		void collisionResponse(GameObject* collider) override;
};

