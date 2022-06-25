#ifndef TP_FINAL_HASH_H
#define TP_FINAL_HASH_H

template < typename Type >
class HashTable {
    private:
        Type* table;
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
        /* Constructor
        * PRE:
        * POST: Builds a new hash table of size 'n'
        */
        void handleCollision(int* position);        
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
    int position = getHash(key);
    if (table[position] != nullptr) {
        handleCollision(&position);
    }
    table[position] = value;
}

template<typename Type>
void HashTable<Type>::handleCollision(int* position) {
    *position = 0;
    while ((*position < this->size) && (this->table[*position] != nullptr)) {
        *position = *position + 1;
    }
}

template<typename Type>
void HashTable<Type>::removeElement(int position) {
    table[position] = nullptr;
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