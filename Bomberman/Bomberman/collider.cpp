#include "collider.h"
#include <memory>
#include <vector>
#include "game-object.h"
#include "box-collider.h"
void Physics::Collider::Update()
{
	position = owner->GetPosition();
}
