#include "Graph.hpp"
#include <iostream>

Graph::Graph(/* args */)
{
}

Graph::~Graph()
{
}

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
