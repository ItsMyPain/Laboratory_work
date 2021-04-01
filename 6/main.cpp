#include <iostream>
#include <chrono>
#include <fstream>
#include <forward_list>
#include <cstdlib>
#include <ctime>
#include "SubList.cpp"

using namespace std;

int main() {
    ofstream fout("5.txt");
    forward_list<int> a;
    listt suba;

    for (int i = 0; i < 5000000; i++) {
        a.push_front(1);
        suba.push_forward(1);
    }

    for (int i = 0; i < 500; i++) {
        auto begin1 = chrono::high_resolution_clock::now();
        for (int j = 0; j < 10000; j++)
            a.pop_front();
        auto end1 = chrono::high_resolution_clock::now();

        auto begin2 = chrono::high_resolution_clock::now();
        for (int j = 0; j < 10000; j++)
            suba.pop_forward();
        auto end2 = chrono::high_resolution_clock::now();

        fout << chrono::duration_cast<chrono::microseconds>(end1 - begin1).count() << " "
             << chrono::duration_cast<chrono::microseconds>(end2 - begin2).count() << " " << 5000000 - (i + 1) * 10000
             << endl;
    }

    fout.close();

    return 0;
}
