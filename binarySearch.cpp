#include <vector>
#include <iostream>

using namespace std;

int binarySearchHelper(const vector<int>& v, int target, int left, int right) {
    if (left > right) {
        cout << "\nNOT FOUND";
        return -1;
    }

    int mid = left + (right - left) / 2;

    if (v[mid] == target) return v[mid];
    else if (v[mid] < target) return binarySearchHelper(v, target, mid + 1, right);
    else return binarySearchHelper(v, target, left, mid - 1);
}

int binarysearch(const vector<int>& v, int target) {
    return binarySearchHelper(v, target, 0, v.size() - 1);
}

int main() {
    vector<int> v = {12, 3, 7, 9, 14, 6 , 11, 2};
    int target = 11;
    int result = binarysearch(v, target);

    if (result != -1) {
        cout << "Found: " << result << endl;
    }

    return 0;
}
