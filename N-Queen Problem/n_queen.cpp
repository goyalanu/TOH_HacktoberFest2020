/*Using Backtracking*/
#define N 4 
#include <stdbool.h> 
#include <stdio.h> 

void printSol(int cboard[N][N]) 
{ 
	for (int i = 0; i < N; i++) { 
		for (int j = 0; j < N; j++) 
			printf(" %d ", cboard[i][j]); 
		printf("\n"); 
	} 
}
bool place(int cboard[N][N], int row, int col) 
{ 
	int i, j; 
	for (i = 0; i < col; i++) 
		if (cboard[row][i]) 
			return false; 
	for (i = row, j = col; i >= 0 && j >= 0; i--, j--) 
		if (cboard[i][j]) 
			return false; 
	for (i = row, j = col; j >= 0 && i < N; i++, j--) 
		if (cboard[i][j]) 
			return false; 

	return true; 
} 
bool solve(int cboard[N][N], int col) 
{ 
	if (col >= N) 
		return true; 
	for (int i = 0; i < N; i++) { 
		if (place(cboard, i, col)) { 
			cboard[i][col] = 1; 
			if (solve(cboard, col + 1)) 
				return true; 
			cboard[i][col] = 0; 
		} 
	}
	return false; 
}
bool nQueen() 
{ 
	int cboard[N][N] = { { 0, 0, 0, 0 }, 
						{ 0, 0, 0, 0 }, 
						{ 0, 0, 0, 0 }, 
						{ 0, 0, 0, 0 } }; 

	if (solve(cboard, 0) == false) { 
		printf("Solution does not exist"); 
		return false; 
	} 

	printSol(cboard); 
	return true; 
} 
int main() 
{ 
	nQueen(); 
	return 0; 
} 
