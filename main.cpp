#include "list.h"
#include "Mst.h"
#include "Graph.h"
#include "lectura.h"
#include "ParserReading.h"
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
    /*

    Graph<int> graph;

    graph.addVertex(0);
    graph.addVertex(1);
    graph.addVertex(2);
    graph.addVertex(3);
    graph.addVertex(4);


    graph.addEdge(0,1,0);
    graph.addEdge(0,2,1);
    graph.addEdge(0,3,20);
    graph.addEdge(0,4,5);
    graph.addEdge(1,2,0);
    graph.addEdge(1,3,15);
    graph.addEdge(1,4,10);
    graph.addEdge(2,3,20);
    graph.addEdge(2,4,5);
    graph.addEdge(3,4,60);


    graph.displayGraph();

    Mst mst(graph.getVertexNumbers(),graph.getAdjMAtrix());



    mst.primAlgorithm();
    mst.calcMinDistance();

    */

    ParserReading p;
    List<Lectura*> *l = new List<Lectura*>;
    p.getReading(l);

    while(l->moveCursor()){
        l->getCursor()->mostrar();
    }
    return 0;
}