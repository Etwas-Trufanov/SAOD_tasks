#pragma once

#include <iostream>

// рекурсивная функция для оценки стека
inline void testStack(int depth, char* prevAddr, int &maxDepth, size_t &frameSize) {
  int x; // локальная переменная = часть стека текущего кадра
  char* curAddr = (char*)&x;

  // оцениваем размер одного "шага" стека
  if (prevAddr != nullptr) {
    frameSize = (curAddr > prevAddr)
    ? (curAddr - prevAddr)
    : (prevAddr - curAddr);
  }

  maxDepth = depth;

  // ограничитель, чтобы не улететь слишком далеко (можно менять)
  if (depth > 200000) return;

  testStack(depth + 1, curAddr, maxDepth, frameSize);
}
