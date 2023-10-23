#include <ostream>
#include "List.h"
#include "Node.h"

using namespace std;

template <typename T>

class ListLinked : public List<T> {

    private:
 
      Node<T>* first;
      int n;

    public:

      ListLinked(){
        first = nullptr;
        n = 0;
      }

      ~ListLinked(){
        Node<T>* aux = first;
        for(int i=0 ; i<n ; i++){
          aux = first->next;
          delete first;
          first = aux;
        }
      }


      T operator[](int pos){
        if(pos<0 || pos>n){
          throw out_of_range("Posición no válida");
        }else{
          Node<T>* aux = first;
          
          for(int i=1 ; i<pos ; i++){
            aux = aux->next;
          }
          return aux->data;
        }
      }


      friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list){
        out << list.arr;
        return out;
      }


      //miembros heredados de List<T>

      void insert(int pos, T e){
        if(pos<1 || pos>n){
          throw out_of_range("Posición no válida");
        }else{
	    if(pos==1){
                prepend(e);
	    }else if(pos==n){
	        append(e);
	    }else{
                Node<T>* aux = first;
          	Node<T>* prevAux = nullptr;
		Node<T>* nuevo;          	

          	for(int i=1 ; i<pos ; i++){
            	prevAux = aux;
            	aux = aux->next;
          	}

          	prevAux->next = nuevo;
          	nuevo->next = aux;
          	nuevo->data = e;
          	n++;
          	delete prevAux;
          	delete aux;
	    }
        }
      }


	void prepend(T e){
		Node<T>* aux = first;
		Node<T>* nuevo;

		first = nuevo;
		nuevo->data = e;
		nuevo->next=aux;
		delete aux;
		n++;
	}


	void append(T e){
		Node<T>* aux = first;
		Node<T>* nuevo;

		for(int i=1; i<n ; i++){
			aux = aux->next;
		}
		aux->next = nuevo;
		nuevo->data = e;
		nuevo->next = nullptr;
		n++;
		delete aux;
	}



	int size(){
		return n;
	}
	



	bool empty(){
		if(n==0){
			cout << "La lista esta vacía.\n";
			return true;
		}else{
			cout << "La lista NO esta vacía.\n";
			return false;
		}
	}



	int search(T e){

		Node<T>* aux = first;
		for(int i=1 ; i<n ; i++){
			if(aux->data == e){
				return i;
			}else{
				aux = aux->next;
			}
		}
		return -1;
	}



	T get(int pos){

		if(pos<1 || pos>n){
          		throw out_of_range("Posición no válida");
        	}else{
			Node<T>* aux = first;
			for(int i=1 ; i<pos ; i++){
				aux = aux->next;
			}
			return aux->data;
		}
	}



	T remove(int pos){
		Node<T>* aux = first;
		Node<T>* prevAux = nullptr;

		for(int i=1 ; i<pos ; i++){
			prevAux = aux;
			aux = aux->next;
		}
		prevAux->next = aux->next;
		return aux->data;
		delete aux;
		delete prevAux;
		n--;
	}



};
