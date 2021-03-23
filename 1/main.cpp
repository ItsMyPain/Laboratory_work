#include <iostream>
#include <chrono>
#include <fstream>
#include <vector>
#include <cstdlib >

using namespace std;

int main() {
    ofstream fout("1.txt");
    vector<long long int> a;
    a.push_back(1);
    for (long long int i = 0; i < 1000000; i++) {
        a.push_back(i);
        fout << a.size() << " " << a.capacity() << i << endl;
    }
    fout.close();
    return 0;
}
