#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int n, m;
    vector<int> list;
    unordered_set<int> list2;
    cin >> n >> m;
    while (n--) {
        int inp;
        cin >> inp;
        list.push_back(inp);
    }
    while (m--) {
        int inp;
        cin >> inp;
        bool check = false;
        for (int i = 0; i < list.size(); i++) {
            if (list2.find(list[i]) != list2.end()) {
                check = true;
                break;
            }
            list2.insert(inp - list[i]);
        }
        if (check) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
        list2.clear();
    }
}