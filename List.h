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
    /* Constructor
     * PRE:
     * POST: Creates a new List object.
     */
    List();
    /* 
     * PRE:
     * POST: Returns the amount of nodes within the list.
     */
    int getNumberOfElements();
    /* 
     * PRE:
     * POST: Finds and returns the position where the searched node's name is (Or returns -1 if it wasn't found)
     */
    int getPosition(int node);
    /* 
     * PRE:
     * POST: Finds and returns the name where the searched node's position is (Or returns NAME_NOT_FOUND if it wasn't found)
     */
    int getName(int position);
    /*
     * PRE:
     * POST: Adds the new element to the end of the list.
     */
    void add(Type newElement);
    /*
     * PRE: The position parameter should be greater than 0 and lower (or equal) than the length of the list + 1 (If desired to add the element at the end of the list).
     * POST: Adds the new element to a specific position in the list (The first position is 1)
     */
    void add(Type newElement, int pos);
    /*
     * PRE: The position parameter should be greater than 0 and lower (or equal) than the length of the list.
     * POST: Removes the node in that position of the list.
     */
    void remove(int pos);
    /*
     * PRE: The list mustn't be empty
     * POST: Finds and returns the element in that position of the list.
     */
    Type search(int pos);
    /*
     * PRE:
     * POST: Returns the position of the element in the list (If not found, then it returns -1).
     */
    int searchPosition(Type element);
    /*
     * PRE: The cursor must be started.
     * POST: Returns true if the cursor doesn't point towards a NULL (false otherwise)
     */
    bool moveCursor();
    /*
     * PRE: Cursor must be pointing to an element of the list.
     *      (The method moveCursor() must've returned true previously)
     * POST: Returns the element in the cursor's position.
     */
    Type getCursor();
    /*
     * PRE:
     * POST: Initializes the cursor so it can trace through the list from the start.
     */
    void startCursor();
    /* Destructor
     * PRE:
     * POST: Dealocates the memory used.
     */
    ~List();
private:
    /*
     * PRE: 
     * POST: Returns the node in that position of the list.
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
int List<Type>::getName(int position) {
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
        auto *newNode = new Node<Type>(newElement);
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
        this->cursor = this->first; // Resets the cursor
    } else {
        this->cursor = this->cursor->getNext(); // Moves the cursor forward in the list
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
        Node<Type> *remove = this->first;
        this->first = this->first->getNext();
        delete remove;
    }
}

#endif
