#ifndef SQUARE_H
#define SQUARE_H

#include "../lib/raylib/include/raylib.h"

typedef struct {
	Vector2 position;
	Vector2 size;
	bool alive;
} Square;

Square* NewSquare(Vector2 position, Vector2 size, bool alive);
int DestroySquare(Square* square);

#endif
