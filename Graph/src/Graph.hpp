#pragma once
#include <vector>
#include <map>
#include <string>

struct Vertex
{
	std::string name;
	std::vector<std::pair<int, Vertex*>> adjacents;
};


class Graph
{
private:
	std::map<std::string, Vertex*> vertices;

public:
	bool addVertex(const std::string& name);
	bool addEdge(const std::string& from, const std::string& to, int weight);
	void printGraph();
	void BFS(const std::string& start);
};