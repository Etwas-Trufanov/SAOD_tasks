#include <chrono>
#include <iostream>
#include <cassert>

#include "lib.hpp"

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
    m.fill(new int[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 10);
    assert(m.is_sorted());
  }

  // Измерение времени выполнения с точностью до милисекунд
  auto t0 = std::chrono::steady_clock::now();
  massive<int> m;
  m.fill_inc_random(20, 1, 200);
  m.print();
  auto t1 = std::chrono::steady_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(t1 - t0);
  std::cout << "Время выполнения: " << duration.count() << " миллисекунд\n";
}
