#ifndef GRID_H
#define GRID_H

#include "square.h"
#include "../lib/raylib/include/raylib.h"

typedef struct {
	Square** squares;	
	int length;
} SquareRow;

typedef struct {
	SquareRow** rows;
	int height;
} Grid;

SquareRow* NewSquareRow(int length, float py, Vector2 size);
int DestroySquareRow(SquareRow* row);
Grid* NewGrid(int length, int height, Vector2 size);
int DestroyGrid(Grid* grid);
int GridHeight(Grid* grid);
int GridWidth(Grid* grid);
void VisitSquares(Grid* grid, void (*visit)(Square* square));

#endif
