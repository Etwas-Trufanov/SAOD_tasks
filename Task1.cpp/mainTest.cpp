#include "time.hpp"
#include "rarray.hpp"
#include <iostream>
#include <cassert>
#include <thread>

// Ваша функция для замера
void heavy_task() {
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
}

int main() {

  // Тесты на assertах
  {
    massive<int> m;
    m.fill(new int[5]{1, 2, 3, 4, 5}, 5);
    assert(m.is_sorted());
  }
  {
    massive<int> m;
    m.fill(new int[5]{1, 2, 3, 5, 4}, 5);
    assert(!m.is_sorted());
  }
  {
    massive<int> m;
    m.fill(new int[5]{1, 2, 15, 5, 4}, 5);
    assert(!m.is_sorted());
  }
  {
    massive<int> m;
    m.fill(new int[10]{20, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 10);
    assert(!m.is_sorted());
  }



    // Замер лямбды
    auto time1 = Timer::measure([]() {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    });
    std::cout << "Лямбда: " << time1 << " мс\n";

    // Замер обычной функции
    auto time2 = Timer::measure(heavy_task);
    std::cout << "Функция: " << time2 << " мс\n";

    // Замер с аргументами (если функция их принимает)
    auto time3 = Timer::measure([](int n) {
        volatile int sum = 0;
        for (int i = 0; i < n; ++i) sum += i;
    }, 1000000);
    std::cout << "Цикл с аргументом: " << time3 << " мс\n";

    return 0;
}
