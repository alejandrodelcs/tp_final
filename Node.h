#ifndef TP_FINAL_NODO_H
#define TP_FINAL_NODO_H
#include <string>

using namespace std;

template < typename Type >
class Node {
/*ATRIBUTOS*/
private:
    Type* element;
    Node<Type>* next;

/*MÉTODOS*/
public:
    explicit Node(Type name);

    //post: devuelve el nodo siguiente.
    Node<Type>* getNext();

    //post: devuelve el nombre del nodo
    int getName();

    //post: le asigna como siguiente el nodo recibido
    void assignNext(Node<Type>* ps);

    //PRE: -
    //POS: devuelve el dato que esta en el nodo
    Type getElement();

    ~Node();

};

template<typename Type>
Node<Type>::Node(Type name) {
    element = new Type(name);
    next = nullptr;
}

template<typename Type>
Node<Type> *Node<Type>::getNext() {
    return next;
}

template<typename Type> //EL VALOR DE RETORNO VA A DEPENDER DEL TIPO DE NODO
int Node<Type>::getName() {
    return element->getName();
}

template<typename Type>
void Node<Type>::assignNext(Node<Type> *ps) {
    this -> next = ps;
}


template<typename Type>
Type Node<Type>::getElement() {
    return *element;
}

template<typename Type>
Node<Type>::~Node() {
    delete element;
}


#endif //TP_FINAL_NODO_H
