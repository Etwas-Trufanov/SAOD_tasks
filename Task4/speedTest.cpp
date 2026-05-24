#include "../Task1/rarray.hpp"
#include "sortLib.hpp"
#include "../Task1/time.hpp"
#include <cassert>
#include <climits>
#include <iostream>
#include <unistd.h>

int main() {

    // Слошной тест скорости
    std::cout << "bubbleSort с шагом 1000, до 20000, время в мкс" << std::endl;
    for (std::size_t size = 0; size < 20000; size += 1000) {
        std::vector<int> array = fill_random_vector<int>(size, 0, INT_MAX);
        auto time = TTimer::measureNano([&array]() {
            array = slowSort::bubbleSort(array);
        });
        std::cout << time / 1000 << std::endl;
        assert(is_sorted(array));
    }

    // Слошной тест скорости
    std::cout << "insertSort с шагом 1000, до 20000, время в мкс" << std::endl;
    for (std::size_t size = 0; size < 20000; size += 1000) {
        std::vector<int> array = fill_random_vector<int>(size, 0, INT_MAX);
        auto time = TTimer::measureNano([&array]() {
            array = slowSort::insertSort(array);
        });
        std::cout << time / 1000 << std::endl;
        assert(is_sorted(array));
    }

    // Слошной тест скорости
    std::cout << "quickSort с шагом 1000, до 20000, время в мкс" << std::endl;
    for (std::size_t size = 0; size < 20000; size += 1000) {
        std::vector<int> array = fill_random_vector<int>(size, 0, INT_MAX);
        auto time = TTimer::measureNano([&array]() {
            array = fastsort::quickSort(array);
        });
        std::cout << time / 1000 << std::endl;
        assert(is_sorted(array));
    }


    std::cout << "Отдельно смотрим quickSort на 268435456 элементов ~1 гиг\n";
    std::vector<int> array = fill_random_vector<int>(268435456, 0, INT_MAX);
    std::cout << "Сгенерирован, спин 5 сек.\n";
    sleep(5);
    auto time = TTimer::measureNano([&array]() {
        array = fastsort::quickSort(array);
    });
    std::cout << "  quickSort time: " << time / 1000000000 << " секунд" << std::endl;
    assert(is_sorted(array));


    return 0;
}
