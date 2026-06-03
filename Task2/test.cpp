#include <cassert>
#include <iostream>
#include <vector>
#include "find.hpp"
#include "../Task1/rarray.hpp"
#include "../Task1/time.hpp"

void testLinearSearch() {
    std::vector<int> data = {5, 8, 2, 9, 1};

    // Проверка обычного поиска
    assert(linearSearch(data, 5) == 0  );
    assert(linearSearch(data, 2) == 2  );
    assert(linearSearch(data, 1) == 4  );

    // Если есть дубликаты - должен вернуть первый индекс
    std::vector<int> dup = {7, 3, 7, 1};
    assert(linearSearch(dup, 7) == 0);

    // Проверка отсутствия значения
    assert(linearSearch(data, 100) == SIZE_MAX);
}

void testBinSearch() {
    std::vector<int> data = {1, 3, 5, 7, 9, 11};

    // Поиск в отсортированном массиве
    assert(binSearch(data, 1) == 0);
    assert(binSearch(data, 7) == 3);
    assert(binSearch(data, 11) == 5);

    // Проверка отсутствия значения
    assert(binSearch(data, 4) == SIZE_MAX);

    // Пустой массив
    std::vector<int> empty;
    assert(binSearch(empty, 1) == SIZE_MAX);
}

void testContain() {
    std::vector<int> data = {5, 8, 2, 9, 1};

    // Проверка наличия элемента
    assert(contain(data, 5));
    assert(contain(data, 2));
    assert(contain(data, 1));

    // Проверка отсутствия элемента
    assert(!contain(data, 100));

    // Проверка для обычного массива
    int arr[] = {5, 8, 2, 9, 1};
    assert(contain(arr, 5, 5));
    assert(contain(arr, 5, 2));
    assert(!contain(arr, 5, 100));
}

int main() {
    testLinearSearch();
    testBinSearch();
    testContain();

    std::cout << "All tests passed!\n";

    // Размер массива: 100 миллионов элементов (~800 МБ для int64_t)
    constexpr std::size_t SIZE = 100'000'000;
    constexpr std::size_t TESTS = 20;  // Кол-во тестов для усреднения

    std::random_device rd;
    std::mt19937_64 gen(rd());


    std::uniform_int_distribution<std::size_t> indexDist(0, SIZE - 1);

    long long binSearchTime = 0;       // Аккумулятор времени бинарного поиска

    // Заполняем массив возрастающими случайными числами
    int64_t* data = fill_inc_random<int64_t>(
        SIZE,
        0,
        std::numeric_limits<int64_t>::max()
    );

    // === Бинарный поиск: O(log N) ===
    for (std::size_t i = 0; i < TESTS; ++i) {
        // Берём случайный элемент из массива - его гарантированно можно найти
        int64_t foundValue = data[indexDist(gen)];

        // Измеряем время, результат кладём в volatile, чтобы компилятор не выкинул вызов
        auto time = TTimer::measureNano([=]() {
                volatile std::size_t index =
                binSearch<int64_t>(data, SIZE, foundValue);
            });

        std::cout << "Бинарный поиск: " << time << " ns\n";
        binSearchTime += time;
    }

    binSearchTime /= TESTS;  // Среднее арифметическое

    // === Линейный поиск: O(N) ===
    long long linSearchTime = 0;

    for (std::size_t i = 0; i < TESTS; ++i) {
        int64_t foundValue = data[indexDist(gen)];

        auto time = TTimer::measureNano([=]() {
                volatile std::size_t index =
                linearSearch<int64_t>(data, SIZE, foundValue);
            });

        std::cout << "Линейный поиск: " << time << " ns\n";
        linSearchTime += time;
    }

    linSearchTime /= TESTS;

    std::cout << "\nСреднее время бинарного поиска: "
    << binSearchTime << " ns\n";

    std::cout << "Среднее время линейного поиска: "
    << linSearchTime << " ns\n";


    delete[] data;

    return 0;
}
