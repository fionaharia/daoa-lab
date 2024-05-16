#include<stdio.h>
#include<stdbool.h>

#define N 4 // Define the size of the chessboard

// Function to check if placing a queen at position (x, y) is safe
bool isSafe(int board[N][N], int x, int y) {
    // Check if there is a queen in the same column
    for (int i = 0; i < x; i++) {
        if (board[i][y])
            return false;
    }
    // Check upper left diagonal
    for (int i = x, j = y; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j])
            return false;
    }
    // Check upper right diagonal
    for (int i = x, j = y; i >= 0 && j < N; i--, j++) {
        if (board[i][j])
            return false;
    }
    return true;
}

// Function to solve N-Queens problem recursively
void solveNQueens(int board[N][N], int row) {
    if (row == N) {
        // If all queens are placed, print the solution
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        return;
    }
    // Try placing queen at each column of the current row
    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {
            // Place the queen
            board[row][col] = 1;
            // Recur for the next row
            solveNQueens(board, row + 1);
            // Backtrack
            board[row][col] = 0;
        }
    }
}

int main() {
    int board[N][N] = {0}; // Initialize chessboard with zeros
    solveNQueens(board, 0); // Start from the first row
    return 0;
}
