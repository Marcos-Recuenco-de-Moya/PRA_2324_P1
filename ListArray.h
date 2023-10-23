#include <iostream> //para el cout
#include <ostream>
#include "List.h"

using namespace std;

template <typename T> 

class ListArray : public List<T> {

    private:
        //declaración de las variables privadas
        T* arr;
        int max;
        int n;
        static const int MINSIZE = 2;


      void resize(int new_size){
        T* new_arr = new T[new_size];
        
        for(int i=0 ; i < max ; i++){
          new_arr[i] = arr[i];
        }
        delete[] arr;
        arr = new_arr;
        max = new_size;
      }

    public:
        // miembros públicos, incluidos los heredados de List<T>

      ListArray(){
        arr = new T[MINSIZE];
        max = 2;
        n = 0;
      }


      ~ListArray(){
        delete[] arr;
      }


      T operator[](int pos){
        if(pos<0 || pos>size()){
          throw out_of_range("Posición no válida");
        }else{
          return arr[pos];
        }
      }


      friend ostream& operator<<(ostream &out, const ListArray<T> &list){
	      cout << "List => [";
	      for(int i=0 ; i<list.n ; i++){
		      out<< list.arr[i] << " ";
	      }
	      cout << "]" << endl;
        return out;
      }



      //miembros heredados de List<T>

      int size() override{
        return n;
      }

      void insert(int pos, T e) override{
        if(pos<0 || pos>size()){
          throw out_of_range("Posición no válida");
        }else{

          resize(size() +1);
          for(int i=max-1 ; i>=pos ; i--){
            if(i==pos){
              arr[i]=e;
            }else{
              arr[i]=arr[i-1];
            }
          }
        }
	max++;
	n++;
      }

      void append(T e) override{
        resize(size() +1);
        arr[max-1] = e;
	max++;
	n++;
      }

      void prepend(T e) override{
        resize(size() +1);
        for(int i=max-1 ; i >= 0 ; i--){
          if(i==0){
            arr[i]=e;
          }else{
            arr[i]=arr[i-1];
          }
        }
	max++;
	n++;
      }


    T remove(int pos) override{
      if(pos<0 || pos>size()){
        throw out_of_range("Posición no válida");
      }else{
        int aux = arr[pos];
        for(int i=pos ; i<=max-1 ; i++){
          if(pos==max){
		resize(size()-1);
	  }else{
             arr[i]=arr[i+1];
          }
	}
	max--;
	n--;
        return aux;
      }
    }


    T get(int pos) override{
      if(pos<0 || pos>size()){
        throw out_of_range("Posición no válida");
      }else{
        return arr[pos];
      }
    }


    int search(T e) override{
      for(int i=0 ; i<max ; i++){
        if(arr[i]==e){
          return i;
        }
      }
      cout << "No se ha encontrado el elemento en el array" << endl;
      return -1;
    }


    bool empty() override{
      if(n==0){
        cout << "La lista esta vacía" << endl;
        return true;
      }else{
        cout << "La lista no esta vacía" << endl;;
        return false;
      }
    }




};
