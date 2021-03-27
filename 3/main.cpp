#include <iostream>
#include <chrono>
#include <fstream>
#include <vector>
#include <cstdlib>
#include "Subvector.cpp"

using namespace std;

int main() {
    ofstream fout("3.txt");
    vector<int> a;
    sub_vector suba;
    suba.init(5000000);
    for (long long int i = 0; i < 5000000; i++) {
        a.push_back(i);
    }

    for (long long int i = 1; i < 5000; i++) {
        auto begin1 = chrono::high_resolution_clock::now();
        for (int j = 0; j < 1000; j++)
            a.erase(a.begin() + (rand() % a.size()));
        auto end1 = chrono::high_resolution_clock::now();

        auto begin2 = chrono::high_resolution_clock::now();
        for (int j = 0; j < 1000; j++)
            suba.erase((rand() % i));
        auto end2 = chrono::high_resolution_clock::now();

        fout << chrono::duration_cast<chrono::microseconds>(end1 - begin1).count() / 1000 << " "
             << chrono::duration_cast<chrono::microseconds>(end2 - begin2).count() / 1000 << " " << a.size() << endl;
    }
    fout.close();
    return 0;
}
