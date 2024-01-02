#include <raylib.h>

#include "input.h"

void input_init(Input *input) {
    input->up = false;
    input->down = false;
    input->left = false;
    input->right = false;
}

void input_capture(Input *input) {
    input->up = IsKeyDown(KEY_UP) || IsKeyDown(KEY_W);
    input->down = IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S);
    input->left = IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A);
    input->right = IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D);
}
