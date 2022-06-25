#ifndef TP_FINAL_HASH_H
#define TP_FINAL_HASH_H

template < typename Type >
class HashTable {

private:

    Type* table;
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
HashTable<Type>::HashTable(int n) {
    table = new Type[n];
    this->size = n;
}

template<typename Type>
int HashTable<Type>::getHash(int key) {
    return key % this->size;
}

template<typename Type>
void HashTable<Type>::insertElement(Type value, int key) {
    table[getHash(key)] = value;
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
    int j, numberOfElements;
    for(int i = 0; i < this->size; i++) {
        if (this->table[i] != nullptr) {
            j = 0;
            this->table[i]->startCursor();
            numberOfElements = this->table[i]->getNumberOfElements();
            std::cout << "[ ";
            while (this->table[i]->moveCursor()) {
                std::cout << this->table[i]->getCursor()->getISNI();
                j++;
                if (j < numberOfElements) {
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