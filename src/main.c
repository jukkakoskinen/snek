#include <raylib.h>

#include "input.h"
#include "render.h"
#include "world.h"

int main() {
    Input input;
    World world;

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "snek");

    input_init(&input);
    world_init(&world);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        input_capture(&input);
        world_update(&world, &input, GetFrameTime());
        render_world(&world);

        DrawText(TextFormat("FPS: %i", GetFPS()), 10, 10, 20, GREEN);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
