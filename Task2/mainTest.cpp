#include "binFind.hpp"
#include "../Task1/rarray.hpp"
#include "time.hpp"

int main() {
  int *data = fill_random(1000000, 0, 2000000);
  //std::cout << "Элемент найден: " << linearSearch(data, 1000000, 1320000) << std::endl;
  
  for (std::size_t i = 0; i < 20; i++) {
    auto time = TTimer::measure([]() {
        try {
            int *data = fill_random(1000000, 0, 2000000);
            std::cout << "Элемент найден: " << linearSearch(data, 1000000, 1320000) << std::endl;
        } catch (...) {
            std::cout << "Элемент не найден\n";
        }
      });
    std::cout << "Поиск занял: " << time << " мс\n";
  }
    return 0;
}
