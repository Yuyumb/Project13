#include "Graph.h"
#include <iostream>
#include <algorithm>

Graph::Graph() 
{
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            matrix[i][j] = 0;
        }
    }
    vertexCount = 0;
}

void Graph::addVertex(int vnumber, const std::string& name) 
{
    if (vertexCount < SIZE && vertexNames.find(vnumber) == vertexNames.end()) {
        vertexes.push_back(vnumber);
        vertexNames[vnumber] = name;
        vertexCount++;
    }
}

void Graph::addEdge(int v1, int v2)
{
    if (v1 < SIZE && v2 < SIZE)
    {
        matrix[v1][v2] = 1;
        matrix[v2][v1] = 1;
    }
}

void Graph::bfs(int startVertex, std::vector<int>& distances) {
    std::fill(distances.begin(), distances.end(), INF);
    std::vector<int> queue;
    queue.push_back(startVertex);
    distances[startVertex] = 0;

    int front = 0;
    while (front < queue.size()) {
        int current = queue[front++];
        for (int i = 0; i < vertexCount; ++i) {
            if (are_adj(current, vertexes[i]) && distances[vertexes[i]] == INF) {
                distances[vertexes[i]] = distances[current] + 1;
                queue.push_back(vertexes[i]);
            }
        }
    }
}

bool Graph::are_adj(int v1, int v2) {
    return matrix[v1][v2] != 0;
}

void Graph::findPairsWithinDistance3() {
    std::vector<int> distances(SIZE);

    for (int i = 0; i < vertexCount; ++i) {
        bfs(vertexes[i], distances);

        for (int j = i + 1; j < vertexCount; ++j) {
            if (distances[vertexes[j]] <= 3) {
                std::cout << "(" << vertexNames[vertexes[i]] << ", " << vertexNames[vertexes[j]] << ")\n";
            }
        }
    }
}