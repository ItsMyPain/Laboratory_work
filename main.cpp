#include <iostream>
#include <chrono>
#include <fstream>
#include <forward_list>
#include <cstdlib>
#include <ctime>
#include "SubList.cpp"

using namespace std;

int main() {
    ofstream fout("63.txt");
    forward_list<int> a;
    listt suba;

    for (int i = 0; i < 100000; i++) {
        a.push_front(1);
        suba.push_forward(1);
    }

    for (int i = 100000; i < 10000000; i += 100) {
        for (int k = 0; k < 100; k++)
            a.push_front(1);
        auto begin1 = chrono::high_resolution_clock::now();
        for (int j = 0; j < 1000; j++) {
            a.pop_front();
            a.push_front(1);
        }
        auto end1 = chrono::high_resolution_clock::now();
//        auto begin2 = chrono::high_resolution_clock::now();
//        for (int j = 0; j < 1; j++)
//            suba.pop_forward();
//        auto end2 = chrono::high_resolution_clock::now();

        fout << chrono::duration_cast<chrono::nanoseconds>(end1 - begin1).count() << " " << i + 100
             << endl;
    }

    fout.close();

    return 0;
}
