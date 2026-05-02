#include "time.hpp"
#include "rarray.hpp"
#include <iostream>
#include <cassert>
#include <unistd.h>

int main() {

  // Тесты на assertах
  {
    int *data = new int[5]{1, 2, 3, 4, 5};
    assert(is_sorted(data, 5));
  }
  {
    int *data = new int[5]{1, 2, 3, 5, 4};
    assert(!is_sorted(data, 5));
  }
  {
    int *data = new int[5]{1, 2, 15, 5, 4};
    assert(!is_sorted(data, 5));
  }
  {
    int *data = new int[10]{20, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    assert(!is_sorted(data, 5));
  }



    // Замер лямбды
    auto time1 = TTimer::measure([]() {
        sleep(2);
    });
    std::cout << "Тест лямбды: " << time1 << " мс\n";

    auto time4 = TTimer::measure([]() {
      int *data = fill_inc_random(100000000, 0, 300000000);
      auto sorted = is_sorted(data, 100000000);
      if (sorted) {
        std::cout << "Массив отсортирован\n";
      } else {
        std::cout << "Массив не отсортирован\n";
      }
    });
    std::cout << "Перебор массива на 100000000 элементов занял: " << time4 << " мс\n";

    return 0;
}
