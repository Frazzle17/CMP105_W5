#pragma once
#include "Framework/GameObject.h"
#include "Framework/Animation.h"

class Zombie:public GameObject
{
public:
	Zombie();
	~Zombie();

	virtual void handleInput(float dt);
	virtual void update(float dt);

protected:
	Animation walk;
};

