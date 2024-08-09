#pragma once
#include <vector>
#include <map>
#include <string>

#define SIZE 100
#define INF 100000

class Graph
{
public:
	Graph();
	void addVertex(int vnumber, const std::string& name);
	void addEdge(int v1, int v2);
	void findPairsWithinDistance3();
private:
	int matrix[SIZE][SIZE];
	std::vector<int> vertexes;
	int vertexCount;
	std::map<int, std::string> vertexNames;

	void bfs(int startVertex, std::vector<int>& distances);
	bool are_adj(int v1, int v2);
};