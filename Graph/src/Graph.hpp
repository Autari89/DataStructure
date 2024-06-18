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
	Graph(/* args */);

	bool addVertex(const std::string& name);
	bool addEdge(const std::string& from, const std::string& to, int weight);
	void printGraph();

	~Graph();
};