#include "../Task1/rarray.hpp"
#include "sortLib.hpp"
#include "../Task1/time.hpp"
#include <algorithm>
#include <cassert>
#include <climits>
#include <iostream>
#include <unistd.h>


int main() {
    // Сплошной тест скорости std::sort
    std::cout << "std::sort с шагом 1000, до 20000, время в мкс" << std::endl;
    for (std::size_t size = 0; size <= 20000; size += 1000) {
        std::vector<int> array = fill_random_vector<int>(size, 0, INT_MAX);
        auto time = TTimer::measureNano([&array]() {
            std::sort(array.begin(), array.end());
        });
        std::cout << time / 1000 << std::endl;
        assert(is_sorted(array));
    }

    // Слошной тест скорости mergeSort
    std::cout << "mergeSort с шагом 1000, до 20000, время в мкс" << std::endl;
    for (std::size_t size = 0; size <= 20000; size += 1000) {
        std::vector<int> array = fill_random_vector<int>(size, 0, INT_MAX);
        auto time = TTimer::measureNano([&array]() {
            array = fastsort::mergeSort(array);
        });
        std::cout << time / 1000 << std::endl;
        assert(is_sorted(array));
        }

    // Слошной тест скорости quickSort
    std::cout << "quickSort с шагом 1000, до 20000, время в мкс" << std::endl;
    for (std::size_t size = 0; size <= 20000; size += 1000) {
        std::vector<int> array = fill_random_vector<int>(size, 0, INT_MAX);
        auto time = TTimer::measureNano([&array]() {
            array = fastsort::quickSort(array);
        });
        std::cout << time / 1000 << std::endl;
        assert(is_sorted(array));
    }

    // Слошной тест скорости shellSort
    std::cout << "shellSort с шагом 1000, до 20000, время в мкс" << std::endl;
    for (std::size_t size = 0; size <= 20000; size += 1000) {
        std::vector<int> array = fill_random_vector<int>(size, 0, INT_MAX);
        auto time = TTimer::measureNano([&array]() {
            array = slowSort::shellSort(array);
        });
        std::cout << time / 1000 << std::endl;
        assert(is_sorted(array));
    }

    // Слошной тест скорости bubbleSort
    std::cout << "bubbleSort с шагом 1000, до 20000, время в мкс" << std::endl;
    for (std::size_t size = 0; size <= 20000; size += 1000) {
        std::vector<int> array = fill_random_vector<int>(size, 0, INT_MAX);
        auto time = TTimer::measureNano([&array]() {
            array = slowSort::bubbleSort(array);
        });
        std::cout << time / 1000 << std::endl;
        assert(is_sorted(array));
    }

    // Слошной тест скорости insertSort
    std::cout << "insertSort с шагом 1000, до 20000, время в мкс" << std::endl;
    for (std::size_t size = 0; size <= 20000; size += 1000) {
        std::vector<int> array = fill_random_vector<int>(size, 0, INT_MAX);
        auto time = TTimer::measureNano([&array]() {
            array = slowSort::insertSort(array);
        });
        std::cout << time / 1000 << std::endl;
        assert(is_sorted(array));
    }


    // Слошной тест скорости quickSort
    std::cout << "quickSort с шагом 10000, до 200000, время в мкс" << std::endl;
    for (std::size_t size = 0; size <= 200000; size += 10000) {
        std::vector<int> array = fill_random_vector<int>(size, 0, INT_MAX);
        auto time = TTimer::measureNano([&array]() {
            array = fastsort::quickSort(array);
        });
        std::cout << time / 1000 << std::endl;
        assert(is_sorted(array));
    }

    // Слошной тест скорости shellSort
    std::cout << "shellSort с шагом 10000, до 200000, время в мкс" << std::endl;
    for (std::size_t size = 0; size <= 200000; size += 10000) {
        std::vector<int> array = fill_random_vector<int>(size, 0, INT_MAX);
        auto time = TTimer::measureNano([&array]() {
            array = slowSort::shellSort(array);
        });
        std::cout << time / 1000 << std::endl;
        assert(is_sorted(array));
    }

    // Слошной тест скорости quickSort
    std::cout << "--------------------------------------------------------------------" << std::endl;
    std::cout << "quickSort с шагом 10, до 100, время в мкс" << std::endl;
    for (std::size_t size = 0; size <= 100; size += 10) {
        std::vector<int> array = fill_random_vector<int>(size, 0, INT_MAX);
        auto time = TTimer::measureNano([&array]() {
            array = fastsort::quickSort(array);
        });
        std::cout << time / 1000 << std::endl;
        assert(is_sorted(array));
    }

    // Слошной тест скорости shellSort
    std::cout << "shellSort с шагом 10, до 100, время в мкс" << std::endl;
    for (std::size_t size = 0; size <= 100; size += 10) {
        std::vector<int> array = fill_random_vector<int>(size, 0, INT_MAX);
        auto time = TTimer::measureNano([&array]() {
            array = slowSort::shellSort(array);
        });
        std::cout << time / 1000 << std::endl;
        assert(is_sorted(array));
    }

    // Слошной тест скорости bubbleSort
    std::cout << "bubbleSort с шагом 10, до 100, время в мкс" << std::endl;
    for (std::size_t size = 0; size <= 100; size += 10) {
        std::vector<int> array = fill_random_vector<int>(size, 0, INT_MAX);
        auto time = TTimer::measureNano([&array]() {
            array = slowSort::bubbleSort(array);
        });
        std::cout << time / 1000 << std::endl;
        assert(is_sorted(array));
    }

    // Слошной тест скорости insertSort
    std::cout << "insertSort с шагом 10, до 100, время в мкс" << std::endl;
    for (std::size_t size = 0; size <= 100; size += 10) {
        std::vector<int> array = fill_random_vector<int>(size, 0, INT_MAX);
        auto time = TTimer::measureNano([&array]() {
            array = slowSort::insertSort(array);
        });
        std::cout << time / 1000 << std::endl;
        assert(is_sorted(array));
    }

    return 0;
}
