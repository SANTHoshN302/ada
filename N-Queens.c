/*Implement “N-Queens Problem” using Backtracking.*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


void printSolution(int N, int board[N][N]) {
    printf("One of the solutions:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%s ", board[i][j] ? "Q" : ".");
        printf("\n");
    }
}

bool isSafe(int N, int board[N][N], int row, int col) {
    int i, j;

    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool solveNQUtil(int N, int board[N][N], int col) {
    if (col >= N)
        return true;

    for (int i = 0; i < N; i++) {
        if (isSafe(N, board, i, col)) {
            board[i][col] = 1;

            if (solveNQUtil(N, board, col + 1))
                return true;

            board[i][col] = 0;
        }
    }

    return false;
}

void solveNQueens(int N) {
    int board[N][N];
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = 0;

    if (!solveNQUtil(N, board, 0)) {
        printf("Solution does not exist for N = %d\n", N);
        return;
    }

    printSolution(N, board);
}

int main() {
    int N;
    printf("Enter the number of queens (N): ");
    scanf("%d", &N);

    if (N < 1) {
        printf("Invalid input! N must be >= 1\n");
        return 1;
    }

    solveNQueens(N);
    return 0;
}

/* OUTPUT
Enter the number of queens (N): 4
One of the solutions:
. Q . .
. . . Q
Q . . .
. . Q .
*/
