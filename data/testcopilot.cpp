#include <iostream> 
#include <vector>

using namespace std;

void heapify(vector<int>& list, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && list[left] > list[largest]) {
        largest = left;
    }
    if (right < n && list[right] > list[largest]) {
        largest = right;
    }
    if (largest != i) {
        swap(list[i], list[largest]);
        heapify(list, n, largest);
    }
}

void heapSort(vector<int>& list) {
    int n = list.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(list, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        swap(list[0], list[i]);
        heapify(list, i, 0);
    }
}

void printArray(vector<int>& list) {
    for (int i = 0; i < list.size(); i++) {
        cout << list[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> list = {12, 11, 13, 5, 6, 7};
    heapSort(list);
    printArray(list);
}