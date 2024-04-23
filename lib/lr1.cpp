#include "lr1.h"

find_and_multiply_result find_and_multiply(vector<int> array) {
    find_and_multiply_result result;
    result.min_value = INT_MAX;
    result.min_index = 0;

    if(array.empty()) {
        result.errors_array.emplace_back("array empty");
        return result;
    }

    if (array.size() > 1024) {
        result.errors_array.emplace_back("array size > 1024");
        return result;
    }

    // найти минимальное значение в массиве
    for (int i = 0; i < array.size(); i++) {
        if (array[i] < result.min_value) {
            result.min_value = array[i];
            result.min_index = i;
        }
    }

    // перемножить значения, идущие в массиве до индекса минимального значения, на это значение
    for (int i = 0; i < result.min_index; i++) {
        int curr_number = array[i];
        int new_value = curr_number * result.min_value;
        // проверить, не вызывает ли умножение чисел overflow, т.е. что новое значение не превышает INT_MAX
        if (curr_number != 0 && new_value / curr_number != result.min_value) {
            result.errors_array.emplace_back("new number is more than int_max");
            return result;
        }
        array[i] = new_value;
    }
    result.array = array;

    return result;
}