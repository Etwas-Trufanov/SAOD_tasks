#include <ctime>
#include <iostream>

#include ""

int main() {
  time_t time_point1 = time(nullptr);

  time_t time_point2 = time(nullptr);
  std::cout << "Время выполнения: " << time_point1 - time_point2 << " секунд\n";
}
