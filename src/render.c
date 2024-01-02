#include <raylib.h>

#include "config.h"
#include "render.h"

void render_world(World *world) {
    // Draw food
    DrawRectangle(world->food.x * WORLD_CELL_SIZE, world->food.y * WORLD_CELL_SIZE, WORLD_CELL_SIZE, WORLD_CELL_SIZE, RED);

    // Draw snake
    Snake* snake = &world->snake;
    for (int i = 0; i < snake->length; i++) {
        DrawRectangle(snake->parts[i].x * WORLD_CELL_SIZE, snake->parts[i].y * WORLD_CELL_SIZE, WORLD_CELL_SIZE, WORLD_CELL_SIZE, GREEN);
    }
}
