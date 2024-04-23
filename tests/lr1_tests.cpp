#include "../lib/lr1.h"
#include "../services/file/file_test.h"
#include "../services/tests/generate_tests.h"
#include <gtest/gtest.h>
#include <vector>
#include <utility>
using namespace std;

// Подробнее https://google.github.io/googletest/reference/testing.html

// Тестовый класс
class find_and_multiplyTest : public ::testing::Test {
protected:
    find_and_multiplyTest() {
        vectorTestData = readTestFromJsonFile();
    }
    find_and_multiply_result result;
    map<string, testData> vectorTestData;
};

// дальше идут тесты, код повторяется, разница только в названиях тестов, а входные данные берем из json файла
TEST_F (find_and_multiplyTest, ArrayEmpty) {
    string name = "Пустой массив";

    vector<int> arr = vectorTestData[name].input;
    find_and_multiply_result correctResult = vectorTestData[name].output;

    result = find_and_multiply(arr);

    cout << "ТЕСТ: «" << name << "» с размером входящего массива: " << vectorTestData[name].input.size() << endl;
    EXPECT_EQ(result.array, correctResult.array);
    EXPECT_EQ(result.errors_array, correctResult.errors_array);
    cout << "Пройдено" << endl;
    cout << endl;
}

TEST_F (find_and_multiplyTest, ArrayWithSingleItem) {
    string name = "Массив с одним элементом";

    vector<int> arr = vectorTestData[name].input;
    find_and_multiply_result correctResult = vectorTestData[name].output;

    result = find_and_multiply(arr);

    cout << "ТЕСТ: «" << name << "» с размером входящего массива: " << vectorTestData[name].input.size() << endl;
    EXPECT_EQ(result.array, correctResult.array);
    EXPECT_EQ(result.errors_array, correctResult.errors_array);
    cout << "Пройдено" << endl;
    cout << endl;
}

TEST_F (find_and_multiplyTest, ArrayMaxSizeMinusOne) {
    string name = "Массив с максимальным количеством элементов - 1";

    vector<int> arr = vectorTestData[name].input;
    find_and_multiply_result correctResult = vectorTestData[name].output;

    result = find_and_multiply(arr);

    cout << "ТЕСТ: «" << name << "» с размером входящего массива: " << vectorTestData[name].input.size() << endl;
    EXPECT_EQ(result.array, correctResult.array);
    EXPECT_EQ(result.errors_array, correctResult.errors_array);
    cout << "Пройдено" << endl;
    cout << endl;
}

TEST_F (find_and_multiplyTest, ArrayMaxSize) {
    string name = "Массив с максимальным количеством элементов";

    vector<int> arr = vectorTestData[name].input;
    find_and_multiply_result correctResult = vectorTestData[name].output;

    result = find_and_multiply(arr);

    cout << "ТЕСТ: «" << name << "» с размером входящего массива: " << vectorTestData[name].input.size() << endl;
    EXPECT_EQ(result.array, correctResult.array);
    EXPECT_EQ(result.errors_array, correctResult.errors_array);
    cout << "Пройдено" << endl;
    cout << endl;
}

TEST_F (find_and_multiplyTest, ArrayTooBig) {
    string name = "Массив с количеством элементов больше максимального";

    vector<int> arr = vectorTestData[name].input;
    find_and_multiply_result correctResult = vectorTestData[name].output;

    result = find_and_multiply(arr);

    cout << "ТЕСТ: «" << name << "» с размером входящего массива: " << vectorTestData[name].input.size() << endl;
    EXPECT_EQ(result.array, correctResult.array);
    EXPECT_EQ(result.errors_array, correctResult.errors_array);
    cout << "Пройдено" << endl;
    cout << endl;
}

TEST_F (find_and_multiplyTest, ArrayWithMinValueAtZero) {
    string name = "Массив с минимальным элементом в индексе 0";

    vector<int> arr = vectorTestData[name].input;
    find_and_multiply_result correctResult = vectorTestData[name].output;

    result = find_and_multiply(arr);

    cout << "ТЕСТ: «" << name << "» с размером входящего массива: " << vectorTestData[name].input.size() << endl;
    EXPECT_EQ(result.array, correctResult.array);
    EXPECT_EQ(result.errors_array, correctResult.errors_array);
    cout << "Пройдено" << endl;
    cout << endl;
}

TEST_F (find_and_multiplyTest, ArrayWithMinValueAtMax) {
    string name = "Массив с минимальным элементом в последнем индексе";

    vector<int> arr = vectorTestData[name].input;
    find_and_multiply_result correctResult = vectorTestData[name].output;

    result = find_and_multiply(arr);

    cout << "ТЕСТ: «" << name << "» с размером входящего массива: " << vectorTestData[name].input.size() << endl;
    EXPECT_EQ(result.array, correctResult.array);
    EXPECT_EQ(result.errors_array, correctResult.errors_array);
    cout << "Пройдено" << endl;
    cout << endl;
}

TEST_F (find_and_multiplyTest, ArrayWithTooBigNumbers) {
    string name = "Массив с элементом, превышающим INT_MAX при умножении на минимальное число";

    vector<int> arr = vectorTestData[name].input;
    find_and_multiply_result correctResult = vectorTestData[name].output;

    result = find_and_multiply(arr);

    cout << "ТЕСТ: «" << name << "» с размером входящего массива: " << vectorTestData[name].input.size() << endl;
    EXPECT_EQ(result.array, correctResult.array);
    EXPECT_EQ(result.errors_array, correctResult.errors_array);
    cout << "Пройдено" << endl;
    cout << endl;
}

TEST_F (find_and_multiplyTest, ArrayCorrectDataRandomSize) {
    string name = "Массив случайного размера с корректными данными";

    vector<int> arr = vectorTestData[name].input;
    find_and_multiply_result correctResult = vectorTestData[name].output;

    result = find_and_multiply(arr);

    cout << "ТЕСТ: «" << name << "» с размером входящего массива: " << vectorTestData[name].input.size() << endl;
    EXPECT_EQ(result.array, correctResult.array);
    EXPECT_EQ(result.errors_array, correctResult.errors_array);
    cout << "Пройдено" << endl;
    cout << endl;
}