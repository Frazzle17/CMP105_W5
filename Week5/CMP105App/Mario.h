#pragma once
#include "Framework/GameObject.h"
#include "Framework/Animation.h"

class Mario:public GameObject
{
public:
	Mario();
	~Mario();

	virtual void handleInput(float dt);
	virtual void update(float dt);

protected:
	Animation* animation;
	Animation walk;
	Animation swim;
	Animation crouch;
	bool crouched;
	bool swimming;
};

