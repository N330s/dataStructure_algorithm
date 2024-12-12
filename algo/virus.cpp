#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool check(string s) {
    if (s.size() == 2) {
        return s == "01";
    }
    string rev;
    for (int i = 0; i < s.size()/2; i++) {
        rev.push_back(s[s.size()/2-1-i]);
    }
    return (check(s.substr(0, s.size()/2)) || check(rev)) && check (s.substr(s.size()/2, s.size()/2));
}

int main() {
    string s;
    int n, k;
    cin >> n >> k;
    k = pow(2, k);
    for (int i = 0; i < k; i++) {
        s.push_back('0');
    }
    while (n--) {
        for (int i = 0; i < k; i++) {
            cin >> s[i];
        }
        if (check(s)) {
            cout << "yes" << endl;
        }
        else {
            cout << "no" << endl;
        }
    } 
}