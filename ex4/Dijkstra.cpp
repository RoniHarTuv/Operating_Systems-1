#include <iostream>
#include <limits.h>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
// Number of vertices in the graph
#define V 4

// A utility function to find the vertex with minimum
// distance value, from the set of vertices not yet included
// in shortest path tree
int minDistance(int dist[], bool sptSet[])
{

    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// A utility function to print the constructed distance
// array
void printSolution(int dist[])
{
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout << i << " \t\t\t\t" << dist[i] << endl;
}

// Function that implements Dijkstra's single source
// shortest path algorithm for a graph represented using
// adjacency matrix representation
void dijkstra(int graph[V][V], int src)
{
    int dist[V]; // The output array. dist[i] will hold the
                 // shortest
    // distance from src to i

    bool sptSet[V]; // sptSet[i] will be true if vertex i is
                    // included in shortest
    // path tree or shortest distance from src to i is
    // finalized

    // Initialize all distances as INFINITE and stpSet[] as
    // false
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++)
    {
        // Pick the minimum distance vertex from the set of
        // vertices not yet processed. u is always equal to
        // src in the first iteration.
        int u = minDistance(dist, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the
        // picked vertex.
        for (int v = 0; v < V; v++)

            // Update dist[v] only if is not in sptSet,
            // there is an edge from u to v, and total
            // weight of path from src to v through u is
            // smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
    printSolution(dist);
}

int countWords(string str)
{
    stringstream s(str);
    string word;
    int count = 0;
    while (s >> word)
        count++;
    return count;
}

vector<int> countWords2(string str, int size)
{
    vector<int> line{0, size};
    stringstream s(str);
    string word;
    int i = 0;
    while (s >> word)
    {
        line[i] = stoi(word);
        i++;
    }
    return line;
}

int main()
{
    cout << "The size of the matrix is : " << V << endl;
    int graph[V][V];

    cout << "Enter " << V * V << " numbers of the graph:" << endl;
    cout << "Enter only 0 in the diagonal" << endl;

    for (int i = 0; i < V; i++)
    {
        string s;
        getline(cin, s);
        if (countWords(s) != V)
        {
            cout << "Error - not valid number of edges" << endl;
            exit(1);
        }
        vector<int> line = countWords2(s, V);
        for (int j = 0; j < V; j++)
        {
            if (line[j] < 0)
            {
                cout << "Error-negative number" << endl;
                exit(1);
            }
            graph[i][j] = line[j];
        }
    }
    dijkstra(graph, 0);
    return 0;
}