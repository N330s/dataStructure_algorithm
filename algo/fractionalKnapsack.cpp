#include <iostream>
#include <queue>
#include <iomanip>

using namespace std;

int main() {
    double w = 0;
    int n;
    cin >> w >> n;
    vector<double> price(n);
    vector<double> weight(n);
    double currWeight = 0;
    double currPrice = 0;
    priority_queue<pair<double, pair<double, double>>> pq;
    for (int i = 0; i < n; i++) cin >> price[i];
    for (int i = 0; i < n; i++) cin >> weight[i];
    for (int i = 0; i < n; i++) {
        double pw = price[i] / weight[i];
        pq.push(make_pair(pw, make_pair(weight[i], price[i])));
    }
    while (currWeight < w && !pq.empty()) {
        auto top = pq.top();
        if (currWeight + top.second.first <= w) {
            currWeight += top.second.first;
            currPrice += top.second.second;
        }
        else {
            double leftWeight = w - currWeight;
            currPrice += top.first * leftWeight;
            currWeight = w;
            break;
        }
        pq.pop();
    }
    cout << fixed << setprecision(4);
    cout << currPrice;
}