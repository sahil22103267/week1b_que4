# Dijkstra's Algorithm Implementation Analysis

## Overview
This implementation of Dijkstra's algorithm is part of TheAlgorithms/C repository. It finds the shortest path from a source vertex to all other vertices in a weighted graph.

## Code Structure

### Constants
- `MAX_NODES`: Maximum number of nodes in the graph (set to 1000)
- `INF`: Represents infinity (set to 999999)

### Global Variables
- `n`: Number of nodes in the graph
- `graph[MAX_NODES][MAX_NODES]`: 2D array representing the graph
- `dist[MAX_NODES]`: Array to store shortest distances from source
- `visited[MAX_NODES]`: Array to mark visited nodes
- `parent[MAX_NODES]`: Array to store the parent of each node in the shortest path

### Functions

#### `void dijkstra(int source)`
This is the main function implementing Dijkstra's algorithm.

Parameters:
- `source`: The starting vertex

Process:
1. Initialize distances, visited array, and parent array
2. Set distance of source vertex to 0
3. Find shortest path for all vertices
   - Pick the minimum distance vertex from the set of unvisited vertices
   - Mark the picked vertex as visited
   - Update distances of adjacent vertices

#### `int minDistance()`
Finds the vertex with the minimum distance value from the set of vertices not yet included in the shortest path tree.

Returns:
- Index of the vertex with minimum distance

Process:
1. Initialize min value and min_index
2. Loop through all vertices
   - If vertex is not visited and has a smaller distance than current min, update min and min_index
3. Return min_index

#### `void printPath(int j)`
Recursively prints the path from source to the given vertex.

Parameters:
- `j`: The destination vertex

Process:
1. Base case: if parent[j] is -1 (source vertex), print the vertex and return
2. Recursive case: call printPath for parent[j], then print the current vertex

#### `void printSolution()`
Prints the calculated distances and paths for all vertices.

Process:
1. Print header
2. Loop through all vertices
   - Print vertex number, its distance from source, and the path
   - Call printPath to print the actual path

#### `int main()`
The main function that sets up the graph and calls the Dijkstra function.

Process:
1. Input the number of nodes and edges
2. Initialize the graph with INF values
3. Input edge information (source, destination, weight) and update the graph
4. Call dijkstra function with source vertex 0
5. Print the solution

## Usage
Compile the program and run it. Input the number of nodes, number of edges, and edge information as prompted. The program will output the shortest distances and paths from the source vertex (0) to all other vertices.
