#include "collider.h"
#include <memory>
#include <vector>
#include "game-object.h"
#include "box-collider.h"
#include <iostream>
void Physics::Collider::Update()
{
	if (type == STATIC) return;
	position = owner->GetPosition();
}
