#include <iostream>
#include <vector>

using namespace std;

void insertSort(vector<int> & v) {
    int n = v.size();
    for (int i = 1; i < n; i++) {
        int key = v[i];
        int j = i-1;
        while (j >= 0 && v[j] > key) {
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = key;
    }
}

template <typename T>

void print(T container) {
    for (auto c : container) {
        cout << c << " ";
    }
}

int main() {
    vector<int> v = {2, 9, 7, 5, 100, 1};
    insertSort(v);
    print(v);
    return 0;
}