#ifndef TP_FINAL_VERTEX_H
#define TP_FINAL_VERTEX_H

template <typename Data>

class Vertex {
    private:
    Data name;
    public:
    /* Constructor
     * PRE:
     * POST: Builds a new Vertex object
     */
    Vertex(Data name);
    /*
     * PRE:
     * POST: Get name of the node
     */
    Data getName();
    /* Destructor
     * PRE:
     * POST: Dealocates the memory used
     */
    ~Vertex()= default;;
};

template<typename Data>
Vertex<Data>::Vertex(Data name) {
    this -> name = name;
}

template<typename Data>
Data Vertex<Data>::getName() {
    return name;
}

#endif
