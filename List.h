#ifndef TP_FINAL_LISTA_H
#define TP_FINAL_LISTA_H

#include "Node.h"
#include <iostream>

const int NAME_NOT_FOUND = -1;

const int POSITION_NOT_FOUND = -1;

template<typename Type>
class List {

private:
    int numberOfElements;
    Node<Type> *first;
    Node<Type> *cursor;


public:
    List();

    //post: devuelve la cantidad de elementos que tiene la lista
    int getNumberOfElements();

    //post: devuelve la posicion en la que se encuentra el nombre que recibe o -1 si no lo encuentra
    int getPosition(int node);

    //post: devuelve el  nombre que se encuentra en la posicion recibida o NAME_NOT_FOUND si no lo encuentra
    int getName(int position);

    /*
   * PRE: -
   * POST: agrega el dato al final de la lista en la posición obtenerLargo() + 1
   */
    void add(Type newElement);

    /*
     * PRE::recibe un Dato d - 0 < pos <= largo+1
     * POST: agrega el Dato d en la Lista. La primera posición es 1
     */
    void add(Type newElement, int pos);

    /*
    * PRE:  0 < pos <= largo
    * POST: -
    */
    void remove(int pos);

    /*
     * PRE: la lista no tiene que estar vacia
     * POST: devuelve el dato que esta encima de la lista
     */
    Type search(int pos);

    /*
     * PRE: Recibe el dato a buscar en la lista
     * POST: devuelve la posicion del dato en la lista, -1 de lo contrario
     */
    int searchPosition(Type element);


    /*
     * PRE: consulta si hay un elemento siguiente (si el cursor no apunta a NULL)
     * POST: devuelve true si el cursor no apunta a NULL, false de lo contrario
    */
    bool moveCursor();

    /*
     * PRE:  el cursor se posiciona sobre un elemento de la lista
     *      (el metodo avanzarCursor() tiene que haber devuelto true previamente)
     * POST: devuelve el elemento en la posición del cursor y avanza
     */
    Type getCursor();

    /*
    * PRE: -
    * POST: Deja Cursor preparado para iniciar un nuevo recorrido de la Lista
    */
    void startCursor();


    //PRE: Recibe una lista distinta a la original
    //POS: concatena la dos lista colocando la segunda lista al final de la otra.
    void concatenate(List<Type> *l);


    ~List();

private:
/*
     * PRE: Recibe una posicion de la lista
     * POST: Retorna el nodo en dicha posición
     */
    Node<Type> *getNode(int pos);


};

template<typename Type>
List<Type>::List() {
    this->first = nullptr;
    this->cursor = nullptr;
    numberOfElements = 0;
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
    this->add(newElement, getNumberOfElements() + 1);
}

template<typename Type>
int List<Type>::getName(int position) { //EL VALOR DE RETORNO VA A DEPENDER DEL TIPO DE NODO
    int i = 0;
    Node<Type> *aux = first;
    if (position > numberOfElements) {
        return NAME_NOT_FOUND;
    }
    while (i != position - 1) {
        aux = aux->getNext();
        i++;
    }
    return aux->getName();
}

template<typename Type>
Node<Type> *List<Type>::getNode(int pos) {
    Node<Type> *current = this->first;
    for (int i = 1; i < pos; i++)
        current = current->getNext();
    return current;
}

template<typename Type>
void List<Type>::add(Type newElement, int pos) {
    if ((pos > 0) && (pos <= this->numberOfElements + 1)) {
        Node<Type> *newNode = new Node<Type>(newElement);

        if (pos == 1) {
            newNode->assignNext(this->first);
            this->first = newNode;
        } else {
            Node<Type> *former = getNode(pos - 1);
            newNode->assignNext(former->getNext());
            former->assignNext(newNode);
        }

        this->numberOfElements++;
        this->startCursor();
    }
}

template<typename Type>
void List<Type>::startCursor() {
    this->cursor = nullptr;
}

template<typename Type>
void List<Type>::remove(int pos) {
    if ((pos > 0) && (pos <= this->numberOfElements)) {
        Node<Type> *remove;
        if (pos == 1) {
            remove = this->first;
            this->first = remove->getNext();
        } else {
            Node<Type> *former = this->getNode(pos - 1);
            remove = former->getNext();
            former->assignNext(remove->getNext());
        }
        delete remove;
        this->numberOfElements--;
        this->startCursor();
    }
}

template<typename Type>
Type List<Type>::search(int pos) {
    Type element;
    if ((pos > 0) && (pos <= this->numberOfElements)) {
        element = this->getNode(pos)->getElement();
    }
    return element;
}

template<typename Type>
int List<Type>::searchPosition(Type element) {
    Node<Type> *aux = this->first;
    bool foundOut = false;
    int position = 0;
    while (aux != nullptr && !foundOut) {
        if (aux->getElement() == element) {
            foundOut = true;
        }
        position++;
        aux = aux->getNext();
    }
    return position;
}

template<typename Type>
bool List<Type>::moveCursor() {
    if (this->cursor == nullptr) {
        this->cursor = this->first;  //reinicia
    } else {
        this->cursor = this->cursor->getNext(); //avanza al sgte
    }
    return (this->cursor != nullptr);
}

template<typename Type>
Type List<Type>::getCursor() {
    Type element;
    if (this->cursor != nullptr) {
        element = this->cursor->getElement();
    }
    return element;
}

template<typename Type>
List<Type>::~List() {
    while (this->first != nullptr){
        Node<Type>* remove = this->first;
        this->first = this->first->getNext();
        delete remove;
    }
}

template<typename Type>
void List<Type>::concatenate(List<Type> *l) {
    Node<Type> *aux = l->first;
    while(aux != nullptr) {
        add(aux->getElement());
        aux = aux->getNext();
    }
}


#endif //TP_FINAL_LISTA_H
