#ifndef TP_FINAL_MST_H
#define TP_FINAL_MST_H

#include "Reading.h"
#include "Novel.h"
#include "Reading.h"
#include <iostream>
#include <vector>

const int INFINITY = 99999999;

class Mst {
private:
    int nodes;
    int *parent;
    bool *visited;
    int *weight;
    int totalMinDistance;
    std::vector<std::vector<int>> adjMatrix;
    /*
     * PRE:
     * POST: Initializes the values of the parent and weight vectors.
     */
    void setVisitedWeight();
    /*
     * PRE:
     * POST: If the node was already visited and the weight is lower than the others visited,
     *       then it'll change the value of the weight vector and initialize its parent.
     */
    void exploreUnvisited(int minVertex);
    /*
     * PRE:
     * POST: Search the next minimum vertex.
     */
    int findMinVertex();
public:
    /* Constructor
     * PRE: (nodes > 0) and (edges > 0)
     * POST: Initializes all the values of a new Mst object
     */
    Mst(int nodes,std::vector<std::vector<int>> adjMatrix);
    /*
     * PRE:
     * POST: Display the minimum distance, edges and cost
     */
    void calcMinDistance();
    /*
     * PRE:
     * POST: Finds the MST using prim's algorithm.
     */
    void primAlgorithm();
    /*
     * PRE:
     * POST Returns the parent vector
     */
    int* getParent();
    /*
     * PRE:
     * POST: Returns the weigth of the vectors.
     */
    int* getWeight();
    /* Destructor
     * PRE:
     * POST: Dealocates the memory used (parent, visited and weight).
     */
    ~Mst();
};

#endif
