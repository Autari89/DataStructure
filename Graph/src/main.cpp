#include <iostream>
#include "Graph.hpp"

int main(int argc, char *argv[])
{
    Graph myGraph;

    myGraph.addVertex("A");
    myGraph.addVertex("B");
    myGraph.addVertex("C");
    myGraph.addVertex("D");

    myGraph.addEdge("A", "B", 1);
    myGraph.addEdge("A", "D", 1);
    myGraph.addEdge("B", "C", 2);
    myGraph.addEdge("C", "A", 3);

    myGraph.printGraph();
    return 0;
}