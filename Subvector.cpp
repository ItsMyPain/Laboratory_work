#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class sub_vector{
public:

    sub_vector(){
        init();
    }
    void init(){
        top=0;
        capacity=0;
        data = nullptr;
    }

    void init(int n){
        delete[] data;
        data = new int[n];
        top = n;
        capacity = n+1;
        srand(time(0));
        for (int i = 0; i < top; i++) {
            data[i]=rand() % 1000;
        }
    }

    int& operator[](const int index){
        return data[index];
    }

    void erase(int position){
        int *p = new int[capacity];
        top--;
        for(int i = 0; i < position; i++){
            p[i] = data[i];
        }
        for(int i = position; i < top; i++){
            p[i] = data[i+1];
        }
        delete[] data;
        data = p;
    }

    void insert(int position, int value){
        if(top+1 >= capacity)   capacity++;
        int *p = new int[capacity];
        top++;
        for(int i = 0; i < top; i++){
            p[i] = data[i];
        }
        p[position] = value;
        for(int i = position + 1; i < top; i++){
            p[i] = data[i-1];
        }
        delete[] data;
        data = p;
    }
    void print(){
        for(int i=0; i < top; i++){
            cout<<data[i]<<" ";
        }
        cout<<endl;
    }
    void push_back(int a){
        if(top>=capacity){
            capacity++;
            int* p = new int[capacity];
            for(unsigned int i=0; i<top; i++){
                p[i]=data[i];
            }
            p[top]=a;
            top++;
            delete[] data;
            data=p;

        }
        else{
            data[top] = a;
            top++;

        }
    }


    int pop_back(){
        if(top>0){
            top--;
            int* p= new int [capacity];
            for(int i=0; i<top; i++){
                p[i]=data[i];
            }
            delete[] data;
            data = p;
            return 1;
        }
        else{
            return 0;
        }
    }

    void resize(unsigned int new_capacity){
        if(new_capacity >= capacity){
            capacity = new_capacity;
            int* p= new int [capacity];
            for(int i=0; i<top; i++){
                p[i]=data[i];
            }
            delete[] data;
            data = p;
        }
    }

    void shrink_to_fit(){
        capacity = top;
        int* p= new int [capacity];
        for(int i=0; i<top; i++){
            p[i]=data[i];
        }
        delete[] data;
        data = p;
    }

    void clear(){
        top=0;
        int* p= new int [capacity];
        delete[] data;
        data = p;
    }

    ~sub_vector(){
        delete[] data;
        top=0;
        capacity=0;
        data = nullptr;

    }

private:
    unsigned int top;
    unsigned int capacity;
    int* data;

};
