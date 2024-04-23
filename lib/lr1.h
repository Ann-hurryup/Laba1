#pragma once
#include <vector>
#include <string>
#include <cmath>
using namespace std;


struct find_and_multiply_result{
    int min_index;
    int min_value;
    vector<int> array;
    vector<string> errors_array;
};

find_and_multiply_result find_and_multiply(vector<int> array);



