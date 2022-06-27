#include "List.h"
#include "Mst.h"
#include "Graph.h"
#include "Reading.h"
#include "AuthorsFileParser.h"
#include "menu.h"



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

    /* Hashing usage code by Ian */
    // Create a hash table of 20 authors:
    HashTable<Author*> ht(20);
    // Declare some authors for the hash table:
    Author* AuthorA = new Author(1, "Autor A", "Pais del autor A", 1901, 2001);
    Author* AuthorB = new Author(2, "Autor B", "Pais del autor B", 1902, 2002);
    Author* AuthorC = new Author(3, "Autor C", "Pais del autor C", 1903, 2003);
    Author* AuthorD = new Author(13, "Autor D", "Pais del autor D", 1904, 2004);
    Author* AuthorE = new Author(23, "Autor E", "Pais del autor E", 1905, 2005);
    Author* AuthorF = new Author(43, "Autor F", "Pais del autor F", 1906, 2006);
    // Insert the elements in the hash table:
    ht.insertAuthor(AuthorA);
    ht.insertAuthor(AuthorB);
    ht.insertAuthor(AuthorC);
    ht.insertAuthor(AuthorD);
    ht.insertAuthor(AuthorE);
    ht.insertAuthor(AuthorF);

    std::cout << "Hash Table:" << std::endl;
    ht.display();
    /* End of hashing code */ 

    Author* searchedAuthor = ht.searchElement(23);
    if (searchedAuthor != NULL) {
        std::cout << "Result of searching the key 23 on the hash table: " << searchedAuthor->getName() << std::endl;
    }
    ht.removeElement(23);
    std::cout << "Removing the element with key 23 on the hash table..." << std::endl << std::endl;

    std::cout << "Hash Table:" << std::endl;
    ht.display();
    /* End of hashing code */ 

    // Example of Getlist() method usage
    List<Author*>* table = new List<Author*>[ht.getSize()];
    for (int i=0;i < ht.getSize();i++) {
        table[i] = ht.getList(i);
    }
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


/*
    Menu m;
    m.interaction();
    return 0;
    */
}