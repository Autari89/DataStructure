#include "Graph.hpp"
#include <iostream>
#include <queue>

bool Graph::addVertex(const std::string& name)
{
	if (vertices.contains(name))
	{
		return false;
	}

	vertices[name] = new Vertex{name};
	return true;
}

bool Graph::addEdge(const std::string& from, const std::string& to, int weight)
{
	if (!vertices.contains(from) || !vertices.contains(to))
	{
		return false;
	}

	vertices[from]->adjacents.push_back({weight, vertices[to]});
	return true;
}

void Graph::printGraph()
{
	for (const auto& [name, vertex] : vertices)
	{
		std::cout << "Vertex: " << name << std::endl;
		for (const auto& [weight, adj] : vertex->adjacents)
		{
			std::cout << "  -> " << adj->name << " with weight " << weight << std::endl;
		}
	}
}

void Graph::BFS(const std::string& startNode)
{
	std::map<std::string, bool> visited;
	std::for_each(vertices.begin(), vertices.end(), [&visited](const auto& currentVertex) {visited[currentVertex.first] = false; });
	std::queue<Vertex*> queue;

	queue.push(vertices[startNode]);
	visited[startNode] = true;

	while (!queue.empty())
	{
		const auto vertex = queue.front();
		queue.pop();
		std::cout << "--> " << vertex->name << std::endl;

		for (const auto& [weight, adjacentVertex] : vertex->adjacents)
		{
			if (!visited[adjacentVertex->name])
			{
				visited[adjacentVertex->name] = true;
				queue.push(adjacentVertex);
			}
		}
	}
}
