#pragma once

#include <stdbool.h>

typedef struct Input {
    bool up;
    bool down;
    bool left;
    bool right;
} Input;

void input_init(Input *input);
void input_capture(Input *input);
