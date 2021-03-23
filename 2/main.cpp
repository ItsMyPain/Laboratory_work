#include <iostream>
#include <chrono>
#include <fstream>
#include <vector>
#include <cstdlib>

using namespace std;

int main() {
    ofstream fout("2.txt");
    vector<long long int> a;
    a.push_back(1);
    a.push_back(1);
    for (long long int i = 1300000; i < 10000000000; i += 1000) {
        auto begin = chrono::high_resolution_clock::now();
        a.insert(a.begin() + (rand() % a.size()), i);
        auto end = chrono::high_resolution_clock::now();
        fout << chrono::duration_cast<chrono::microseconds>(end - begin).count() << " " << a.size() << endl;
    }
    fout.close();
    return 0;
}
