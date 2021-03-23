#include <iostream>
#include <chrono>
#include <fstream>
#include <vector>
#include <cstdlib >

using namespace std;

int main() {
    ofstream fout("3.txt");
    vector<long long int> a;
    a.push_back(1);
    for (long long int i = 0; i < 10000000; i++) {
        a.push_back(i);
    }

    for (long long int i = 0; i < 10000000; i++) {
        auto begin = chrono::high_resolution_clock::now();
        a.erase(a.begin() + (rand() % a.size()));
        auto end = chrono::high_resolution_clock::now();
        if (i % 100  == 0)
            fout << chrono::duration_cast<chrono::microseconds>(end - begin).count() << " " << a.size() << endl;
    }
    fout.close();
    return 0;
}
