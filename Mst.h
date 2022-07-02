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
     * POST : initializes the parent and height vectors
     */
    void setVisitedWeight();
    /*
     * PRE:
     * POST: if the node has already been visited and the weight
     *       is less than the others visited,
     *       chhange the value of the weight vector and initialize its parent
     */
    void exploreUnvisited(int minVertex);
    /*
     * PRE:
     * POST: Search the next vertex min
     */
    int findMinVertex();

public:
    /* Constructor
     * PRE: (nodes > 0) and (edges > 0)
     * POST: Builds the MST (minimum spanning tree)
     */
    Mst(int nodes,std::vector<std::vector<int>> adjMatrix);
    /*
     * PRE:
     * POST : show the minium distance, edges and cost
     */
    void calcMinDistance();
    /*
     * PRE:
     * POST:
     */
    void primAlgorithm();
    /*
     * PRE:
     * POST get parent vector
     */
    int* getParent();
    /*
     * PRE:
     * POST: get Weigth vector
     */
    int* getWeight();
    /* Destructor
     * PRE:
     * POST: Dealocates the memory used (parent, visited and weight).
     */
    ~Mst();
};

#endif
