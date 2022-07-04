#ifndef TP_FINAL_HASH_H
#define TP_FINAL_HASH_H
#include "List.h"

template <typename Type>
class HashTable {
private:
    int size{};
    List<Type>* table;
    /*
     * PRE:
     * POST: Returns the hashed key used as a parameter.
     */
    int getHash(int key);  
    /* 
     * PRE: 
     * POST: Compares if the author's key matches with the other parameter.
     */
    bool compareAuthorKey(Author* author, int comparationKey);
public:
    HashTable() = default;
    /* Constructor
     * PRE:
     * POST: Builds a new hash table of size 'n'
     */
    explicit HashTable(int size);
    /* 
     * PRE: 
     * POST: Get the physical size of the hash table.
     */
    int getSize();
    /* 
     * PRE: The parameter used has to be an Author object.
     * POST: Inserts a new author to the hash table.
     */
    void insertAuthor(Author* value);
    /* 
     * PRE:
     * POST: Inserts a new element to the hash table
     */
    void insertElement(Type value, int key);
    /* 
     * PRE:
     * POST: Searches for a specific element in the hash table.
     */
    Type searchElement(int key);
    /* 
     * PRE:
     * POST: Removes an element from the hash table
     */
    void removeElement(int key);
    /* 
     * PRE: The parameter position should be greater than 0 and lower than the size n of the hash table.
     * POST: Returns a specific list of the hash table.
     */
    List<Type> getList(int position);
    /* 
     * PRE:
     * POST: Returns the hash table.
     */
    List<Type>* getTable();
    /* 
     * PRE:
     * POST: Displays the object's attributes in screen.
     */
    void display();
    /* Destructor
     * PRE:
     * POST: Dealocates the memory used.
     */
    ~HashTable();
};

template <typename Type>
HashTable<Type>::HashTable(int size) {
    this->size = size;
    this->table = new List<Type>[size];
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
    table[position].add(value);
}

template<typename Type>
void HashTable<Type>::removeElement(int key) {
    bool found = false;
    int position = getHash(key);
    table[position].startCursor();
    while (table[position].moveCursor() && !found) {
        found = compareAuthorKey(table[position].getCursor(), key);
        if (found) {
            int removePosition = table[position].searchPosition(table[position].getCursor());
            delete table[position].getCursor();
            table[position].remove(removePosition);
        }
    }
}

template<typename Type>
Type HashTable<Type>::searchElement(int key) {
    Type returnedElement = NULL;
    bool found = false;
    int position = getHash(key);
    while (table[position].moveCursor() && !found) {
        found = compareAuthorKey(table[position].getCursor(), key);
        if (found) {
            returnedElement = table[position].getCursor();
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
            std::cout << tableId << " : [ ";
            while (table[tableId].moveCursor()) {
                std::cout << table[tableId].getCursor()->getName();
                listId++;
                if (listId < listSize) {
                    std::cout << ", ";
                }
            }
            std::cout << " ]";
        } else {
            std::cout << tableId << " : [ ]";
        }
        std::cout << std::endl;
    }
}

template <typename Type>
int HashTable<Type>::getSize() {
    return size;
}

template <typename Type>
List<Type> HashTable<Type>::getList(int position) {
    return table[position];
}

template <typename Type>
List<Type>* HashTable<Type>::getTable() {
    return table;
}

template <typename Type>
HashTable<Type>::~HashTable() {
    for (int i = 0; i < size; i++) {
        if(table[i].getNumberOfElements() > 0) {
            while (table[i].moveCursor()) {
                delete table[i].getCursor();
            }
        }
    }
    delete[] table;
    table = nullptr;
}

#endif