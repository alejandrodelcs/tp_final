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
        /* 
        * PRE: 
        * POST: 
        */
        bool compareAuthorKey(Author* author, int comparationKey);
    public:
        /* Constructor
        * PRE:
        * POST: Builds a new hash table of size 'n'
        */
        explicit HashTable(int n);     
        /* 
        * PRE: The paramter used has to be an Author object
        * POST: Inserts a new author to the hash table
        */
        void insertAuthor(Author* value);
        /* 
        * PRE:
        * POST: Inserts a new element to the hash table
        */
        void insertElement(Type value, int key);
        /* 
        * PRE:
        * POST: 
        */
        Type searchElement(int key);
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
bool HashTable<Type>::compareAuthorKey(Author* author, int comparationKey) {
    return (author->getISNI() == comparationKey);
}


template <typename Type>
void HashTable<Type>::insertAuthor(Author* value) {
    insertElement(value,value->getISNI());
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
Type HashTable<Type>::searchElement(int key) {
    Type returnedElement;
    bool found = false;
    int position = getHash(key); 
    int listSize = table[position].getNumberOfElements();
    if (listSize == 1) {
        table[position].startCursor(); table[position].moveCursor();
        found = compareAuthorKey(table[position].getCursor(),key);
        if (found) {
            returnedElement = table[position].getCursor();
        }
        std::cout << "Author's ISNI == " << table[position].getCursor()->getISNI() << std::endl;
        std::cout << "key == " << key << std::endl;
    } else if (listSize > 1) {
        table[position].startCursor();
        while (table[position].moveCursor() && !found ) {
            found = compareAuthorKey(table[position].getCursor(),key);
            if (found) {
                returnedElement = table[position].getCursor();
            }
        }
    }
    if (!found) {
        returnedElement = NULL;
    }
    return returnedElement;
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
                std::cout << table[tableId].getCursor()->getName();
                listId++;
                if (listId < listSize) {
                    std::cout << ", ";
                }
            }
            std::cout << " ]";
        }
        std::cout << std::endl;
    }
}

#endif //TP_FINAL_HASH_H

// SOURCE: https://www.educative.io/answers/how-to-implement-a-hash-table-in-cpp

// https://www.geeksforgeeks.org/hashing-set-2-separate-chaining/
