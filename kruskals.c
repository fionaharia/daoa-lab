#include <stdio.h>

int i, j, a, b, u, v, n, ne = 1;
int min, mincost = 0, G[10][10], parent[10];

int findparent(int i) {
    while (parent[i]) {
        i = parent[i];
    }
    return i;
}

int unionfunc(int i, int j) {
    if (i != j) {  // if parents are not the same
        parent[j] = i;
        return 1;
    }
    return 0;
}

int main() {
    printf("Enter the number of vertices\n");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &G[i][j]);
            if (G[i][j] == 0)
                G[i][j] = 999;  // making it max
        }
    }

    for (i = 0; i < n; i++) {
        parent[i] = 0;  // initializing parent array to 0
    }

    printf("MST:\n");
    while (ne < n) {  // edges less than vertices
        for (i = 0, min = 999; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (G[i][j] < min) {
                    min = G[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        // finding the parent of both vertices
        u = findparent(u);
        v = findparent(v);

        if (unionfunc(u, v)) {  // if original parents are different
            printf("%d edge (%d, %d) = %d\n", ne++, a, b, min);
            mincost += min;
        }

        G[a][b] = G[b][a] = 999;  // setting the selected edge to max
    }

    printf("Minimum cost: %d\n", mincost);
    return 0;
}
