#include <iostream> 
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> degree(n-1, 0);
    int k = 0;
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            int inp;
            cin >> inp;
            count += inp;
        }
        degree[count] += 1;
        k = max(k, count);
    }
    for (int i = 0; i <= k; i++) {
        cout << degree[i] <<  " ";
    }
}