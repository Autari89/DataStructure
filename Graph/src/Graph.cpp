#include "Graph.hpp"
#include <iostream>
#include <queue>
#include <limits>

bool Graph::addVertex(const std::string& name)
{
	if (m_vertices.contains(name))
	{
		return false;
	}

	m_vertices[name] = new Vertex{name};
	return true;
}

bool Graph::addEdge(const std::string& from, const std::string& to, int weight)
{
	if (!m_vertices.contains(from) || !m_vertices.contains(to))
	{
		return false;
	}

	m_vertices[from]->adjacents.push_back({weight, m_vertices[to]});
	return true;
}

void Graph::printGraph()
{
	for (const auto& [name, vertex] : m_vertices)
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
	std::for_each(m_vertices.begin(), m_vertices.end(), [&visited](const auto& currentVertex) {visited[currentVertex.first] = false; });
	std::queue<Vertex*> queue;

	queue.push(m_vertices[startNode]);
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

void Graph::FindPathBFS(const std::string& start, const std::string& end)
{
	std::map<std::string, std::vector<std::string>> parentMap;
	std::map<std::string, int> distanceMap;
	std::for_each(m_vertices.begin(), m_vertices.end(), [&distanceMap](const auto& currentVertex)
		{
			distanceMap[currentVertex.first] = std::numeric_limits<int>::max();
		});
	std::queue<Vertex*> queue;

	queue.push(m_vertices[start]);
	distanceMap[start] = 0;

	while (!queue.empty())
	{
		Vertex* currentNode = queue.front();
		queue.pop();
		for (const auto& [weight, adjacentVertex] : currentNode->adjacents)
		{
			if (distanceMap[adjacentVertex->name] == std::numeric_limits<int>::max())
			{
				distanceMap[adjacentVertex->name] = distanceMap[currentNode->name] + 1;
				parentMap[adjacentVertex->name] = parentMap[currentNode->name];
				parentMap[adjacentVertex->name].push_back(currentNode->name);
				queue.push(adjacentVertex);
			}
		}
	}

	std::cout << "Path from " << start << " to " << end << std::endl;
	for_each(parentMap[end].begin(), parentMap[end].end(), [](const auto& parent) {std::cout << parent << "--"; });
	std::cout << end << std::endl;
	std::cout << "Total steps " << distanceMap[end] << std::endl;
}

void Graph::DFS(const std::string& start)
{
	std::map<std::string, bool> visited;
	std::for_each(m_vertices.begin(), m_vertices.end(), [&visited](const auto& currentVertex) {visited[currentVertex.first] = false; });
	rDFS(visited, start);
}

void Graph::rDFS(std::map<std::string, bool>& visitedNodes, const std::string& currentNode)
{
	if (visitedNodes[currentNode])
	{
		return;
	}

	visitedNodes[currentNode] = true;
	std::cout << "Vertex " << currentNode << std::endl;

	for (const auto& [weight, adjacentVertex] : m_vertices[currentNode]->adjacents)
	{
		rDFS(visitedNodes, adjacentVertex->name);
	}
}
