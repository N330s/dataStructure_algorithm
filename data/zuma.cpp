#include <iostream>
#include <list>
#include <iterator>

using namespace std;

void check(list<int>& zum, list<int>::iterator itr) {
    auto itrBack = itr;
    auto itrFor = itr;
    int count = 1;
    while (itrBack != zum.end()) {
        itrBack--;
        if (*itrBack != *itr) break;
        count++;
    }
    while (itrFor != zum.begin()) {
        itrFor++;
        if (*itrFor != *itr) break;
        count ++;
    }
    if (count >= 3) {
        itr = zum.erase(++itrBack, itrFor);
        if (zum.size() < 3) return;
        check(zum, --itr);
    }
}

int main() {
    int n, k, v;
    list<int> zum;
    cin >> n >> k >>v;
    while (n--) {
        int inp;
        cin >> inp;
        zum.push_back(inp);
    }
    auto pos = zum.begin();
    advance(pos, k);
    auto itr = zum.insert(pos, v);
    check(zum, itr);
    for (int& x : zum) {
        cout << x << " ";
    }

}