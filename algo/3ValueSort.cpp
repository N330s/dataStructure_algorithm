#include <iostream> 
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    int result = 0;
    int count[4] = {0};
    vector<int> data;
    for (int i = 0 ; i < n; i++) {
        int inp;
        cin >> inp;
        count[inp] += 1;
        data.push_back(inp);
    }
    for (int i = 0; i < count[1]; i++) {
        if (data[i] > 1) {
            bool swapped = false;
            if (data[i] == 2) {
                for (int j = count[1]; j < count[1] + count[2]; j++) {
                    if (data[j] == 1) {
                        swap(data[i], data[j]);
                        result++;
                        swapped = true;
                        break;
                    }
                }
                if (!swapped) {
                    for (int j = count[1] + count[2]; j < n; j++) {
                        if (data[j] == 1) {
                            swap(data[i], data[j]);
                            result++;
                            swapped = true;
                            break;
                        }
                    }
                }
            }
            else if (data[i] == 3) {
                for (int j = count[1] + count[2]; j < n; j++) {
                    if (data[j] == 1) {
                        swap(data[i], data[j]);
                        result++;
                        swapped = true;
                        break;
                    }
                }
                if (!swapped) {
                    for (int j = count[1]; j < count[1] + count[2]; j++) {
                        if (data[j] == 1) {
                            swap(data[i], data[j]);
                            result++;
                            swapped = true;
                            break;
                        }
                    }
                }
            }
        }
    }
    for (int i = count[1]; i < count[1] + count[2]; i++) {
        if(data[i] > 2) {
            for (int j = count[1] + count[2]; j < n; j++) {
                if (data[j] == 2) {
                    swap(data[i], data[j]);
                    result++;
                    break;
                }
            }
        }
    }
    cout << result;
}
