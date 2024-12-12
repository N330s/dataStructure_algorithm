#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <string>

using std::string;
using namespace std;

void change_1(std::stack<std::vector<std::queue<int>>> &a, int from, int to)
{
    // your code here
    std::stack<std::vector<std::queue<int>>> dup;
    while (a.size() > 0) {
        auto vec = a.top();
        a.pop();
        for (auto& i : vec) {
            queue<int> q;
            while (i.size() > 0) {
                int j = i.front();
                i.pop();
                q.push((j == from) ? to : j);
            }
            i = q;
        }
        dup.push(vec);
    }
    while (dup.size() > 0) {
        auto vec = dup.top();
        dup.pop();
        a.push(vec);
    }
}

void change_2(std::map<string, std::pair<std::priority_queue<int>, int>> &a, int from, int to)
{
    // your code here
    for (auto &i : a) {
        if (i.second.second == from) {
            i.second.second = to;
        }
        priority_queue<int> pq;
        while (i.second.first.size() > 0) {
            int j = i.second.first.top();
            i.second.first.pop();
            pq.push((j == from) ? to : j);
        }
        i.second.first = pq;
    }
}

void change_3(std::set<std::pair<std::list<int>, std::map<int, std::pair<int, string>>>> &a, int from, int to)
{
    // your code here
    set<pair<list<int>, map<int, pair<int, string>>>> dup;
    for (auto &i : a) {
        list<int> list;
        map<int, pair<int, string>> map;
        for (auto &j : i.first) {
            int val = (j == from) ? to : j;
            list.push_back(val);
        }
        for (auto &k : i.second) {
            int key = (k.first == from) ? to : k.first;
            auto value = make_pair((k.second.first == from) ? to : k.second.first, k.second.second);
            map[key] = value;
        }
        dup.insert(make_pair(list, map));
    }
    a = dup;
}

#endif
