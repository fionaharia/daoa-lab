#include <stdio.h>
#define V 5

void prims(int G[V][V]);
int minkey(int key[], int set[]);
void displayMST(int parent[], int G[V][V]);

int minkey(int key[], int set[]) {
    int min = 999, index = -1;
    for (int i = 0; i < V; i++) {
        if (set[i] == 0 && key[i] < min) {
            min = key[i];
            index = i;
        }
    }
    return index;
}

void displayMST(int parent[], int G[V][V]) {
    printf("Edge \t Weight\n");
    for (int i = 1; i < V; i++) {
        printf("%d ->> %d \t %d\n", parent[i], i, G[i][parent[i]]);
    }
}

void prims(int G[V][V]) {
    int parent[V], key[V], set[V];
    for (int i = 0; i < V; i++) {
        key[i] = 998; // init to max value
        set[i] = 0; // init visited node to 0
    }

    key[0] = 0; // consider 0th vertex first
    parent[0] = -1; // parent of zero vertex is -1

    for (int i = 0; i < V - 1; i++) {
        int u = minkey(key, set); // find closest vertex
        set[u] = 1; // set visited to 1

        for (int j = 0; j < V; j++) { // for connected vertex of u
            if (G[u][j] && set[j] == 0 && G[u][j] < key[j]) {
                parent[j] = u;
                key[j] = G[u][j];
            }
        }
    }
    displayMST(parent, G);
}

int main() {
    int G[V][V] = 
    {{0, 2, 0, 6, 0},
     {2, 0, 3, 8, 5},
     {0, 3, 0, 0, 7},
     {6, 8, 0, 0, 9},
     {0, 5, 7, 9, 0}};
    
    prims(G);
    return 0;
}
