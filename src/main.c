#include <raylib.h>

#include "input.h"
#include "render.h"
#include "world.h"

int main() {
    Input input;
    World world;

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "snek");
    SetTargetFPS(20);

    input_init(&input);
    world_init(&world);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        input_capture(&input);
        world_update(&world, &input);
        render_world(&world);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
