#include "../include/draw.h"
#include "../lib/raylib/include/raylib.h"
#include <stdio.h>

void drawSquares() {
	Vector2 pos = {10.0f, 10.0f};
	Vector2 size = {10.0f, 10.0f};
	DrawRectangleV(pos, size, BLACK);
}

void drawSquare(Square* square) {
	Color color = BLACK;
	if (square->alive) {
		color = WHITE;
	}
	printf("square position %f, %f \n", square->position.x, square->position.y);
	DrawRectangleV(square->position, square->size, WHITE);
}
