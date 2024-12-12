#include <iostream>

using namespace std;

struct car {
    int number = 1000;
    string name = "name";
};

struct bus : car {
    string color = "red";
};
