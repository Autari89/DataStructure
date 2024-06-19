#include <iostream>
#include "Graph.hpp"

int main(int argc, char *argv[])
{
    Graph myGraph;

    myGraph.addVertex("A");
    myGraph.addVertex("B");
    myGraph.addVertex("C");
    myGraph.addVertex("D");
    myGraph.addVertex("E");
    myGraph.addVertex("F");
    myGraph.addVertex("K");

    myGraph.addEdge("A", "B", 1);
    myGraph.addEdge("A", "D", 1);
    myGraph.addEdge("B", "C", 2);
    myGraph.addEdge("C", "A", 3);
    myGraph.addEdge("B", "E", 3);
    myGraph.addEdge("B", "F", 3);
    myGraph.addEdge("F", "E", 3);
    myGraph.addEdge("E", "K", 3);

    /*
    * Current graph
         C
    *  /   \
    * A---- B---E--K
    *  \     \ /
    *   D     F
    */

    myGraph.printGraph();
    myGraph.BFS("A");

    return 0;
}