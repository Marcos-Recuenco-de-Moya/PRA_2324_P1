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
          
          for(int i=0 ; i<pos ; i++){
            aux = aux->next;
          }
          return aux->data;
        }
      }


      friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list){
	      Node<T>* aux = list.first;
		cout << "List => [";
	      for(int i=0 ; i<list.n ; i++){
		      cout << " ";
		out << aux->data;
		aux = aux->next;
	      }
	      cout << "]" << endl;
        return out;
      }


      //miembros heredados de List<T>

	void prepend(T e) override{
                Node<T>* aux = new Node<T>(e, first);
                first = aux;
                n++;
        }


        void append(T e) override{
                Node<T>* aux = first;

                for(int i=1; i<n ; i++){
                        aux = aux->next;
                }
                aux->next = new Node<T>(e, nullptr);
                n++;
        }


      void insert(int pos, T e) override{
        if(pos<0 || pos>n){
          throw out_of_range("Posición no válida");
        }else{
	    if(pos==0){
                prepend(e);
	    }else if(pos==n-1){
	        append(e);
	    }else{
		    cout << "No funciona el insert" << endl;
                Node<T>* aux = first;
          	Node<T>* prevAux = nullptr;

          	for(int i=0 ; i<pos ; i++){
            	prevAux = aux;
            	aux = aux->next;
          	}

          	prevAux->next = new Node<T>(e, aux);
          	n++;
	    }
        }
      }



	int size() override{
		return n;
	}
	



	bool empty() override{
		if(n==0){
			cout << "La lista esta vacía.\n";
			return true;
		}else{
			cout << "La lista NO esta vacía.\n";
			return false;
		}
	}



	int search(T e) override{

		Node<T>* aux = first;
		for(int i=0 ; i<n ; i++){
			if(aux->data == e){
				return i;
			}else{
				aux = aux->next;
			}
		}
		return -1;
	}



	T get(int pos) override{

		if(pos<0 || pos>n-1){
          		throw out_of_range("Posición no válida");
        	}else{
			Node<T>* aux = first;
			for(int i=0 ; i<pos ; i++){
				aux = aux->next;
			}
			return aux->data;
		}
	}



	T remove(int pos) override{

		if(pos<0 || pos>n-1){
                        throw out_of_range("Posición no válida");
                }else{

			Node<T>* aux = first;
			if(pos==0){
				first=first->next;
			}else{
			Node<T>* prevAux = nullptr;

			for(int i=0 ; i<pos ; i++){
				prevAux = aux;
				aux = aux->next;
			}
			prevAux->next = aux->next;
			}
			n--;
			T elemento=aux->data;
			delete aux;
			return elemento;
		}
	}



};

