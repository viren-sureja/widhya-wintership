#include<bits/stdc++.h>
using namespace std;

void shortestPath(int distance[]){
    
   sort(distance, distance + V);

   cout << endl << "Final shortest path stored in 'distance' is: " << distance[0];

   return;
}

void bellmanFord(int graph[][3], int start) {
   int distance[V];
   for(int i=0; i<V; i++){ 
      distance[i] = INT_MAX;
   }
   distance[start] = 0;

   for(int i=0; i< V-1; i++){ 
      for(int j=0; j<E; j++){ 
         int source = graph[j][0];
         int dest = graph[j][1];
         int weight = graph[j][2];
         int temp= distance[source] + weight;
         if(temp < distance[dest]){
               distance[dest] = temp;
         }
      }
   }

   for(int i=0; i<E; i++){ //To check for negative cycles
      int source = graph[i][0];
      int dest = graph[i][1];
      int weight = graph[i][2];
      if((distance[source] + weight) < distance[dest]){
         cout << endl << "Negative cycle exists" << endl;
         break;
      }
   }


   shortestPath(distance);

   return;  
}
int V, E;
int main() {
   
   cin >> V >> E;
   
   int G[E][3];
   // fill the graph with source, desti. and weight
   for(int i=0;i<E;i++) {
      cout << "please enter: <source> <destination> <weight>: ";
      cin >> G[i][0] >> G[i][1] >> G[i][2];
   }
   int S;
   cin >> S;   // fetching source
   
   bellmanFord(G, S);
}