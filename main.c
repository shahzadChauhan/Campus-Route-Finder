#include <stdio.h>
#include <string.h>

#define V 9
#define MAX 20

// Campus locations
char *locations[V] = {
    "Main Gate",
    "Library",
    "Block 1",
    "Block 2",
    "Cafeteria",
    "Auditorium",
    "Parking",
    "Lab",
    "Medical Centre"
};

// Adjacency List
int graph[V][MAX];
int degree[V] = {0};

// Add an undirected edge
void addEdge(int u, int v)
{
    graph[u][degree[u]++] = v;
    graph[v][degree[v]++] = u;
}

// Display graph
void displayGraph()
{
    int i, j;

    printf("\n--- CAMPUS GRAPH ---\n");

    for (i = 0; i < V; i++)
    {
        printf("%s -> ", locations[i]);

        for (j = 0; j < degree[i]; j++)
        {
            printf("%s", locations[graph[i][j]]);

            if (j < degree[i] - 1)
                printf(", ");
        }

        printf("\n");
    }
}

// Find location index
int findLocation(char name[])
{
    int i;

    for (i = 0; i < V; i++)
    {
        if (strcmp(locations[i], name) == 0)
            return i;
    }

    return -1;
}

// BFS: Shortest Path
void BFS(int source, int destination)
{
    int queue[V];
    int visited[V] = {0};
    int parent[V];

    int front = 0, rear = 0;
    int current, i;

    for (i = 0; i < V; i++)
        parent[i] = -1;

    queue[rear++] = source;
    visited[source] = 1;

    while (front < rear)
    {
        current = queue[front++];

        if (current == destination)
            break;

        for (i = 0; i < degree[current]; i++)
        {
            int neighbor = graph[current][i];

            if (!visited[neighbor])
            {
                visited[neighbor] = 1;
                parent[neighbor] = current;
                queue[rear++] = neighbor;
            }
        }
    }

    if (!visited[destination])
    {
        printf("\nNo route found!\n");
        return;
    }

    // Reconstruct shortest path
    int path[V];
    int count = 0;

    current = destination;

    while (current != -1)
    {
        path[count++] = current;
        current = parent[current];
    }

    printf("\nShortest Route:\n");

    for (i = count - 1; i >= 0; i--)
    {
        printf("%s", locations[path[i]]);

        if (i > 0)
            printf(" -> ");
    }

    printf("\nNumber of edges: %d\n", count - 1);
}

// DFS using Stack
void DFS(int source)
{
    int stack[V];
    int visited[V] = {0};

    int top = -1;
    int current, i;

    stack[++top] = source;

    printf("\nDFS Traversal:\n");

    while (top != -1)
    {
        current = stack[top--];

        if (visited[current])
            continue;

        visited[current] = 1;

        printf("%s -> ", locations[current]);

        // Push neighbors in reverse order
        for (i = degree[current] - 1; i >= 0; i--)
        {
            int neighbor = graph[current][i];

            if (!visited[neighbor])
                stack[++top] = neighbor;
        }
    }

    printf("END\n");
}

// Display reachable locations and disconnected locations
void checkReachability(int source)
{
    int queue[V];
    int visited[V] = {0};

    int front = 0, rear = 0;
    int current, i;

    queue[rear++] = source;
    visited[source] = 1;

    while (front < rear)
    {
        current = queue[front++];

        for (i = 0; i < degree[current]; i++)
        {
            int neighbor = graph[current][i];

            if (!visited[neighbor])
            {
                visited[neighbor] = 1;
                queue[rear++] = neighbor;
            }
        }
    }

    printf("\nReachable Locations:\n");

    for (i = 0; i < V; i++)
    {
        if (visited[i])
            printf("%s\n", locations[i]);
    }

    printf("\nDisconnected Locations:\n");

    int found = 0;

    for (i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            printf("%s\n", locations[i]);
            found = 1;
        }
    }

    if (!found)
        printf("None\n");
}

// Main Function
int main()
{
    int choice;
    int source, destination;

    char sourceName[50];
    char destinationName[50];

    // Create campus graph
    addEdge(0, 1);  // Main Gate - Library
    addEdge(0, 6);  // Main Gate - Parking
    addEdge(1, 2);  // Library - Block 1
    addEdge(1, 4);  // Library - Cafeteria
    addEdge(2, 3);  // Block 1 - Block 2
    addEdge(2, 7);  // Block 1 - Lab
    addEdge(3, 5);  // Block 2 - Auditorium
    addEdge(4, 5);  // Cafeteria - Auditorium

    // Medical Centre is intentionally isolated
    // to demonstrate disconnected locations.

    while (1)
    {
        printf("\n===== CAMPUS ROUTE FINDER =====\n");
        printf("1. Display Campus Graph\n");
        printf("2. Find Shortest Route (BFS)\n");
        printf("3. Explore Campus (DFS)\n");
        printf("4. Check Reachability\n");
        printf("5. Exit\n");

        printf("\nEnter your choice: ");
        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input!\n");
            return 1;
        }

        switch (choice)
        {
            case 1:
                displayGraph();
                break;

            case 2:
                printf("Enter source location: ");
                scanf(" %49[^\n]", sourceName);

                printf("Enter destination location: ");
                scanf(" %49[^\n]", destinationName);

                source = findLocation(sourceName);
                destination = findLocation(destinationName);

                if (source == -1 || destination == -1)
                    printf("Invalid location!\n");
                else
                    BFS(source, destination);

                break;

            case 3:
                printf("Enter starting location: ");
                scanf(" %49[^\n]", sourceName);

                source = findLocation(sourceName);

                if (source == -1)
                    printf("Invalid location!\n");
                else
                    DFS(source);

                break;

            case 4:
                printf("Enter starting location: ");
                scanf(" %49[^\n]", sourceName);

                source = findLocation(sourceName);

                if (source == -1)
                    printf("Invalid location!\n");
                else
                    checkReachability(source);

                break;

            case 5:
                printf("\nThank you for using Campus Route Finder!\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}