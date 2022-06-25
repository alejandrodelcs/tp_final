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
        /*
        * PRE:
        * POST:
        */
        void handleCollisionA(int* position);        
        /*
        * PRE:
        * POST:
        */
        void handleCollision(int position, Type newValue);        
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
void HashTable<Type>::handleCollisionA(int* position) {
    int newPosition = 0;
    newPosition = 0;
    while ((newPosition < size) && (table[newPosition] != nullptr)) {
        newPosition++;
    }
    if (newPosition != size) {
        *position = newPosition;
    }
}

template<typename Type>
void HashTable<Type>::handleCollision(int position,Type newValue) {
    table[position]->concatenate(newValue);
}

template<typename Type>
void HashTable<Type>::insertElement(Type value, int key) {
    int position = getHash(key);
    if (table[position] != nullptr) {
        //handleCollisionA(&position);
        handleCollision(position, value);
    } else {
        table[position] = value;
    }
}

template<typename Type>
void HashTable<Type>::removeElement(int position) {
    table[position] = nullptr;
}

template<typename Type>
void HashTable<Type>::display() {
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
}

#endif //TP_FINAL_HASH_H

// SOURCE: https://www.educative.io/answers/how-to-implement-a-hash-table-in-cpp