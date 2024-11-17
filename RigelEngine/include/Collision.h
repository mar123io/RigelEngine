#pragma once

#ifndef COLLISION_H
#define COLLISION_H

#include "GameObject.h"

inline bool checkCollision(const GameObject& obj1, const GameObject& obj2)
{
	return obj1.getBounds().intersects(obj2.getBounds());
}

#endif // COLLISION_H