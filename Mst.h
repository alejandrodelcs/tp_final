#ifndef TP_FINAL_MST_H
#define TP_FINAL_MST_H
#include <iostream>
const int INFINITY =  99999999;

class Mst {
private:
    int nodes;
    int *parent;
    bool *visited;
    int *weight;
    int totalMinDistance;
    int **adjMatrix;

    void setVisitedWeight();


    void exploreUnvisited(int minVertex);

    int findMinVertex();



public:
    /* Constructor
     * PRE: nodes > 0, edges>0
     * POST: constructs Minimum Spanning Tree
     */
    Mst(int nodes,int **adjMatrix);

    void calcMinDistance();

    /*
     * PRE:
     * POST:
     */
    void primAlgorithm();

    /*
     * PRE:-
     * POST: desalocates the memory used y parent, visited and weight vector
     */
    ~Mst();

};


#endif //TP_FINAL_MST_H
