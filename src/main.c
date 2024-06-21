#include <stdio.h>
#include "../lib/raylib/include/raylib.h"
#include "../include/draw.h"
#include "../include/grid.h"

int main() {
	InitWindow(300, 300, "WINDOW");
	Vector2 size = {.x=10.0f, .y=10.0f};
	Grid* grid = NewGrid(10, 10, size);

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(WHITE);
		VisitSquares(grid, drawSquare);
		EndDrawing();
	}
	CloseWindow();
}
