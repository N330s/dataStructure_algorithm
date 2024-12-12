#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> num(pow(2, k-1));
    while (n--) {
        bool valid = true;
        for (int i = 0; i < num.size(); i++) {
            int inp1, inp2;
            cin >> inp1 >> inp2;
            num[i] = inp1 + inp2;
        }
        int space = 1;
        while (space <= num.size() / 2) {
            for (int i = 0; i < num.size(); i+= space) {
                int j = i + space;
                if (abs(num[i] - num[j]) > 1) {
                    valid = false;
                    break;
                }
                num[i] += num[j];
                i += space;
            }
            space *= 2;
        }
        if (valid) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}