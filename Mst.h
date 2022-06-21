#ifndef TP_FINAL_MST_H
#define TP_FINAL_MST_H
#include <iostream>
#include <vector>
const int INFINITY =  99999999;

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
     * PRE: nodes > 0, edges>0
     * POST: constructs Minimum Spanning Tree
     */
    Mst(int nodes,std::vector<std::vector<int>> adjMatrix);

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
