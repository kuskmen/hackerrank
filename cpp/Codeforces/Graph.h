#pragma once
#include <vector>
#include <list>
#include <memory>

class GraphAdjMatrix
{
private:
	std::vector<std::vector<int>> _elements;
public:
	GraphAdjMatrix(int);
	GraphAdjMatrix(std::vector<std::vector<int>>);

	void Print();
};

class GraphAdjList
{
private:
	std::vector<std::list<int>> _elements;
public:
	GraphAdjList(int);
	GraphAdjList(std::vector<std::list<int>>);

	void Print();
	void DFS(int);
	void BFS(int);
};

