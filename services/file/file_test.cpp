#include "file_test.h"

using namespace std;

void writeTestToJsonFile(vector<int> input_array, find_and_multiply_result correct_result, string testName) {

    string filename = "../tests/generated_tests.json";

    using json = nlohmann::json;
    json data;

    // читаем и парсим json файл
    std::ifstream f(filename);
    try {
        json parseData = json::parse(f);
        for (int i = 0; i < parseData.size(); i++) {
            data.push_back(parseData[i]);
        }
    } catch(const std::runtime_error& re)
    {
        std::cerr << "Runtime error: " << re.what() << std::endl;
    }
    catch(const std::exception& ex)
    {
        std::cerr << "Error occurred: " << ex.what() << std::endl;
    }
    catch(...)
    {
        std::cerr << "Unknown failure occurred. Possible memory corruption" << std::endl;
    }
    f.close();

    json jsonOutput;

    jsonOutput[testName];

    // дописываем данные теста в json
    jsonOutput[testName]["input"] = input_array;
    jsonOutput[testName]["output"]["int_array"] = correct_result.array;
    jsonOutput[testName]["output"]["err_array"] = correct_result.errors_array;

    data.push_back(jsonOutput);

    // сохраняем новый json в файл
    std::ofstream outputFile(filename);
    if (outputFile.is_open()) {
        outputFile << std::setw(4) << data << endl;
    }
    else { cout << "Unable to open file for writing" << endl;}
    outputFile.close();
}



map<string, testData> readTestFromJsonFile() {
    string filename = "../tests/generated_tests.json";
    using json = nlohmann::json;
    json data;

    map<string, testData> response;
    testData test;

    ifstream f(filename);
    try {
        json parseData = json::parse(f);
        for (int i = 0; i < parseData.size(); i++) {
            data.push_back(parseData[i]);
        }
    } catch(const std::runtime_error& re)
    {
        std::cerr << "Runtime error: " << re.what() << std::endl;
    }
    catch(const std::exception& ex)
    {

        std::cerr << "Error occurred: " << ex.what() << std::endl;
    }
    catch(...)
    {

        std::cerr << "Unknown failure occurred. Possible memory corruption" << std::endl;
    }
    f.close();

    string key;
    vector<string> keys = {
        "Пустой массив",
        "Массив с одним элементом",
        "Массив с максимальным количеством элементов - 1",
        "Массив с максимальным количеством элементов",
        "Массив с количеством элементов больше максимального",
        "Массив с минимальным элементом в индексе 0",
        "Массив с минимальным элементом в последнем индексе",
        "Массив с элементом, превышающим INT_MAX при умножении на минимальное число",
        "Массив случайного размера с корректными данными"
    };

    for (int k = 0; k < data.size(); k++) {
        key = keys[k];
        test.input = data[k][key]["input"].get<vector<int>>();
        test.output.errors_array = data[k][key]["output"]["err_array"];
        test.output.array = data[k][key]["output"]["int_array"].get<vector<int>>();
        response[key] = test;
    }
    return response;
}

void clearFile() {
    string filename = "../tests/generated_tests.json";
    std::ofstream ofs;
    ofs.open(filename, std::ofstream::out | std::ofstream::trunc);
    ofs.close();
}