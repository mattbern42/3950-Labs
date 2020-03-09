/*
 *Authors: Sohaib Mohiuddin, Umar Riaz, Matthew Bernard, Vidit Vyas
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Sudoku_Valid.h"
#include "Sudoku_Solve.h"

int row=0;
int col=0;
int numbers[9][9];
//Check if puzzle needs to be solved
int hasZero(int number[9][9]){
	int i, j;
	for(i=0; i<9; ++i)
	{
		for(j=0; j<9; ++j)
			if(number[i][j]==0){
				return 1;
			}
	}
	return 0;
}
int main(void) {
	//Read puzzle
	FILE *file = fopen("puzzle.txt", "r");
	int num;
	while(row<9){
		while(col<9){
			fscanf(file, "%d", &num);
			numbers[col][row]= num;
			col++;
		}
		col=0;
		row++;
	}
	//If puzzle needs to be solved
	if(hasZero(numbers)){
		//solve puzzle
		int solved = sudokuSolve(numbers);
		//check if solution is correct
		valid(numbers, solved);
	}
	//Check given solution
	else{
		valid(numbers, 0);
	}
}
