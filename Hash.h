#ifndef TP_FINAL_HASH_H
#define TP_FINAL_HASH_H
#include <list>

template < typename Type >
class HashTable {

private:

    list<Type> *table;
    int size;

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
    void removeElement(Type value);

    void display();

};

template<typename Type>
int HashTable<Type>::getHash(int key) {
    return key % this->size;
}

template<typename Type>
HashTable<Type>::HashTable(int n) {
    table = new list<Type>[n];
    this->size = n;
}

template<typename Type>
void HashTable<Type>::insertElement(Type value, int key) {
    table[getHash(key)].push_back(value);
}

template<typename Type>
void HashTable<Type>::removeElement(Type value) {
    /*
    int x = getHash(key.getISNI());



    list<int>::iterator i; 
    for (i = table[x].begin().getISNI(); i != table[x].end(); i++) { 
    // Check if the iterator points to the required item:
    if (*i == key) 
        break;
    }

    // If the item was found in the list, then delete it:
    if (i != table[x].end()) 
    table[x].erase(i);
    */
}

template<typename Type>
void HashTable<Type>::display() {
    // Traverse each index:
    for(int i = 0; i < this->size; i++) {
        std::cout << "Attempting to display the value of index " << i << "... ";
        // Traverse the list at current index:
        for (Type j : table[i]) {
            j.display();
        }
    
        std::cout << std::endl;
    }
}

#endif //TP_FINAL_HASH_H

// SOURCE: https://www.educative.io/answers/how-to-implement-a-hash-table-in-cpp