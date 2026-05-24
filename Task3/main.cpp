#include <iostream>
#include "sizeOfStack.hpp"

int main(int argc, char **argv) {
  int maxDepth = 0;
  size_t frameSize = 0;

  testStack(0, nullptr, maxDepth, frameSize);

  std::cout << "Max recursion depth: " << maxDepth << std::endl;
  std::cout << "Approx frame size: " << frameSize << " bytes" << std::endl;

  size_t total = (size_t)maxDepth * frameSize;

  std::cout << "Estimated stack size: ~" << total / 1024 << " KB" << std::endl;

  return 0;
}
