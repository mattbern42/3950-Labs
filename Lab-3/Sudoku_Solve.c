/*
 *Name         : Sudoku_Solve.c
 *Authors      : Sohaib Mohiuddin, Umar Riaz, Matthew Bernard, Vidit Vyas
 *This controls the solver and validator
 */

#include <stdio.h>

int hasNotBeenUsed(int numbers[9][9], int row, int col, int num)
{
    //Determine offset of 3x3 square
	int rowOffset = (row/3) * 3;
    int colOffset = (col/3) * 3;
    int i;

    for(i=0; i<9; ++i)
    {
        //If number has been used in row
    	if (numbers[row][i] == num)
        	return 0;
    	//If number has been used in column
        if (numbers[i][col] == num)
        	return 0;
        //If number has been used in 3x3 square
        if (numbers[rowOffset + (i%3)][colOffset + (i/3)] == num)
        	return 0;
    }
    return 1;
}

int fillNumber(int numbers[9][9], int row, int col)
{
    int i;
    //If not at end of array
    if(row<9 && col<9)
    {
    	//If space is filled in
    	if(numbers[row][col] != 0)
        {
    		//Move to next column
            if((col+1)<9)
            	return fillNumber(numbers, row, col+1);
            //Move to next row
            else if((row+1)<9)
            	return fillNumber(numbers, row+1, 0);
            //At the end of array
            else
            	return 1;
        }
    	//Else if space is empty
        else
        {
            //Loop through 1-9
        	for(i=0; i<9; ++i)
            {
        		//check if number has not been used in row, column or square
            	if(hasNotBeenUsed(numbers, row, col, i+1))
                {
                    numbers[row][col] = i+1;
                    //If not at end of column
                    if((col+1)<9)
                    {
                    	//Try to fill next column
                        if(fillNumber(numbers, row, col +1))
                        	return 1;
                        else
                        	numbers[row][col] = 0;
                    }
                    //If not at end of row
                    else if((row+1)<9)
                    {
                    	//Try to fill next row
                        if(fillNumber(numbers, row+1, 0))
                        	return 1;
                        //Reset value if unsuccessful
                        else
                        	numbers[row][col] = 0;
                    }
                    else
                    	return 1;
                }
            }
        }
        return 0;
    }
    else
    	return 1;
}
int sudokuSolve(int numbers[9][9])
{
	//File to write solution
	FILE *file = fopen("solution.txt", "w");
	int i, j;
    //If puzzle was solved
	if(fillNumber(numbers, 0, 0))
    {
        for(i=1; i<10; ++i)
        {
            for(j=1; j<10; ++j){
            	fprintf(file,"%d ", numbers[i-1][j-1]);
            }
            fprintf(file,"\n");
        }
        fclose(file);
        return 1;
    }
    else printf("There is no solution");
    fclose(file);
    return 0;
}



