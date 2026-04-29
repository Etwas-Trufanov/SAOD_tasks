#include <cassert>
#include <iostream>
#include <stdexcept>
#include "find.hpp"

void testLinearSearch() {
    int data[] = {5, 8, 2, 9, 1};

    // Проверка обычного поиска
    assert(linearSearch(data, 5, 5) == 0);
    assert(linearSearch(data, 5, 2) == 2);
    assert(linearSearch(data, 5, 1) == 4);

    // Если есть дубликаты — должен вернуть первый индекс
    int dup[] = {7, 3, 7, 1};
    assert(linearSearch(dup, 4, 7) == 0);

    // Проверка исключения
    try {
        linearSearch(data, 5, 100);
        assert(false);
    } catch (const std::runtime_error&) {
    }
}

void testBinSearch() {
    int data[] = {1, 3, 5, 7, 9, 11};

    // Поиск в отсортированном массиве
    assert(binSearch(data, 6, 1) == 0);
    assert(binSearch(data, 6, 7) == 3);
    assert(binSearch(data, 6, 11) == 5);

    // Проверка исключения
    try {
        binSearch(data, 6, 4);
        assert(false);
    } catch (const std::runtime_error&) {
    }

    // Пустой массив
    try {
        binSearch(data, 0, 1);
        assert(false);
    } catch (const std::runtime_error&) {
    }
}

int main() {
    testLinearSearch();
    testBinSearch();

    std::cout << "All tests passed!\n";
    return 0;
}