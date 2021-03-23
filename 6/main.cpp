#include <iostream>
#include <chrono>
#include <fstream>
#include <list>
#include <cstdlib>

using namespace std;

int main() {
    ofstream fout("6.txt");
    list<int> a;
    for (int i = 0; i < 10000000; i++)
        a.push_back(1);

    for (int i = 0; i < 10000000; i++) {
        auto begin = chrono::high_resolution_clock::now();
        for (int j = 0; j < 100; j++)
            a.pop_front();
        auto end = chrono::high_resolution_clock::now();
        //if (i % 100 == 0)
        fout << a.size() << " " << chrono::duration_cast<chrono::nanoseconds>(end - begin).count() / 100 << endl;
    }
    fout.close();
    return 0;
}
