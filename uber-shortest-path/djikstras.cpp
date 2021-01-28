#include <iostream>
#include <bits/stdc++.h>

#define Vertex 9

using namespace std;

void print(int distance[]){
    for(int i=0; i<Vertex; i++){
        printf("%d      %d\n", i, distance[i]);
    }
}

void Dijkstra(int graph[Vertex][Vertex], int startingIndex)
{
    int distance[Vertex]; 
    bool visited[Vertex];

    for (int i = 0; i < Vertex; i++){
        distance[i] = INT_MAX;
        visited[i] = false;
    }
    distance[startingIndex] = 0;

    for (int i=0; i<Vertex-1; i++) {

        int tiny = INT_MAX;
        int smallest_index;
        for (int j=0; j<Vertex; j++){
            if (visited[j] == false && distance[j] <= tiny){
                tiny = distance[j];
                smallest_index = j;
            }
        }

        visited[smallest_index] = true;

        for (int j=0; j<Vertex; j++){

            if (!visited[j] && graph[smallest_index][j] && distance[smallest_index] != INT_MAX && distance[smallest_index] + graph[smallest_index][j] < distance[j]){
                distance[j] = distance[smallest_index] + graph[smallest_index][j];
            }
        }
    }

    print(distance);
}



int main()
{
    int g[Vertex][Vertex] = { 
            { 1, 2, 0, 0, 0, 0, 0, 3, 0 },
            { 2, 0, 3, 0, 0, 0, 0, 7, 0 },
            { 0, 3, 0, 5, 0, 2, 0, 0, 2 },
            { 0, 0, 7, 0, 9, 14, 0, 5, 0 },
            { 5, 0, 0, 9, 0, 11, 0, 0, 0 },
            { 0, 0, 2, 14, 11, 0, 2, 0, 0 },
            { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
            { 1, 7, 0, 0, 1, 0, 1, 0, 8 },
            { 0, 0, 2, 0, 0, 0, 6, 19, 0 } 
        };

    Dijkstra(g, 0);

    return 0;
}