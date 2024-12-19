#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &A, int p, int q, int r) {
    int nL = q - p +1;
    int nR = r - q;
    vector<int> L(nL, -1);
    vector<int> R(nR, -1);
    for (int i = 0; i < nL; i++) {
        L[i] = A[p+i];
    }
    for (int j = 0; j < nR; j++) {
        R[j] = A[q+j+1];
    }
    int i = 0;
    int j = 0;
    int k = p;
    while ((i < nL) && (j < nR)) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < nL) {
        A[k] = L[i];
        i++;
        k++;
    }
    while (j < nR) {
        A[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int> &v, int p, int r) {
    if (p >= r) return;
    int q = p + (r-p)/ 2 ;
    mergeSort(v, p ,q);
    mergeSort(v, q+1, r);
    merge(v,p,q,r);
}

template <typename T>

void print(T container) {
    for (auto c : container) {
        cout << c << " ";
    }
}

int main() {
    vector<int> v = {2, 9, 7, 5, 100, 1};
    int p = 0;
    int r = v.size() - 1;
    mergeSort(v, p, r);
    print(v);
    return 0;
}