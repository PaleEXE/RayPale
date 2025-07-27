#include "include/raylib.h"

int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 450;
    const int rectSize = 40;
    const int fps = 60;
    const float speed = 500.0f;
    const float dt = 1.0f / (float) fps;


    InitWindow(screenWidth, screenHeight, "Bouncing Rectangle");

    SetTargetFPS(fps);

    Vector2 position = {200, 150};
    Vector2 direction = {1, 1};

    while (!WindowShouldClose()) {
        position.x += direction.x * speed * dt;
        position.y += direction.y * speed * dt;

        if (position.x <= 0 || position.x + rectSize >= screenWidth) direction.x *= -1;
        if (position.y <= 0 || position.y + rectSize >= screenHeight) direction.y *= -1;

        BeginDrawing();
        ClearBackground(BLACK);
        DrawRectangle((int) position.x, (int) position.y, rectSize, rectSize, RED);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
