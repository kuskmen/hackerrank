#include <iostream>
#include <vector>
#include <set>

#include "Codeforces.h"
#include "Graph.h"
#include "Common.h"

int main()
{
	/*GraphAdjList cyclicGraph(6);

	cyclicGraph.AddEdgeDirected(0, 1);
	cyclicGraph.AddEdgeDirected(1, 2);
	cyclicGraph.AddEdgeDirected(2, 4);
	cyclicGraph.AddEdgeDirected(2, 5);
	cyclicGraph.AddEdgeDirected(2, 0);
	cyclicGraph.AddEdgeDirected(4, 3);
	cyclicGraph.AddEdgeDirected(3, 2);

	std::cout << cyclicGraph.HaveCycle();*/
/*
	GraphAdjList dag(6);

	dag.AddEdgeDirected(5, 2);
	dag.AddEdgeDirected(5, 0);
	dag.AddEdgeDirected(4, 0);
	dag.AddEdgeDirected(4, 1);
	dag.AddEdgeDirected(2, 3);
	dag.AddEdgeDirected(3, 1);

	dag.DFS(5);
	std::cout << std::endl;
	dag.BFS(5);
	std::cout << std::endl;
	dag.DFS();
	std::cout << std::endl;
	dag.TopSort();


*/
	GraphAdjList disjointGraph(8);
	
	disjointGraph.AddEdgeUndirected(0, 1);
	disjointGraph.AddEdgeUndirected(0, 3);
	disjointGraph.AddEdgeUndirected(1, 2);
	disjointGraph.AddEdgeUndirected(3, 4);
	disjointGraph.AddEdgeUndirected(3, 7);
	disjointGraph.AddEdgeUndirected(4, 5);
	disjointGraph.AddEdgeUndirected(4, 6);
	disjointGraph.AddEdgeUndirected(4, 7);
	disjointGraph.AddEdgeUndirected(5, 6);
	disjointGraph.AddEdgeUndirected(6, 7);

	disjointGraph.ShortestParth(0, 7);
}

