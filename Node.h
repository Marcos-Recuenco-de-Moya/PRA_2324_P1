#include <iostream> //para el cout
#include <ostream>

template <typename T> 

class Node {
    public:
        //ATRIBUTOS

      T data;
      Node* next;

        //METODOS

      Node(T data, Node* next){
        this->data = data;
        this->next = next;
      }
    
};
