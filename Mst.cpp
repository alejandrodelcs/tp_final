#include "Mst.h"
#include "Historical.h"
#include <utility>

Mst::Mst(int nodes,std::vector<std::vector<int>> adjMatrix) {
    this->nodes = nodes;
    this->adjMatrix = std::move(adjMatrix);
    this->parent = nullptr;
    this->visited = nullptr;
    this->weight = nullptr;
    this->totalMinDistance = 0;
}

void Mst::calcMinDistance() {
    std::cout<<"Prim's Minimum Spanning Tree "<<std::endl;
    for (int i = 1; i < nodes; i++) {
        if (parent[i] < i) {
            this->totalMinDistance += weight[i];
            std::cout << "Edge: " << parent[i] << "-" << i << " "
                      << "Cost: " << weight[i] << std::endl;
        } else {
            this->totalMinDistance += weight[i];
            std::cout << "Edge: " << i << "-" << parent[i] << " "
                      << "Cost: " << weight[i] << std::endl;
        }
    }
    std::cout << "The total minimum distance taken is " << this->totalMinDistance << std::endl;
}

void Mst::exploreUnvisited(int minVertex) {
    for (int j = 0; j < nodes; j++) {
        if (adjMatrix[minVertex][j] != INFINITY && !visited[j]) {
            if (adjMatrix[minVertex][j] < weight[j]) {
                weight[j] = adjMatrix[minVertex][j];
                parent[j] = minVertex;
            }
        }
    }
}

int Mst::findMinVertex() {
    int minVertex = -1;
    for (int i = 0; i < nodes; i++) {
        if (!(this->visited[i]) && (minVertex == -1 || (this->weight[i]) < (this->weight[minVertex]))) {
            minVertex = i;
        }
    }
    return minVertex;
}

void Mst::setVisitedWeight() {
    for (int i = 0; i < nodes; i++) {
        this->visited[i] = false;
        this->weight[i] = INFINITY;
    }
}

void Mst::primAlgorithm() {
    this->parent = new int[nodes];
    this->visited = new bool[nodes];
    this->weight = new int[nodes];
    this->setVisitedWeight();
    this->parent[0] = -1; //FIRST NODE
    this->weight[0] = 0;
    for (int i = 0; i < nodes; i++) {
        //find min vertex
        int minVertex = findMinVertex();
        visited[minVertex] = true;
        //explore the unvisited neighbours of min vertex
        this->exploreUnvisited(minVertex);
    }
}





/* cuento - cuento 8 cuento - poema 0 cuento - novela 10 cuento - historica 15
 * poema - cuento 0
 *
 * poema - novela 5
 * poema - historica 20
 * novela - historica 60
 * poema - poema 1
 * novela - novela 30
 * historica - historica 80
 * */

int Mst::getCost(Reading initialReading, Reading endingReading){

    int costs[4][4]= {
            {8, 0, 10, 15},
            {0, 1, 5, 20},
            {10, 5, 30, 60},
            {15, 20, 60, 80}
    };

}

int Mst::validarTipo(Reading *reading){
    int typeNum;
    if (reading->getType() == TALE){
        typeNum= 1;
    }
    else if (reading->getType() == POEM){
        typeNum= 2;
    }
    else if (reading->getType() == NOVEL){
        typeNum= 3;
        if (dynamic_cast<Historical*>(reading)->getGenre() == Genres::HISTORICAL){
            typeNum=4;
        }
    }
}






Mst::~Mst() {
    delete[] parent;
    delete[] visited;
    delete[] weight;
}
