#ifndef TP_FINAL_HASH_H
#define TP_FINAL_HASH_H
#include "List.h"

template <typename Type>
class HashTable {
    private:
        List<Type>* table;
        int size;
        /* Constructor
        * PRE:
        * POST: Builds a new hash table of size 'n'
        */
        int getHash(int key);
    public:
        /* Constructor
        * PRE:
        * POST: Builds a new hash table of size 'n'
        */
        explicit HashTable(int n);     
        /* 
        * PRE:
        * POST: Inserts a new element to the hash table
        */
        void insertElement(Type value, int key);
        /* 
        * PRE:
        * POST: Removes an element from the hash table
        */
        void removeElement(int position);
        /* 
        * PRE:
        * POST:
        */
        void display();
};

template <typename Type>
HashTable<Type>::HashTable(int size) {
    this->table = new List<Type> [size];
    this->size = size;
}

template <typename Type>
int HashTable<Type>::getHash(int key) {
    return key % this->size;
}

template <typename Type>
void HashTable<Type>::insertElement(Type value, int key) {
    int position = getHash(key); 
    int listSize = table[position].getNumberOfElements();
    table[position].add(value);
}

template <typename Type>
void HashTable<Type>::removeElement(int position) {
    table[position] = nullptr;
}

template <typename Type>
void HashTable<Type>::display() {
    int listId, listSize;
    for (int tableId = 0; tableId < size; tableId++) {
        if (table[tableId].getNumberOfElements() != 0) {
            listId = 0;
            table[tableId].startCursor();
            listSize = table[tableId].getNumberOfElements();
            std::cout << "[ ";
            while (table[tableId].moveCursor()) {
                std::cout << table[tableId].getCursor()->getISNI();
                listId++;
                if (listId < listSize) {
                    std::cout << ", ";
                }
            }
            std::cout << " ]";
        }
        std::cout << std::endl;
    }




    /*
    int listIndex, listSize;
    for(int tableIndex = 0; tableIndex < size; tableIndex++) {
        if (table[tableIndex] != nullptr) {
            listIndex = 0;
            table[tableIndex]->startCursor();
            listSize = table[tableIndex]->getNumberOfElements();
            std::cout << "[ ";
            while (table[tableIndex]->moveCursor()) {
                std::cout << table[tableIndex]->getCursor()->getISNI();
                listIndex++;
                if (listIndex < listSize) {
                    std::cout << ", ";
                }
            }
            std::cout << " ]";
        }
        std::cout << std::endl;
    }
    */
}

#endif //TP_FINAL_HASH_H

// SOURCE: https://www.educative.io/answers/how-to-implement-a-hash-table-in-cpp