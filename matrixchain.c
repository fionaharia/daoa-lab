#include <stdio.h>

void printOptimalParens(int s[5][5], int i, int j) {
    if (i == j) {
        printf("M%d", i);
    } else {
        printf("(");
        printOptimalParens(s, i, s[i][j]);
        printOptimalParens(s, s[i][j] + 1, j);
        printf(")");
    }
}

int main() {
    int n = 5;
    int p[] = {5, 4, 6, 2, 7};
    int m[5][5] = {0};  // cost table
    int s[5][5] = {0};  // s-table
    int i, j, k, min, q;

    for (int d = 1; d < n - 1; d++) { // max length of the chain
        for (i = 1; i < n - d; i++) { // starting index of the matrix
            j = i + d;  // ending index of the matrix
            min = 32767;
            // find the minimum cost for the chain (k decides the brackets)
            for (k = i; k <= j - 1; k++) {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < min) {
                    min = q;
                    s[i][j] = k;
                }
            }
            m[i][j] = min;
        }
    }

    int res = m[1][n - 1];

    printf("Total cost: %d\n", res);

    printf("Cost Matrix: \n");
    for (i = 1; i < n; i++) {
        for (j = 1; j < n; j++) {
            if (j < i)
                printf("\t");
            else
                printf("%d\t", m[i][j]);
        }
        printf("\n");
    }

    printf("\nS-table: \n");
    for (i = 1; i < n; i++) {
        for (j = 1; j < n; j++) {
            if (j < i)
                printf("\t");
            else
                printf("%d\t", s[i][j]);
        }
        printf("\n");
    }

    printf("\nOptimal Parenthesization: ");
    printOptimalParens(s, 1, n - 1);
    printf("\n");
    return 0;
}
