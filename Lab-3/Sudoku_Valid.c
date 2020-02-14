/*
 *Name         : Sudoku_Valid.c
 *Authors      : Sohaib Mohiuddin, Umar Riaz, Matthew Bernard, Vidit Vyas
 *This controls the solver and validator
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void * check_rows(int numbers[9][9]) {
	int i;
	int j;
	//Move from one row to another
	for (i = 0; i < 9; ++i) {
		int row[10] = {0};
		//Move through current row
		for (j = 0; j < 9; ++j) {
			//Check if row had a value more than once
			int val = numbers[i][j];
			if (row[val] != 0) {
				//Number appears more than once
				return (void *) 0;
			}
			else{
				row[val] = 1;
			}
		}
	}
	return (void *) 1;
}

void * check_cols(int numbers[9][9]) {
	int i;
	int j;
	//Move from one column to another
	for (i = 0; i < 9; ++i) {
		int col[10] = {0};
		//Move through current column
		for (j = 0; j < 9; ++j) {
			//Check if column has a value more than once
			int val = numbers[j][i];
			if (col[val] != 0) {
				//Number appears more than once
				return (void *) 0;
			}
			else{
				col[val] = 1;
			}
		}
	}
	return (void *) 1;
}

void * check_squares(int numbers[9][9]){
	int startRow = 0;
	int startCol = 0;
	int i,j;
	//Move from one 3x3 square to the other
	for(i=0; i < 9; i++){
		startRow = (i/3)*3;
		startCol = (i%3)*3;
		int saved[10] = {0};
		//Move through 3x3 square
		for(j = 0; j<9; j++){
			//check if square has a value more than once
			int val = numbers[j/3+startRow][j%3+startCol];
			if (saved[val] != 0) {
				//number appears more than once
				return (void *) 0;
			}
			else{
				saved[val] = 1;
			}
		}
	}
	return (void *) 1;
}
void valid(int numbers[9][9], int isSolved)
{
	//Create the threads
	pthread_t thread_rows, thread_cols, thread_squares;
	void * rows;
	void * cols;
	void * squares;
	//Create and run threads
	pthread_create(&thread_rows, NULL, check_rows, numbers);
	pthread_create(&thread_cols, NULL, check_cols, numbers);
	pthread_create(&thread_squares, NULL, check_squares, numbers);
	//Join threads
	pthread_join(thread_rows, &rows);
	pthread_join(thread_cols, &cols);
	pthread_join(thread_squares, &squares);
	//Check if the Sudoku Puzzle was solved
	if ((int) rows == 1 && (int) cols == 1 && (int) squares == 1 ) {
		//Check if it was solved using solver
		if(isSolved)
			printf("The Sudoku Puzzle is solved quitter!");
		else
			printf("The Sudoku Puzzle is solved!\n");
	}
	//Check if there was a solve attempt by solved
	else if(isSolved){
		printf("The Sudoku Puzzle has no solution");
	}
	else {
		printf("The Sudoku Puzzle is NOT solved.\n");
	}

}
