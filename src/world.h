#pragma once

#include "food.h"
#include "input.h"
#include "snake.h"

typedef struct World {
    Food food;
    Snake snake;
} World;

void world_init(World *world);
void world_update(World *world, Input *input);
