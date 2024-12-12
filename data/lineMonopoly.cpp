#include <iostream>
#include <map>
#include <algorithm>

int main(int argc, char const *argv[])
{
  std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
  int n, chs, inp1, inp2 = 0;
  std::map<int, int> bought;
  std::cin >> n;
  while (n--) {
    std::cin >> chs;
    if (chs == 1) {
      std::cin >> inp1 >> inp2;
      if(bought[inp1] < inp2) {
        bought[inp1] = inp2;
        auto i = bought.find(inp1);
        if (i != bought.begin()) i--; 
        int count = 0;
        while (true) {
          auto it = next(i);
          if (it == bought.end()) break;
          if (i->second >= it->first - 1) {
            if (i->second < it->second) {
              count--;
              i->second = it->second;
            }
            i = bought.erase(it);
            i--;
          }
          else i++;
          count++;
          if (count > 2) {
            break;
          }
        }
      }
    }
    else {
      std::cout << bought.size() << "\n";
    }
  }
}