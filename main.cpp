#include "List.h"
#include "Mst.h"
#include "Graph.h"
#include "Reading.h"
#include "AuthorsFileParser.h"
#include "Menu.h"
#include "Hash.h"


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


/*

void printSolution(int path[]);

bool isSafe(int v, bool graph[V][V], int path[], int pos) {
    if (graph [path[pos - 1]][ v ] == 0)
        return false;
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;
 
    return true;
}

bool hamCycleUtil(bool graph[V][V], int path[], int pos) {
    if (pos == V) {
        if (graph[path[pos - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }
    for (int v = 1; v < V; v++) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;
            if (hamCycleUtil (graph, path, pos + 1) == true)
                return true;
            path[pos] = -1;
        }
    }
    return false;
}

bool hamCycle(bool graph[V][V]) {
    int *path = new int[V];
    for (int i = 0; i < V; i++)
        path[i] = -1;
    path[0] = 0;
    if (hamCycleUtil(graph, path, 1) == false )
    {
        cout << "\nSolution does not exist";
        return false;
    }
 
    printSolution(path);
    return true;
}

*/

int main() {



    Menu m;


    m.interaction();
    return 0;
}