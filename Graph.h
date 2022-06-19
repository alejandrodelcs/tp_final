#ifndef TP_FINAL_GRAPH_H
#define TP_FINAL_GRAPH_H
#include "iostream"
#include "List.h"
#include "Vertex.h"

const int INFINITO = 99999999;

template <typename Type>
class Graph {
private:
    int ** adjMatrix;
    List<Vertex<Type>> *vertexes;

    //post: agranda dinamicamente la matriz de adyacencia
    void resizeAdjMatrix();

    //pre: la matriz que se le envie ya debe tener memoria reservada
    //post: copia la matriz de adyacencia en la nueva matriz
    void copyAdjMatrix(int** newAdjMatrix);

    //post inicializa un nuevo vertice en la matriz de adyacencia con un valor de infinito
    void initializeNewVertex(int** newAdjMatrix);

    //post libera la memoria de la matriz de adyacencia
    void desalocateMemoryAdjMatrix();

    void displayVertexes();

    void displayAdjMatrix();


public:
    Graph();

    /*
     * PRE: No hay vertices repetidos en nombre
     * POST:  agrega un nuevo vertice al grafo
     */
    void addVertex(Type newVertex);

    /*
     * PRE: el peso es un valor positivo
     * POST: Ajusta la matriz de adyacencia con el peso ingresado
     */
    void addEdge(Type origin, Type destiny, int weigth);

    /*
     * PRE:
     * POST: imprime por pantalla la matriz de adyacencia
     */
    void displayGraph();

    /*
     * PRE:
     * POST: retorna la matriz adjunta
     */
    int** getAdjMAtrix();

    /*
     * PRE:
     * POST: retorna el numero de vertices
     */
    int getVertexNumbers();

    ~Graph();


};


template<typename Type>
Graph<Type>::Graph() {
    adjMatrix = nullptr;
    vertexes = new List<Vertex<Type> >;
}


template<typename Type>
void Graph<Type>::addVertex(Type newVertex) {
    resizeAdjMatrix();
    vertexes->add(newVertex);

}


template<typename Type>
void Graph<Type>::resizeAdjMatrix() {
    int** auxMatrix;
    int newNumberOfVertexes = vertexes->getNumberOfElements() + 1;

    auxMatrix = new int*[newNumberOfVertexes];
    for(int i = 0; i < newNumberOfVertexes; i++){
        auxMatrix[i] = new int[newNumberOfVertexes];
    }

    copyAdjMatrix(auxMatrix);
    initializeNewVertex(auxMatrix);
    desalocateMemoryAdjMatrix();
    adjMatrix = auxMatrix;
}

template<typename Type>
void Graph<Type>::copyAdjMatrix(int **newAdjMatrix) {
    for(int i = 0; i < vertexes -> getNumberOfElements(); i++){
        for(int j = 0; j < vertexes -> getNumberOfElements(); j++){
            newAdjMatrix[i][j] = adjMatrix[i][j];
        }
    }
}

template<typename Type>
void Graph<Type>::desalocateMemoryAdjMatrix() {
    for(int i = 0; i < vertexes -> getNumberOfElements(); i++){
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;
}

template<typename Type>
void Graph<Type>::initializeNewVertex(int** newAdjMatrix) {
    for(int i = 0; i < vertexes -> getNumberOfElements(); i++){
        newAdjMatrix[vertexes -> getNumberOfElements()][i] = INFINITO;
        newAdjMatrix[i][vertexes -> getNumberOfElements()] = INFINITO;
    }
    newAdjMatrix[vertexes -> getNumberOfElements()][vertexes -> getNumberOfElements()] = 0;

}

template<typename Type>
Graph<Type>::~Graph() {
    desalocateMemoryAdjMatrix();
    adjMatrix = nullptr;
    delete vertexes;
}

template<typename Type>
void Graph<Type>::addEdge(Type origin, Type destiny, int weigth) {
    int originPosition = vertexes ->getPosition(origin);
    int destinyPosition = vertexes ->getPosition(destiny);

    if(originPosition == POSITION_NOT_FOUND){
        std::cout << "El vertice " << origin << " no existe en el grafo" << std::endl;
    }
    if(destinyPosition == POSITION_NOT_FOUND){
        std::cout << "El vertice " << destiny << " no existe en el grafo" << std::endl;
    }

    if(!(destinyPosition == POSITION_NOT_FOUND || originPosition == POSITION_NOT_FOUND)) {
        adjMatrix[originPosition][destinyPosition] = weigth;
        adjMatrix[destinyPosition][originPosition] = weigth;
    }

}

template<typename Type>
void Graph<Type>::displayGraph() {
    displayVertexes();
    displayAdjMatrix();
}

template<typename Type>
void Graph<Type>::displayVertexes() {
    std::cout << "Lista de vértices: [";
    for(int i = 0; i < vertexes -> getNumberOfElements(); i++){
        std::cout << vertexes -> getName(i + 1);
        if(i + 1 != vertexes -> getNumberOfElements()){
            std::cout << ", ";
        }
    }
    std::cout << "]" << endl;
}

template<typename Type>
void Graph<Type>::displayAdjMatrix() {
    std::cout << "Matriz de adyacencia:" << endl;
    for(int i = 0; i < vertexes -> getNumberOfElements(); i++){
        for(int j = 0; j < vertexes -> getNumberOfElements() * 2; j++) {
            if(j == vertexes -> getNumberOfElements() * 2 - 1){
                std::cout << endl;
            } else if(j % 2 == 0){
                if(adjMatrix[i][j/2] == INFINITO){
                    std::cout << "∞";
                } else {
                    std::cout << adjMatrix[i][j/2];
                }
            } else{
                std::cout << "|";
            }
        }
    }
    std::cout << endl;

}

template<typename Type>
int **Graph<Type>::getAdjMAtrix() {
    return this->adjMatrix;
}

template<typename Type>
int Graph<Type>::getVertexNumbers() {
    return vertexes->getNumberOfElements();
}

#endif //TP_FINAL_GRAPH_H
