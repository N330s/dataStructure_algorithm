#include <iostream>
#include <vector>

using namespace std;

int main () {
    int z;
    cin >> z;
    while (z--) {
        int n;
        cin >> n;
        vector<vector<double>>ex (n, vector<double> (n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> ex[i][j];
            }
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    ex[i][j] = max(ex[i][j], ex[i][k] * ex[k][j]);
                }
            }
        }
        bool check = false;
        for (int i = 0; i < n; i++) {
            if (ex[i][i] > 1) {
                check = true;
                break;
            }
        }
        cout << (check ? "YES" : "NO") << endl;
    }
}