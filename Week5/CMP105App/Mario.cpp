#include "Mario.h"

Mario::Mario()
{
	animation = &walk;
	crouched = false;
	swimming = false;

	walk.addFrame(sf::IntRect(0, 0, 15, 21));
	walk.addFrame(sf::IntRect(15, 0, 15, 21));
	walk.addFrame(sf::IntRect(30, 0, 15, 21));
	walk.addFrame(sf::IntRect(45, 0, 15, 21));
	walk.setFrameSpeed(0.1);

	swim.addFrame(sf::IntRect(0, 21, 16, 20));
	swim.addFrame(sf::IntRect(16, 21, 16, 20));
	swim.addFrame(sf::IntRect(32, 21, 16, 20));
	swim.setFrameSpeed(0.1);

	crouch.addFrame(sf::IntRect(16, 41, 16, 20));
	crouch.addFrame(sf::IntRect(0, 41, 16, 20));
	crouch.setFrameSpeed(0.1);
	crouch.setLooping(false);
}

Mario::~Mario()
{

}

void Mario::handleInput(float dt)
{
	velocity.x = 0;
	if (input->isKeyDown(sf::Keyboard::Left))
	{
		animation = &walk;
		animation->setFlipped(true);
		velocity.x = -250;
		setSize(sf::Vector2f(15, 21));
		animation->animate(dt);
	}

	if (input->isKeyDown(sf::Keyboard::Right))
	{
		animation = &walk;
		animation->setFlipped(false);
		velocity.x = 250;
		setSize(sf::Vector2f(15, 21));
		animation->animate(dt);
	}

	if (input->isKeyDown(sf::Keyboard::Down) && crouched == false)
	{
		bool flip = animation->getFlipped();
		animation = &crouch;
		animation->setFlipped(flip);
		velocity.x = 0;
		setSize(sf::Vector2f(16, 20));
		move(0, 1);
		animation->animate(dt);
		animation->reset();
		crouched = true;
	}
	
	if (!input->isKeyDown(sf::Keyboard::Down) && crouched == true)
	{
		animation = &walk;
		animation->reset();
		setSize(sf::Vector2f(15, 21));
		move(0, -1);
		crouched = false;
	}

	if (input->isKeyDown(sf::Keyboard::Space))
	{
		bool flip = animation->getFlipped();
		animation = &swim;
		animation->setFlipped(flip);
		velocity.x = 0;
		setSize(sf::Vector2f(16, 20));
		animation->animate(dt);
		swimming = true;
	}
	
	if (!input->isKeyDown(sf::Keyboard::Space) && swimming == true)
	{
		animation->reset();
		animation = &walk;
		animation->reset();
		setSize(sf::Vector2f(15, 21));
		swimming = false;
	}
}

void Mario::update(float dt)
{
	setTextureRect(animation->getCurrentFrame());
	move(velocity * dt);
}