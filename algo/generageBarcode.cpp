#include <iostream>

using namespace std;

void recur (int a, int b, string s, int w) {
    if (b-s.size() == 0) {
        cout << s << endl;
        return;
    }
    if (b-s.size() == a - w) {
        for (int i = 0; i <= b-s.size(); i++) {
            s.push_back('1');
            w+=1;
        }
        recur (a, b, s, w);
        return;
    } 
    if (w == a) {
        for (int i = 0; i <= b-s.size(); i++) {
            s.push_back('0');
        }
        recur (a,b,s,w);
        return;
    }
    s.push_back('0');
    recur(a,b,s,w);
    s.back() = ('1');
    recur(a,b,s,w+1);
}

int main() {
    string s = "";
    int a, b;
    cin >> a >> b;
    recur (a,b,s,0);
}