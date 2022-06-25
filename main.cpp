#include "List.h"
#include "Mst.h"
#include "Graph.h"
#include "Reading.h"
#include "AuthorsFileParser.h"


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

    /* Hashing code by Ian */
    // Create a hash table of 20 authors:
    HashTable<List<Author*>*> ht(10);
    // Declare some authors for the hash table:
    Author* AuthorA = new Author(1001, "Autor A", "Pais del autor A", 1901, 2001);
    Author* AuthorB = new Author(1002, "Autor B", "Pais del autor B", 1902, 2002);
    Author* AuthorC = new Author(1003, "Autor C", "Pais del autor C", 1903, 2003);
    List<Author*> *listaA = new List<Author*>;
    listaA->add(AuthorA); listaA->add(AuthorB);listaA->add(AuthorC);
    List<Author*> *listaB = new List<Author*>;
    listaB->add(AuthorB);listaB->add(AuthorA);listaB->add(AuthorC);listaB->add(AuthorB);
    List<Author*> *listaC = new List<Author*>;
    listaC->add(AuthorA);listaC->add(AuthorB);

    // Insert the elements in the hash table:
    ht.insertElement(listaA, 0);
    ht.insertElement(listaB, 1);
    ht.insertElement(listaC, 2);
    ht.insertElement(listaA, 3);
    ht.insertElement(listaB, 3);
    ht.insertElement(listaA, 5);
    ht.insertElement(listaB, 6);
    ht.insertElement(listaC, 7);
    ht.insertElement(listaB, 8);
    ht.insertElement(listaC, 8);

    std::cout << "Hash Table:" << std::endl;
    ht.display();
    /*
    rawHashTable->startCursor();
    while (rawHashTable->moveCursor()) {
        rawHashTable->getCursor()->display();
    }
    */
    /*
    ht.removeElement(AuthorA);
    std::cout << endl << "Hash Table:" << std::endl;
    ht.display();
    */
    /* End of hashing code */ 


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

    
     AuthorsFileParser p;
     List<Author*> *l = new List<Author*>;
     p.getAuthor(l);

     while(l->moveCursor()){
         l->getCursor()->display();
     }
     return 0;

      */
}