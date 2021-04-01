#include <iostream>
#include <chrono>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Subvector.cpp"

using namespace std;

int main() {
    ofstream fout("4+.txt");
    vector<int> a;
    vector<int> b;
    sub_vector suba;
    srand(time(NULL));
//    suba.init(1000);
//    for (int i = 0; i < 1000; i++) {
//        a.push_back(1);
//    }

    for (int k = 0; k < 10000000; k++) {
        b.push_back(rand() % 500);
    }
    for (int i = 500; i <= 200000; i += 500) {
        a.resize(i);
        suba.init(i);
        for (int k = 0; k < 10000000; k++) {
            b[k]= rand() % i;
        }

        auto begin1 = chrono::high_resolution_clock::now();
        for (int j = 0; j < 10000000; j++) {
            a[b[j]]++;
            a[b[j]]--;
        }
        auto end1 = chrono::high_resolution_clock::now();

        auto begin2 = chrono::high_resolution_clock::now();
        for (int j = 0; j < 10000000; j++) {
            suba[b[j]]++;
            suba[b[j]]--;
        }
        auto end2 = chrono::high_resolution_clock::now();

        fout << chrono::duration_cast<chrono::microseconds>(end1 - begin1).count() / 2000 << " "
             << chrono::duration_cast<chrono::microseconds>(end2 - begin2).count() / 2000 << " " << a.size() << endl;
    }

    fout.close();

    return 0;
}
