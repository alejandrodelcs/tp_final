#include "List.h"
#include "Mst.h"
#include "Graph.h"
#include "Reading.h"
#include "AuthorsFileParser.h"
#include "Menu.h"



#include "Hash.h" // By Ian


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
    Menu m;
    m.interaction();
    return 0;
}