#include "Graph.h"
#include <iostream>

int main()
{
	Graph g;

	g.addVertex(0, "Alice");
	g.addVertex(1, "Yumi");
	g.addVertex(2, "Daniel");
	g.addVertex(3, "Robbert");
	g.addVertex(4, "Bob");
	g.addVertex(5, "Rebbeca");

	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(0, 4);
	g.addEdge(0, 5);

	std::cout << "Pairs of vertices within distance 3:\n";
	g.findPairsWithinDistance3();

	return 0;
}