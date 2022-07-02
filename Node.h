#ifndef TP_FINAL_NODE_H
#define TP_FINAL_NODE_H

#include <string>

template < typename Type >
class Node {
private:
    Type* element;
    Node<Type>* next;
public:
    /* Constructor
     * PRE:
     * POST: Builds a new Node object
     */
    explicit Node(Type name);
    /*
     * PRE:
     * POST: Gets the next node.
     */
    Node<Type>* getNext();
    /*
     * PRE:
     * POST: Get the name of the node.
     */
    int getName();
    /*
     * PRE:
     * POST: Assigns the parameter's node as the one following the current.
     */
    void assignNext(Node<Type>* ps);
    /*
     * PRE:
     * POST: Returns the data within the node.
     */
    Type getElement();
    /* Destructor
     * PRE:
     * POST: Dealocates the memory used.
     */
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

template<typename Type>
int Node<Type>::getName() {
    return element->getName();
}

template<typename Type>
void Node<Type>::assignNext(Node<Type> *ps) {
    this->next = ps;
}

template<typename Type>
Type Node<Type>::getElement() {
    return *element;
}

template<typename Type>
Node<Type>::~Node() {
    delete element;
}

#endif
