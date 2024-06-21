#include "../include/grid.h"
#include "../include/square.h"
#include <stdlib.h>
#include <stdio.h>

SquareRow* NewSquareRow(int length, float py, Vector2 size) {
	SquareRow* row = (SquareRow*)malloc(sizeof(SquareRow));
	row->length = length;
	row->squares = (Square**)malloc(sizeof(Square)*(row->length));
	for (int i=0; i<row->length; ++i) {
		Vector2 position;
		position.x = i * size.x;
		position.y = py; 
		Vector2 size = size;
		row->squares[i] = NewSquare(position, size, false);
	}
	return row;
}

int DestroySquareRow(SquareRow* row) {
	if (row == NULL) return -1;
	for (int i=0; i<row->length; ++i) {
		free(row->squares[i]);
	}
	free(row);
	return 0;
}

Grid* NewGrid(int length, int height, Vector2 size) {
	Grid* grid = (Grid*)malloc(sizeof(Grid));
	grid->rows = (SquareRow**)malloc(sizeof(SquareRow*)*grid->height);
	for (int i=0; i<grid->height; ++i) {
		int py = i * size.y;
		grid->rows[i] = NewSquareRow(length, py, size);
	}
	return grid;
}

int DestroyGrid(Grid *grid) {
	if (grid == NULL) return -1;
	for (int i=0; i<GridHeight(grid); ++i) {
		DestroySquareRow(grid->rows[i]);	
	}
	return 0;
}

int GridHeight(Grid *grid) {
	if (grid == NULL) return -1;
	return grid->height;
}

int GridWidth(Grid *grid) {
	if (grid == NULL) return -1;
	if (grid->rows == NULL) return -2;
	if (grid->rows[0] == NULL) return -3;
	return grid->rows[0]->length;
}

void VisitSquares(Grid *grid, void (*visit)(Square *)) {
	if (grid == NULL) printf("Visiting Grid but Grid is NULL");
	for (int i=0; i<GridHeight(grid); ++i) {
		for (int j=0; j<GridWidth(grid); ++j) {
			visit(grid->rows[i]->squares[j]);
		}
	}
}






