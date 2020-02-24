#include "Zombie.h"

Zombie::Zombie()
{
	walk.addFrame(sf::IntRect(0, 0, 55, 108));
	walk.addFrame(sf::IntRect(55, 0, 55, 108));
	walk.addFrame(sf::IntRect(111, 0, 55, 108));
	walk.addFrame(sf::IntRect(165, 0, 55, 108));
	walk.addFrame(sf::IntRect(220, 0, 55, 108));
	walk.addFrame(sf::IntRect(275, 0, 55, 108));
	walk.addFrame(sf::IntRect(330, 0, 55, 108));
	walk.addFrame(sf::IntRect(385, 0, 55, 108));
	walk.setFrameSpeed(0.1);
}

Zombie::~Zombie()
{

}

void Zombie::handleInput(float dt)
{
	velocity.x = 0;
	if (input->isKeyDown(sf::Keyboard::Left))
	{
		walk.setFlipped(true);
		walk.animate(dt);
		velocity.x = -250;
	}

	if (input->isKeyDown(sf::Keyboard::Right))
	{
		walk.setFlipped(false);
		walk.animate(dt);
		velocity.x = 250;
	}
}

void Zombie::update(float dt)
{
	setTextureRect(walk.getCurrentFrame());
	move(velocity*dt);
}