#include "generate_tests.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <random>
#include "../../lib/lr1.h"
#include "../../services/file/file_test.h"
using namespace std;

// генератор случайных чисел
std::random_device rd;
std::mt19937 gen(rd());
// любые два значения меньше этого не будут вызывать overflow при умножении друг на друга
int randomRangeMax = floor(sqrt(INT_MAX));

// функция для генерация случайного массива целых чисел указнного размера
vector<int> generateRandomInputArray(int array_size) {
    vector<int> input_array;
    for (int i = 1; i < array_size; i++) {
        input_array.push_back(rand());
    }
    return input_array;
}

// функция для генерациии массива на вход и получаемого массива со случайными элементами
// и с указаными параметрами таким образом, чтобы они содержали корректные данные
struct correctInputAndOutputArrays {vector<int> input_array; vector<int> output_array;};
correctInputAndOutputArrays generateCorrectInputAndOutputArrays(int array_size, int min_value, int min_index) {
    correctInputAndOutputArrays arrays;
    vector<int> input_array;
    vector<int> output_array;
    // здесь для генератора случайных чисел указывается диапозон минимума и максимума
    // конкретно в этом случае нужно сгенерировать случайное число таким образом,
    // чтобы при умножении его на минимальное значение не возникало overflow (см. выше randomRangeMax)
    std::uniform_int_distribution<> distr_dynamic(min_value, randomRangeMax);
    for (int i = 0; i < array_size; i++) {
        int currNumber = distr_dynamic(gen);
        if (i < min_index) {
            arrays.input_array.push_back(currNumber);
            arrays.output_array.push_back(currNumber * min_value);
        }
        else if (i == min_index) {
            arrays.input_array.push_back(min_value);
            arrays.output_array.push_back(min_value);
        }
        else {
            arrays.input_array.push_back(currNumber);
            arrays.output_array.push_back(currNumber);
        }
    }
    return arrays;
}

void generateTestsToFile() {
    srand((int)time(0));
    clearFile();

    vector<int> inputArray;
    find_and_multiply_result correct_result;
    string test_name;

    // для определения случайных чисел
    std::uniform_int_distribution<> distr_min_value(-randomRangeMax, randomRangeMax);
    int correct_min_value = distr_min_value(gen);

    // случайный размер массива и индекс минимального элемента
    std::uniform_int_distribution<> distr_2_1024(2, 1024);

    int array_size;
    vector<int> input_array;

    correct_result.errors_array = {"array empty"};
    writeTestToJsonFile({}, correct_result, "Пустой массив");

    correct_result.array = {1};
    correct_result.errors_array = {};
    writeTestToJsonFile({1}, correct_result, "Массив с одним элементом");

    test_name = "Массив с максимальным количеством элементов - 1";
    array_size = 1023;
    std::uniform_int_distribution<> distr_0_1023(0, 1023);
    correctInputAndOutputArrays arrays = generateCorrectInputAndOutputArrays(array_size, correct_min_value, distr_0_1023(gen));
    correct_result.array = arrays.output_array;
    writeTestToJsonFile(arrays.input_array, correct_result, test_name);
    correct_result.array = {};

    test_name = "Массив с максимальным количеством элементов";
    array_size = 1024;
    arrays = generateCorrectInputAndOutputArrays(array_size, correct_min_value, distr_2_1024(gen));
    correct_result.array = arrays.output_array;
    writeTestToJsonFile(arrays.input_array, correct_result, test_name);
    correct_result.array = {};

    test_name = "Массив с количеством элементов больше максимального";
    array_size = 2000;
    arrays = generateCorrectInputAndOutputArrays(array_size, correct_min_value, distr_2_1024(gen));
    correct_result.errors_array = {"array size > 1024"};
    writeTestToJsonFile(arrays.input_array, correct_result, test_name);
    correct_result.array = {};
    correct_result.errors_array = {};

    test_name = "Массив с минимальным элементом в индексе 0";
    array_size = distr_2_1024(gen);
    arrays = generateCorrectInputAndOutputArrays(array_size, correct_min_value, 0);
    correct_result.array = arrays.output_array;
    writeTestToJsonFile(arrays.input_array, correct_result, test_name);
    correct_result.array = {};

    test_name = "Массив с минимальным элементом в последнем индексе";
    array_size = distr_2_1024(gen);
    arrays = generateCorrectInputAndOutputArrays(array_size, correct_min_value, array_size - 1);
    correct_result.array = arrays.output_array;
    writeTestToJsonFile(arrays.input_array, correct_result, test_name);
    correct_result.array = {};

    // здесь заменим первый элемент массива на очень большое число, чтобы специально вызвать overflow
    test_name = "Массив с элементом, превышающим INT_MAX при умножении на минимальное число";
    input_array = generateRandomInputArray(distr_2_1024(gen));
    input_array[0] = INT_MAX - 1;
    correct_result.errors_array = {"new number is more than int_max"};
    writeTestToJsonFile(input_array, correct_result, test_name);
    correct_result.errors_array = {};


    test_name = "Массив случайного размера с корректными данными";
    array_size = distr_2_1024(gen);
    std::uniform_int_distribution<> distr_dynamic(2, array_size);
    arrays = generateCorrectInputAndOutputArrays(distr_2_1024(gen), correct_min_value, distr_dynamic(gen));
    correct_result.array = arrays.output_array;
    writeTestToJsonFile(arrays.input_array, correct_result, test_name);
}