#include "../include/square.h"
#include <stdlib.h>

Square* NewSquare(Vector2 position, Vector2 size, bool alive) {
	Square* square = (Square*)malloc(sizeof(Square));
	square->position = position;
	square->size = size;
	square->alive = alive; 
	return square;
}

int DestroySquare(Square* square) {
	if (square == NULL) return -1;
	free(square);
	return 0;
}


