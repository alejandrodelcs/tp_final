#ifndef TP_FINAL_VERTEX_H
#define TP_FINAL_VERTEX_H

template <typename Data>

class Vertex {

private:
    Data name;

public:
    Vertex(Data name);

    //post: obtiene el nombre del vertice
    Data getName();

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


#endif //TP_FINAL_VERTEX_H
