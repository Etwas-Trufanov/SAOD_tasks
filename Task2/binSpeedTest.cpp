#include <cstdint>
#include <iostream>
#include <random>
#include <limits>

#include "find.hpp"
#include "rarray.hpp"
#include "time.hpp"

int main() {
    constexpr std::size_t SIZE = 100'000'000;
    constexpr std::size_t TESTS = 20;

    std::random_device rd;
    std::mt19937_64 gen(rd());

    std::uniform_int_distribution<std::size_t> indexDist(0, SIZE - 1);

    long long binSearchTime = 0;

    int64_t* data = fill_inc_random<int64_t>(
        SIZE,
        0,
        std::numeric_limits<int64_t>::max()
    );

    for (std::size_t i = 0; i < TESTS; ++i) {
        int64_t foundValue = data[indexDist(gen)];

        auto time = TTimer::measureNano([=]() {
            volatile std::size_t index =
                binSearch<int64_t>(data, SIZE, foundValue);
        });

        std::cout << "Бинарный поиск: " << time << " ns\n";
        binSearchTime += time;
    }

    binSearchTime /= TESTS;

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