
#include <stdio.h>

#define MAX 20

int graph[MAX][MAX];
int visited[MAX];
int n;

// Depth First Search
void DFS(int vertex)
{
    int i;

    visited[vertex] = 1;
    printf("%d ", vertex);

    for (i = 0; i < n; i++)
    {
        if (graph[vertex][i] == 1 && !visited[i])
        {
            DFS(i);
        }
    }
}

// Breadth First Search
void BFS(int start)
{
    int queue[MAX], front = 0, rear = 0;
    int visitedBFS[MAX] = {0};
    int vertex, i;

    queue[rear++] = start;
    visitedBFS[start] = 1;

    while (front < rear)
    {
        vertex = queue[front++];
        printf("%d ", vertex);

        for (i = 0; i < n; i++)
        {
            if (graph[vertex][i] == 1 && !visitedBFS[i])
            {
                queue[rear++] = i;
                visitedBFS[i] = 1;
            }
        }
    }
}

int main()
{
    int i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    if (n <= 0 || n > MAX || start < 0 || start >= n)
    {
        printf("Invalid input!\n");
        return 1;
    }

    printf("DFS Traversal: ");
    for (i = 0; i < n; i++)
        visited[i] = 0;

    DFS(start);

    printf("\nBFS Traversal: ");
    BFS(start);

    printf("\n");
    return 0;
}
