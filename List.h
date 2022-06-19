#ifndef TP_FINAL_LISTA_H
#define TP_FINAL_LISTA_H

#include "Node.h"

const int NAME_NOT_FOUND = -1;

const int POSITION_NOT_FOUND = -1;

template<typename Type>
class List {

private:
    int numberOfElements;
    Node<Type> *first;
    Node<Type> *latest;


public:
    List();

    //post: devuelve la cantidad de elementos que tiene la lista
    int getNumberOfElements();

    //post: devuelve la posicion en la que se encuentra el nombre que recibe o -1 si no lo encuentra
    int getPosition(int node);

    //post: devuelve el  nombre que se encuentra en la posicion recibida o NAME_NOT_FOUND si no lo encuentra
    int getName(int position);

    //post: agrega un nuevo elemento a la lista
    void add(Type newElement);

    ~List();
};

template<typename Type>
List<Type>::List() {
    numberOfElements = 0;
    latest = nullptr;
    first = nullptr;
}

template<typename Type>
int List<Type>::getNumberOfElements() {
    return numberOfElements;
}

template<typename Type>
int List<Type>::getPosition(int node) {
    bool foundElement = false;
    int i = 0;
    Node<Type> *aux = first;

    while (!foundElement && i < numberOfElements) {
        if (aux->getName() == node) {
            foundElement = true;
        }
        i++;
        aux = aux->getNext();
    }

    if (!foundElement) {
        return POSITION_NOT_FOUND;
    }
    return i - 1;
}

template<typename Type>
void List<Type>::add(Type newElement) {
    Node<Type> *newNode = new Node<Type>(newElement);
    if (first == nullptr) {
        first = newNode;
        latest = first;
    } else {
        latest->assignNext(newNode);
        latest = newNode;
    }
    numberOfElements++;
}

template<typename Type>
List<Type>::~List() {
    Node<Type> *next;
    while (first != nullptr) {
        next = first->getNext();
        delete first;
        first = next;
    }
}

template<typename Type>
int List<Type>::getName(int position) { //EL VALOR DE RETORNO VA A DEPENDER DEL TIPO DE NODO
    int i = 0;
    Node<Type> *aux = first;

    if (position > numberOfElements) {
        return NAME_NOT_FOUND ;
    }

    while (i != position - 1) {
        aux = aux->getNext();
        i++;
    }
    return aux->getName();
}

#endif //TP_FINAL_LISTA_H
