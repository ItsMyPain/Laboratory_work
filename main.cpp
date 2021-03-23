#include <iostream>
#include <chrono>
#include <fstream>
#include <list>
#include <cstdlib>

using namespace std;

int main() {
    ofstream fout("5.txt");
    list<int> a;
    //a.push_back(1);
    for (int i = 0; i < 100000; i++) {
        auto begin = chrono::high_resolution_clock::now();
        for (int j = 0; j < 1000; j++)
            a.push_back(1);
        auto end = chrono::high_resolution_clock::now();
        //if (i % 100 == 0)
        fout << chrono::duration_cast<chrono::nanoseconds>(end - begin).count() / 1000 << " " << a.size() << endl;
    }
    fout.close();
    return 0;
}
