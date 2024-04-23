#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <utility>
#include "../../lib/lr1.h"
#include "json.hpp"
using namespace std;

//string filename = "services/tests/generated_tests.json";

struct testData {
    vector<int> input;
    find_and_multiply_result output;
};

void writeTestToJsonFile(vector<int> inputArray, find_and_multiply_result correctResult, string testName);

map<string, testData> readTestFromJsonFile();
map<string, testData> readTestFromJsonFileWithParam(string testName);

void clearFile();

#ifndef INC_1_FILE_H
#define INC_1_FILE_H
#endif //INC_1_FILE_H