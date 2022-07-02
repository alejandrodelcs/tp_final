#ifndef TP_FINAL_GRAPH_H
#define TP_FINAL_GRAPH_H

#include <iostream>
#include <vector>
#include "List.h"
#include "Vertex.h"

const int INFINITO = 99999999;

template<typename Type>
class Graph {
private:
    std::vector<std::vector<int>> adjMatrix;
    List<Vertex<Type>> *vertexes;
    /*
     * PRE:
     * POST: Dynamically expand the adjacency matrix.
     */
    void resizeAdjMatrix();
    /*
     * PRE:
     * POST:
     */
    void displayVertexes();
    /*
     * PRE:
     * POST:
     */
    void displayAdjMatrix();
public:
    /* Constructor
     * PRE:
     * POST
     */
    Graph();
    /*
     * PRE: There are no vertexes with repeated names.
     * POST: Adds a new vertex to the graph.
     */
    void addVertex(Type newVertex);
    /*
     * PRE: The parameter Weight should be positive.
     * POST: Adds a new edge to the adjacency matrix, with the indicated weight.
     */
    void addEdge(Type origin, Type destiny, int weigth);
    /*
     * PRE:
     * POST: Displays the adjacency matrix.
     */
    void displayGraph();
    /*
     * PRE:
     * POST: Returns the adjacency matrix.
     */
    std::vector<std::vector<int>> getAdjMAtrix();
    /*
     * PRE:
     * POST: Returns the number of vertexes.
     */
    int getVertexNumbers();
    /* Destructor
     * PRE:
     * POST: Dealocates the memory used.
     */
    ~Graph();
};

template<typename Type>
Graph<Type>::Graph() {
    vertexes = new List<Vertex<Type> >;
}

template<typename Type>
void Graph<Type>::addVertex(Type newVertex) {
    resizeAdjMatrix();
    vertexes->add(newVertex);

}

template<typename Type>
void Graph<Type>::resizeAdjMatrix() {
    int numberOfVertexes = vertexes->getNumberOfElements() + 1;
    std::vector<std::vector<int>> auxMatrix(numberOfVertexes, std::vector<int>(numberOfVertexes, INFINITO));
    adjMatrix = auxMatrix;
}

template<typename Type>
void Graph<Type>::addEdge(Type origin, Type destiny, int weigth) {
    int originPosition = vertexes->getPosition(origin);
    int destinyPosition = vertexes->getPosition(destiny);

    if (originPosition == POSITION_NOT_FOUND) {
        std::cout << "El vertice " << origin << " no existe en el grafo" << std::endl;
    }
    if (destinyPosition == POSITION_NOT_FOUND) {
        std::cout << "El vertice " << destiny << " no existe en el grafo" << std::endl;
    }
    if (!(destinyPosition == POSITION_NOT_FOUND || originPosition == POSITION_NOT_FOUND)) {
        adjMatrix[originPosition][destinyPosition] = weigth;
        adjMatrix[destinyPosition][originPosition] = weigth;
        adjMatrix[originPosition][originPosition] = 0;
        adjMatrix[destinyPosition][destinyPosition] = 0;
    }
}

template<typename Type>
void Graph<Type>::displayGraph() {
    displayVertexes();
    std::cout << std::endl;
    displayAdjMatrix();
}

template<typename Type>
void Graph<Type>::displayVertexes() {
    std::cout << "Lista de vértices: \n[";
    for (int i = 0; i < vertexes->getNumberOfElements(); i++) {
        std::cout << vertexes->getName(i + 1);
        if (i + 1 != vertexes->getNumberOfElements()) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

template<typename Type>
void Graph<Type>::displayAdjMatrix() {
    std::cout << "Matriz de adyacencia:" << std::endl;
    for (auto & i : adjMatrix) {
        for (int j = 0; j < (int)adjMatrix.size() * 2; j++) {
            if (j == (int)(adjMatrix.size()) * 2 - 1) {
                std::cout << std::endl;
            } else if (j % 2 == 0) {
                if (i[j / 2] == INFINITO) {
                    std::cout << "∞";
                } else {
                    std::cout << i[j / 2];
                }
            } else {
                std::cout << "|";
            }
        }
    }
    std::cout << std::endl;

}

template<typename Type>
std::vector<std::vector<int>> Graph<Type>::getAdjMAtrix() {
    return this->adjMatrix;
}

template<typename Type>
int Graph<Type>::getVertexNumbers() {
    return vertexes->getNumberOfElements();
}

template<typename Type>
Graph<Type>::~Graph() {
    delete vertexes;
}

#endif
