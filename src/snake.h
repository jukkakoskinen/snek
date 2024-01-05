#pragma once

#include "config.h"

typedef enum SnakeDirection {
    SNAKE_DIRECTION_NONE,
    SNAKE_DIRECTION_UP,
    SNAKE_DIRECTION_DOWN,
    SNAKE_DIRECTION_LEFT,
    SNAKE_DIRECTION_RIGHT,
} SnakeDirection;

typedef struct SnakePart {
    int x;
    int y;
} SnakePart;

typedef struct Snake {
    SnakeDirection direction;
    SnakeDirection next_direction;
    SnakePart parts[SNAKE_MAX_LENGTH];
    unsigned int length;
    float timer;
} Snake;

void snake_init(Snake *snake, int x, int y);
void snake_grow(Snake *snake);
bool snake_hits(Snake *snake, int x, int y);
bool snake_hits_self(Snake *snake);
bool snake_occupies(Snake *snake, int x, int y);
void snake_update(Snake *snake, Input *input, float dt);
