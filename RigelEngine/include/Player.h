#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"

class Player : public GameObject
{
public:
	Player(float x, float y);
	void handleInput() override;
	void update() override;
};

#endif // !PLAYER_H
