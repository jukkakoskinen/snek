#include "input.h"
#include "snake.h"

void snake_init(Snake *snake, int x, int y) {
    snake->direction = SNAKE_DIRECTION_RIGHT;
    snake->next_direction = SNAKE_DIRECTION_NONE;
    snake->parts[0].x = x;
    snake->parts[0].y = y;
    snake->length = 1;
}

void snake_grow(Snake *snake) {
    if (snake->length < WORLD_WIDTH * WORLD_HEIGHT) {
        snake->parts[snake->length].x = snake->parts[snake->length - 1].x;
        snake->parts[snake->length].y = snake->parts[snake->length - 1].y;
        snake->length++;
    }
}

bool snake_hits(Snake *snake, int x, int y) {
    return snake->parts[0].x == x && snake->parts[0].y == y;
}

bool snake_hits_self(Snake *snake) {
    if (snake->length <= 2) {
        return false;
    }

    for (int i = 1; i < snake->length; i++) {
        SnakePart *part = &snake->parts[i];
        if (snake_hits(snake, part->x, part->y)) {
            return true;
        }
    }

    return false;
}

bool snake_occupies(Snake *snake, int x, int y) {
    for (int i = 0; i < snake->length; i++) {
        SnakePart *part = &snake->parts[i];
        if (part->x == x && part->y == y) {
            return true;
        }
    }

    return false;
}

void snake_update(Snake *snake, Input *input) {
    // Change direction
    if (snake->next_direction != SNAKE_DIRECTION_NONE) {
        snake->direction = snake->next_direction;
        snake->next_direction = SNAKE_DIRECTION_NONE;
    }

    // Queue direction
    if (input->up && snake->direction != SNAKE_DIRECTION_DOWN) {
        snake->next_direction = SNAKE_DIRECTION_UP;
    } else if (input->down && snake->direction != SNAKE_DIRECTION_UP) {
        snake->next_direction = SNAKE_DIRECTION_DOWN;
    } else if (input->left && snake->direction != SNAKE_DIRECTION_RIGHT) {
        snake->next_direction = SNAKE_DIRECTION_LEFT;
    } else if (input->right && snake->direction != SNAKE_DIRECTION_LEFT) {
        snake->next_direction = SNAKE_DIRECTION_RIGHT;
    }

    // Move body
    for (int i = snake->length - 1; i > 0; i--) {
        snake->parts[i] = snake->parts[i - 1];
    }

    // Move head
    SnakePart *head = &snake->parts[0];
    switch (snake->direction) {
        case SNAKE_DIRECTION_UP:
            head->y = (head->y - 1 + WORLD_HEIGHT) % WORLD_HEIGHT;
            break;
        case SNAKE_DIRECTION_DOWN:
            head->y = (head->y + 1) % WORLD_HEIGHT;
            break;
        case SNAKE_DIRECTION_LEFT:
            head->x = (head->x - 1 + WORLD_WIDTH) % WORLD_WIDTH;
            break;
        case SNAKE_DIRECTION_RIGHT:
            head->x = (head->x + 1) % WORLD_WIDTH;
            break;
        default:
            break;
    }
}
