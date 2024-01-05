#include <raylib.h>

#include "config.h"
#include "world.h"

static void world_place_food(World *world) {
    int x = GetRandomValue(0, WORLD_WIDTH - 1);
    int y = GetRandomValue(0, WORLD_HEIGHT - 1);

    if (snake_occupies(&world->snake, x, y)) {
        world_place_food(world);
        return;
    }

    food_init(&world->food, x, y);
}

void world_init(World *world) {
    food_init(&world->food, 5, 5);
    snake_init(&world->snake, 1, 1);

    while (world->snake.length < SNAKE_INIT_LENGTH) {
        snake_grow(&world->snake);
    }
}

void world_update(World *world, Input *input, float dt) {
    snake_update(&world->snake, input, dt);

    if (snake_hits(&world->snake, world->food.x, world->food.y)) {
        snake_grow(&world->snake);
        world_place_food(world);
    }

    if (snake_hits_self(&world->snake)) {
        world_init(world);
    }
}
