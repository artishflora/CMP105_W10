#include "Player.h"

Player::Player()
{
	speed = 50.f;
	gravity = sf::Vector2f(0, 9.8f) * speed * 0.5f;

	walk.addFrame(sf::IntRect(0, 0, 55, 108));
	walk.addFrame(sf::IntRect(55, 0, 55, 108));
	walk.addFrame(sf::IntRect(110, 0, 55, 108));
	walk.addFrame(sf::IntRect(165, 0, 55, 108));
	walk.addFrame(sf::IntRect(220, 0, 55, 108));
	walk.addFrame(sf::IntRect(275, 0, 55, 108));
	walk.addFrame(sf::IntRect(330, 0, 55, 108));
	walk.addFrame(sf::IntRect(385, 0, 55, 108));
	walk.setFrameSpeed(1.f / 10.f);

	currentAnimation = &walk;
	setTextureRect(currentAnimation->getCurrentFrame());

	setCollider(true);
	setCollisionBox(20, 0, 35, 98);
}

Player::~Player()
{

}

void Player::update(float dt)
{
	sf::Vector2f pos = stepVelocity * dt + 0.5f * gravity * dt * dt;
	stepVelocity += gravity * dt * 1.3f;
	setPosition(getPosition() + pos);

	if (getPosition().y >= window->getSize().y) setPosition(0, 0);
	if (!input->isKeyDown(sf::Keyboard::Up))
	{
		if (input->isKeyDown(sf::Keyboard::Right))
		{
			currentAnimation = &walk;
			currentAnimation->setFlipped(false);
			setTextureRect(currentAnimation->getCurrentFrame());

			currentAnimation->animate(dt);
			setTextureRect(currentAnimation->getCurrentFrame());
		}
		if (input->isKeyDown(sf::Keyboard::Left))
		{
			currentAnimation = &walk;
			currentAnimation->setFlipped(true);
			setTextureRect(currentAnimation->getCurrentFrame());

			currentAnimation->animate(dt);
			setTextureRect(currentAnimation->getCurrentFrame());
		}
	}
}

void Player::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Left))
	{
		if (getPosition().x > 0) move(-(speed * dt * 1.4f), 0);
	}
	if (input->isKeyDown(sf::Keyboard::Right))
	{
		if (getPosition().x < window->getSize().x - getSize().x) move((speed * dt * 1.4f), 0);
	}
	if (input->isKeyDown(sf::Keyboard::Up))
	{
		if (getPosition().y > 0)
		{
			move(0, -(speed * dt * 8));
		}
	}
	if (input->isKeyDown(sf::Keyboard::Down))
	{
		if (getPosition().y < window->getSize().y - getSize().y) move(0, (speed * dt));
	}
}

void Player::collisionResponse(GameObject* collider)
{
	stepVelocity = sf::Vector2f(0, 0);
	velocity.y = 0;
	setPosition(getPosition().x, collider->getPosition().y - getCollisionBox().height);
}