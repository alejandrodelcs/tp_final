#include "Mst.h"
#include "Graph.h"
//Prims is applied to find MST to a graph with property of graph as follows:-
//1) Undirected
//2) Connected
//3) Weighted
/*
 * Graph is

         (1)___6___(3)
        /|        / |
       4 |       /  |
      /  |      /   |
     /   |     /    |
    (0)  2    3     5
     \   |   /      |
      \  |  /       |
       8 | /        |
        \|/         |
        (2)____9___(4)


    weights of edges are as follows:-
    0----1 : 4
    0----2 : 8
    1----3 : 6
    1----2 : 2
    2----3 : 3
    2----4 : 9
    3----4 : 5


    MST

         (1)    (3)
        / |     /|
       4  |    / |
      /   2   3  |
    (0)   |  /   5
          | /    |
          |/     |
         (2)    (4)


*/


int main() {
    Graph<int> graph;

    graph.addVertex(0);
    graph.addVertex(1);
    graph.addVertex(2);
    graph.addVertex(3);
    graph.addVertex(4);
    graph.addVertex(5);

    graph.addEdge(0,1,4);
    graph.addEdge(0,2,8);
    graph.addEdge(1,3,6);
    graph.addEdge(1,2,2);
    graph.addEdge(2,3,3);
    graph.addEdge(2,4,9);
    graph.addEdge(3,4,5);
    graph.addEdge(3,5,1);
    graph.addEdge(4,5,3);


    graph.displayGraph();

    Mst mst(graph.getVertexNumbers(),graph.getAdjMAtrix());



    mst.primAlgorithm();
    mst.calcMinDistance();


}