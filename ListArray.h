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
        delete arr;
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
        delete arr;
      }


      T operator[](int pos){
        if(pos<0 || pos>size()){
          throw out_of_range("Posición no válida");
        }else{
          return arr[pos];
        }
      }


      friend ostream& operator<<(ostream &out, const ListArray<T> &list){
        out << list.arr;
        return out;
      }



      //miembros heredados de List<T>

      int size() override{
        return max;
      }

      void insert(int pos, T e) override{
        if(pos<0 || pos>size()){
          throw out_of_range("Posición no válida");
        }else{

          resize(size() +1);
          for(int i=max ; i>=pos ; i--){
            if(i==pos){
              arr[i]=e;
            }else{
              arr[i]=arr[i-1];
            }
          }
        }
      }

      void append(T e) override{
        resize(size() +1);
        arr[max] = e;
      }

      void prepend(T e) override{
        resize(size() +1);
        for(int i=max ; i >= 0 ; i--){
          if(i==0){
            arr[i]=e;
          }else{
            arr[i]=arr[i-1];
          }
        }
      }


    T remove(int pos) override{
      if(pos<0 || pos>size()){
        throw out_of_range("Posición no válida");
      }else{
        int aux = arr[pos];
        for(int i=pos ; i<max ; i++){
          arr[i]=arr[i+1];
        }
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
      return -1;
    }


    bool empty() override{
      if(n==0){
        cout << "La lista esta vacía";
        return true;
      }else{
        cout << "La lista no esta vacía";
        return false;
      }
    }




};
