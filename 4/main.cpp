#include <iostream>
#include <chrono>
#include <fstream>
#include <vector>
#include <cstdlib >

using namespace std;

int main() {
    ofstream fout("4.txt");
    vector<int> a;
    a.push_back(1);
    for (int i = 0; i < 100000000; i++) {
        a.push_back(i);
    }
    for (int j = 1000; j <= 100000000; j += 1000) {
        auto begin = chrono::high_resolution_clock::now();
        for (int i = 0; i < j; i+=j/1000) {
            a[i]++; a[i]--; a[i]++; a[i]--; a[i]++; a[i]++; a[i]--; a[i]++; a[i]--; a[i]++;
            a[i]++; a[i]--; a[i]++; a[i]--; a[i]++; a[i]++; a[i]--; a[i]++; a[i]--; a[i]++;
            a[i]++; a[i]--; a[i]++; a[i]--; a[i]++; a[i]++; a[i]--; a[i]++; a[i]--; a[i]++;
            a[i]++; a[i]--; a[i]++; a[i]--; a[i]++; a[i]++; a[i]--; a[i]++; a[i]--; a[i]++;
            a[i]++; a[i]--; a[i]++; a[i]--; a[i]++; a[i]++; a[i]--; a[i]++; a[i]--; a[i]++;
            a[i]++; a[i]--; a[i]++; a[i]--; a[i]++; a[i]++; a[i]--; a[i]++; a[i]--; a[i]++;
            a[i]++; a[i]--; a[i]++; a[i]--; a[i]++; a[i]++; a[i]--; a[i]++; a[i]--; a[i]++;
            a[i]++; a[i]--; a[i]++; a[i]--; a[i]++; a[i]++; a[i]--; a[i]++; a[i]--; a[i]++;
            a[i]++; a[i]--; a[i]++; a[i]--; a[i]++; a[i]++; a[i]--; a[i]++; a[i]--; a[i]++;
            a[i]++; a[i]--; a[i]++; a[i]--; a[i]++; a[i]++; a[i]--; a[i]++; a[i]--; a[i]++;
            a[i]++; a[i]--; a[i]++; a[i]--; a[i]++; a[i]++; a[i]--; a[i]++; a[i]--; a[i]++;
            a[i]++; a[i]--; a[i]++; a[i]--; a[i]++; a[i]++; a[i]--; a[i]++; a[i]--; a[i]++;
            a[i]++; a[i]--; a[i]++; a[i]--; a[i]++; a[i]++; a[i]--; a[i]++; a[i]--; a[i]++;
            a[i]++; a[i]--; a[i]++; a[i]--; a[i]++; a[i]++; a[i]--; a[i]++; a[i]--; a[i]++;
            a[i]++; a[i]--; a[i]++; a[i]--; a[i]++; a[i]++; a[i]--; a[i]++; a[i]--; a[i]++;
            a[i]++; a[i]--; a[i]++; a[i]--; a[i]++; a[i]++; a[i]--; a[i]++; a[i]--; a[i]++;
            a[i]++; a[i]--; a[i]++; a[i]--; a[i]++; a[i]++; a[i]--; a[i]++; a[i]--; a[i]++;
            a[i]++; a[i]--; a[i]++; a[i]--; a[i]++; a[i]++; a[i]--; a[i]++; a[i]--; a[i]++;
            a[i]++; a[i]--; a[i]++; a[i]--; a[i]++; a[i]++; a[i]--; a[i]++; a[i]--; a[i]++;
            a[i]++; a[i]--; a[i]++; a[i]--; a[i]++; a[i]++; a[i]--; a[i]++; a[i]--; a[i]++;
            a[i]++; a[i]--; a[i]++; a[i]--; a[i]++; a[i]++; a[i]--; a[i]++; a[i]--; a[i]++;
            a[i]++; a[i]--; a[i]++; a[i]--; a[i]++; a[i]++; a[i]--; a[i]++; a[i]--; a[i]++;
            a[i]++; a[i]--; a[i]++; a[i]--; a[i]++; a[i]++; a[i]--; a[i]++; a[i]--; a[i]++;
            a[i]++; a[i]--; a[i]++; a[i]--; a[i]++; a[i]++; a[i]--; a[i]++; a[i]--; a[i]++;
            a[i]++; a[i]--; a[i]++; a[i]--; a[i]++; a[i]++; a[i]--; a[i]++; a[i]--; a[i]++;
            a[i]++; a[i]--; a[i]++; a[i]--; a[i]++; a[i]++; a[i]--; a[i]++; a[i]--; a[i]++;
            a[i]++; a[i]--; a[i]++; a[i]--; a[i]++; a[i]++; a[i]--; a[i]++; a[i]--; a[i]++;
            a[i]++; a[i]--; a[i]++; a[i]--; a[i]++; a[i]++; a[i]--; a[i]++; a[i]--; a[i]++;
            a[i]++; a[i]--; a[i]++; a[i]--; a[i]++; a[i]++; a[i]--; a[i]++; a[i]--; a[i]++;
            a[i]++; a[i]--; a[i]++; a[i]--; a[i]++; a[i]++; a[i]--; a[i]++; a[i]--; a[i]++;
            a[i]++; a[i]--; a[i]++; a[i]--; a[i]++; a[i]++; a[i]--; a[i]++; a[i]--; a[i]++;
            a[i]++; a[i]--; a[i]++; a[i]--; a[i]++; a[i]++; a[i]--; a[i]++; a[i]--; a[i]++;
            a[i]++; a[i]--; a[i]++; a[i]--; a[i]++; a[i]++; a[i]--; a[i]++; a[i]--; a[i]++;
            a[i]++; a[i]--; a[i]++; a[i]--; a[i]++; a[i]++; a[i]--; a[i]++; a[i]--; a[i]++;
            a[i]++; a[i]--; a[i]++; a[i]--; a[i]++; a[i]++; a[i]--; a[i]++; a[i]--; a[i]++;
            a[i]++; a[i]--; a[i]++; a[i]--; a[i]++; a[i]++; a[i]--; a[i]++; a[i]--; a[i]++;
            a[i]++; a[i]--; a[i]++; a[i]--; a[i]++; a[i]++; a[i]--; a[i]++; a[i]--; a[i]++;
            a[i]++; a[i]--; a[i]++; a[i]--; a[i]++; a[i]++; a[i]--; a[i]++; a[i]--; a[i]++;
            a[i]++; a[i]--; a[i]++; a[i]--; a[i]++; a[i]++; a[i]--; a[i]++; a[i]--; a[i]++;
            a[i]++; a[i]--; a[i]++; a[i]--; a[i]++; a[i]++; a[i]--; a[i]++; a[i]--; a[i]++;
        }
        auto end = chrono::high_resolution_clock::now();
        fout << j << " " << chrono::duration_cast<chrono::nanoseconds>(end - begin).count() / 400 << endl;
    }
    fout.close();
    a.clear();
    return 0;
}
