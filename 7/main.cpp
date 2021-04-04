#include <iostream>
#include <chrono>
#include <fstream>
#include <vector>
#include <forward_list>
#include <list>
#include <set>
#include <map>

using namespace std;

template<typename T>
void FillL(T &obj) {
    for (int i = 0; i < 1000; i++)
        obj.push_front(1);
} 

void Fill(vector<int> &obj) {
    for (int i = 0; i < 1000; i++)
        obj.push_back(1);
}

void TimeV(vector<int> &a) {
    ofstream fout("7V.txt");
    for (int i = 0; i < 5000; i++) {
        Fill(a);
        auto begin = chrono::high_resolution_clock::now();
        for (auto it = a.begin(); it != a.end(); ++it)
            *it++;
        auto end = chrono::high_resolution_clock::now();
        fout << chrono::duration_cast<chrono::microseconds>(end - begin).count() / 1000.0 << " " << a.size() << endl;
    }
    fout.close();
    a.resize(1);
}

void TimeFL(forward_list<int> &a) {
    ofstream fout("7FL.txt");
    for (int i = 0; i < 5000; i++) {
        FillL(a);
        auto begin = chrono::high_resolution_clock::now();
        for (auto it = a.begin(); it != a.end(); ++it)
            *it++;
        auto end = chrono::high_resolution_clock::now();
        fout << chrono::duration_cast<chrono::microseconds>(end - begin).count() / 1000.0 << " " << 1000 * (i + 1)
             << endl;
    }
    fout.close();
    a.resize(1);
}

void TimeL(list<int> &a) {
    ofstream fout("7L.txt");
    for (int i = 0; i < 5000; i++) {
        FillL(a);
        auto begin = chrono::high_resolution_clock::now();
        for (auto it = a.begin(); it != a.end(); ++it)
            *it++;
        auto end = chrono::high_resolution_clock::now();
        fout << chrono::duration_cast<chrono::microseconds>(end - begin).count() / 1000.0 << " " << 1000 * (i + 1)
             << endl;
    }
    fout.close();
    a.resize(1);
}

void TimeS(set<int> &a) {
    ofstream fout("7S.txt");
    for (int i = 0; i < 5000; i++) {

        for (int k = 1000 * i; k < 1000 * (i + 1); k++)
            a.insert(k);

        auto begin = chrono::high_resolution_clock::now();
        for (auto it = a.begin(); it != a.end(); ++it)
            *it++;
        auto end = chrono::high_resolution_clock::now();
        fout << chrono::duration_cast<chrono::microseconds>(end - begin).count() / 1000.0 << " " << a.size() << endl;
    }
    fout.close();
    a.erase(a.begin(), a.end());
}

void TimeM(map<int, int> &a) {
    ofstream fout("7M.txt");
    for (int i = 0; i < 5000; i++) {

        for (int k = 1000 * i; k < 1000 * (i + 1); k++)
            a[k] = 1;

        auto begin = chrono::high_resolution_clock::now();
        for (auto it = a.begin(); it != a.end(); ++it)
            *it++;
        auto end = chrono::high_resolution_clock::now();
        fout << chrono::duration_cast<chrono::microseconds>(end - begin).count() / 1000.0 << " " << a.size() << endl;
    }
    fout.close();
    a.erase(a.begin(), a.end());
}

int main() {
    vector<int> vector1;
    forward_list<int> forwardList1;
    list<int> list1;
    set<int> set1;
    map<int, int> map1;

    TimeV(vector1);
    TimeFL(forwardList1);
    TimeL(list1);
    TimeS(set1);
    TimeM(map1);


    return 0;
}
