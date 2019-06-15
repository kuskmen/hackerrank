#include <iostream>
#include <queue>
#include <functional>

#include "Graph.h"

GraphAdjMatrix::GraphAdjMatrix(int size)
{
	_elements = std::vector<std::vector<int>>(size);

	for (size_t i = 0; i < size; i++)
		_elements[i] = std::vector<int>(size);
}

GraphAdjMatrix::GraphAdjMatrix(std::vector<std::vector<int>> matrix)
{
	_elements = std::move(matrix);
}

void GraphAdjMatrix::Print()
{
	for (int v = 0; v < _elements.size(); v++)
	{
		std::cout << v;
		for (size_t c = 0; c < _elements.size(); c++)
		{
			if (_elements[v][c] == 1)
				std::cout << "->" << c;
		}
		std::cout << std::endl;
	}
}

GraphAdjList::GraphAdjList(int size)
{
	_elements = std::vector<std::list<int>>(size);

	for (int i = 0; i < size; i++)
		_elements[i] = std::list<int>();
}

GraphAdjList::GraphAdjList(std::vector<std::list<int>> vertices)
{
	_elements = std::move(vertices);
}

void GraphAdjList::Print()
{
	for (int v = 0; v < _elements.size(); ++v)
	{
		std::cout << v;
		for (auto x : _elements[v])
			std::cout << "->" << x;
		std::cout << std::endl;
	}
}

void GraphAdjList::DFS(int vertex)
{
	std::vector<bool> visited(_elements.size(), false);

	std::function<void(int, std::vector<std::list<int>>)> recurse = [&recurse, &visited](int vertex, std::vector<std::list<int>> vertices)
	{
		visited[vertex] = true;
		std::cout << vertex << " ";

		for (auto itr = vertices[vertex].begin(); itr != vertices[vertex].end(); ++itr)
			if (!visited[*itr])
				recurse(*itr, vertices);
	};

	recurse(vertex, _elements);
}

void GraphAdjList::BFS(int vertex)
{
	std::queue<int> processing;
	std::vector<bool> visited(_elements.size(), false);
	visited[vertex] = true;
	std::cout << vertex << " ";

	processing.emplace(vertex);
	while (!processing.empty())
	{
		int v = processing.front();
		processing.pop();

		for (auto itr = _elements[v].begin(); itr != _elements[v].end(); ++itr)
		{
			if (!visited[*itr])
			{
				std::cout << *itr << " ";
				visited[*itr] = true;
				processing.emplace(*itr);
			}
		}
	}
}
