#include <iostream>
#include <vector>

using namespace std;

void selectionSort(vector<int> & v) {
    int n = v.size();
    int key;
    for (int i = 0; i < n - 1; i++) {
        int smallest = v[i];
        for (int j = i; j < n; j++) {
            if (v[j] <= smallest) {
                smallest = v[j];
                key = j;
                v[key] = v[i];
                v[i] = smallest;
            }
        }
    }
}

template <typename T>

void print(T container) {
    for (auto c : container) {
        cout << c << " ";
    }
}

int main() {
    vector<int> v = {2, 4, 6, 100, 1, -1, 8, 23, 0, 1};
    selectionSort(v);
    print(v);
    return 0;
}