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
    void setVisitedWeight();
    void exploreUnvisited(int minVertex);
    int findMinVertex();

public:
    /* Constructor
     * PRE: (nodes > 0) and (edges > 0)
     * POST: Builds the MST (minimum spanning tree)
     */
    Mst(int nodes,std::vector<std::vector<int>> adjMatrix);

    /*
     * PRE:
     * POST
     */
    void calcMinDistance();

    /*
     * PRE:
     * POST:
     */
    void primAlgorithm();

    /*
     * PRE:
     * POST
     */
    int* getParent();

    /*
     * PRE:
     * POST:
     */
    int* getWeight();


    /* Destructor
     * PRE:-
     * POST: Dealocates the memory used (parent, visited and weight).
     */
    ~Mst();

};

#endif //TP_FINAL_MST_H
