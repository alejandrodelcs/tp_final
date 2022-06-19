#ifndef TP_FINAL_NODO_H
#define TP_FINAL_NODO_H
#include <string>

using namespace std;

template < typename Type >
class Node {
/*ATRIBUTOS*/
private:
    Type* element;
    Node<Type>* _next;

/*MÉTODOS*/
public:
    explicit Node(Type name);

    //post: devuelve el nodo siguiente.
    Node<Type>* getNext();

    //post: devuelve el nombre del nodo
    int getName();

    //post: le asigna como siguiente el nodo recibido
    void assignNext(Node<Type>* next);

    ~Node();
};

template<typename Type>
Node<Type>::Node(Type name) {
    element = new Type(name);
    _next = nullptr;
}

template<typename Type>
Node<Type> *Node<Type>::getNext() {
    return _next;
}

template<typename Type> //EL VALOR DE RETORNO VA A DEPENDER DEL TIPO DE NODO
int Node<Type>::getName() {
    return element->getName();
}

template<typename Type>
void Node<Type>::assignNext(Node<Type> *next) {
    this -> _next = next;
}

template<typename Type>
Node<Type>::~Node() {
    delete element;
}


#endif //TP_FINAL_NODO_H
