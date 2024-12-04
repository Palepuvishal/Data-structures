#include <stdio.h>
#define MAX 5

void bfs(int adj[][MAX], int visited[], int start) {
    int queue[MAX], rear = -1, front = -1, i, k;

    for (k = 0; k < MAX; k++)
        visited[k] = 0;

    queue[++rear] = start;
    ++front;
    visited[start] = 1;

    while (rear >= front) {
        start = queue[front++];
        printf("%d->", start);

        for (i = 0; i < MAX; i++) {
            if (adj[start][i] && visited[i] == 0) {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
}

void dfs(int adj[][MAX], int visited[], int start) {
    int stack[MAX];
    int top = -1, i, k;

    for (k = 0; k < MAX; k++)
        visited[k] = 0;

    stack[++top] = start;
    visited[start] = 1;

    while (top != -1) {
        start = stack[top--];
        printf("%d->", start);

        for (i = MAX - 1; i >= 0; i--) {
            if (adj[start][i] && visited[i] == 0) {
                stack[++top] = i;
                visited[i] = 1;
            }
        }
    }
}




int main() {
    int visited[MAX] = {0};
    int adj[MAX][MAX], i, j;
    int option, size;
    int n1 = 1;\
    int n3 = 0,n4 = 0;

    do {
        printf("\n");
        printf("\n1. Enter the adjacent matrix");
        printf("\n2. BFS Traversal");
        printf("\n3. DFS Traversal");
        printf("\n4. exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("\nEnter the adjacency matrix:\n");
                for (i = 0; i < MAX; i++) {
                    for (j = 0; j < MAX; j++) {
                        scanf("%d", &adj[i][j]);
                    }
                }
                break;

            case 2:
                printf("Enter the starting Node : ");
                scanf("%d",&n1);
                if(n1>=MAX){
                    printf("\nInvalid input ");
                    continue;
                }
                printf("\nBFS Traversal: ");
                bfs(adj, visited, n1);
                break;

            case 3:
                printf("Enter the starting Node : ");
                scanf("%d",&n1);
                if(n1>=MAX){
                    printf("\nInvalid input ");
                    continue;
                }
                printf("DFS Traversal: ");
                dfs(adj, visited, n1);
                break;
        }
    } while (option != 4);

    return 0;
}
