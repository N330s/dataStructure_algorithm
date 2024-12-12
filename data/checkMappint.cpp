#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string is_permutation(int n, vector<int>& sequence) {
    // Sort the sequence
    sort(sequence.begin(), sequence.end());
    
    // Check if it matches [1, 2, ..., n]
    for (int i = 0; i < n; ++i) {
        if (sequence[i] != i + 1) {
            return "NO";
        }
    }
    return "YES";
}

int main() {
    int n;
    cout << "Enter n (size of set A): ";
    cin >> n;

    vector<int> sequence(n);
    cout << "Enter " << n << " integers representing the sequence d1, d2, ..., dn: ";
    for (int i = 0; i < n; ++i) {
        cin >> sequence[i];
    }

    // Check if the sequence is a permutation
    cout << is_permutation(n, sequence) << endl;

    return 0;
}
