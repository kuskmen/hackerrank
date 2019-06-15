#include <iostream>
#include <vector>
#include <set>

#include "Codeforces.h"
#include "Graph.h"
#include "Common.h"

int main()
{
	std::vector<std::vector<int>> graph{
		{0, 1, 0, 0, 1},
		{1, 0, 1, 1, 1},
		{0, 1, 0, 1, 0},
		{0, 1, 1, 0, 1},
		{1, 1, 0, 1, 0},
	};

	GraphAdjMatrix simpleGraph(5);
	GraphAdjMatrix createdGraph(graph);

	createdGraph.Print();

	std::vector<std::list<int>> graph_list{
		{1, 4},
		{0, 4, 2, 3},
		{1, 3},
		{1, 4, 2},
		{3, 0, 1}
	};

	GraphAdjList simpleGraphList(5);
	GraphAdjList createdGraphList(graph_list);

	createdGraphList.Print();
	createdGraphList.DFS(0);
	std::cout << std::endl;
	createdGraphList.BFS(0);
}

