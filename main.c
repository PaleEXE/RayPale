#include "include/raylib.h"

int main(void) {
    const int screenWidth = 900;
    const int screenHeight = 600;
    const int rectSize = 96;
    const int fps = 60;
    const float speed = 500.0f;
    const float dt = 1.0f / (float) fps;

    InitWindow(screenWidth, screenHeight, "Driving in My Car");

    Image image = LoadImage("../imgs/DUI.png");
    Texture2D texture = LoadTextureFromImage(image);
    UnloadImage(image);

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
        DrawTexturePro(
            texture,
            (Rectangle){0, 0, (float)texture.width, (float)texture.height},
            (Rectangle){position.x, position.y, rectSize, rectSize},
            (Vector2){0, 0},
            0.0f,
            WHITE
        );
        EndDrawing();
    }

    UnloadTexture(texture);
    CloseWindow();

    return 0;
}
