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

    // srand(time(NULL));

    for (int i = 0; i < 500; i++) {
        auto begin1 = chrono::high_resolution_clock::now();
        for (int j = 0; j < 10000; j++)
            a.push_front(1);
        auto end1 = chrono::high_resolution_clock::now();

        auto begin2 = chrono::high_resolution_clock::now();
        for (int j = 0; j < 10000; j++)
            suba.push_forward(1);
        auto end2 = chrono::high_resolution_clock::now();

        fout << chrono::duration_cast<chrono::microseconds>(end1 - begin1).count() << " "
             << chrono::duration_cast<chrono::microseconds>(end2 - begin2).count() << " " << (i + 1) * 10000
             << endl;
    }

    fout.close();

    return 0;
}
