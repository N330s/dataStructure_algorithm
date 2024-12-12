#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>


using namespace std;
unordered_map<int, int> m;

void permu(int n, vector<int> s, vector<bool> used) {
   if (s.size() == n) {
        for (int i = 0; i < n; i++) cout << s[i] << " ";
        cout << "\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        if ((!used[i]) && (!m.count(i) || used[m[i]])) {
            used[i] = true;
            s.push_back(i);
            permu(n, s, used);
            s.pop_back();
            used[i] = false;
        }
    }

}

int main() {
    int n, k;
    cin >> n >> k;
    vector<bool> used(n, false);
    for (int i = 0; i < k; i++) {
        int inp1, inp2;
        cin >> inp1 >> inp2;
        m[inp2] = inp1;
    }    
    vector<int> s;
    permu(n, s, used);
}