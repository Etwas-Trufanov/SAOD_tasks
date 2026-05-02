#include <concepts>
#include <cstddef>
#include <stdexcept>

// Просто ищем первое совпадение в массиве, применим к неотсортированным массивам
// T *data - массив, size - размер массива, T value - искомое значение
template <typename T>
requires std::integral<T>
std::size_t linearSearch(T *data, std::size_t size, T value) {
    for (std::size_t i = 0; i < size; ++i) {
        if (data[i] == value) {
            return i;
        } 
    }
    throw std::runtime_error("Has no value in array");
}

// Бинарный поиск в массиве, применим только к отсортированным массивам
// T *data - массив, size - размер массива, T value - искомое значение
template <typename T>
requires std::integral<T>
std::size_t binSearch(T *data, std::size_t size, T value) {
    if (size == 0) {
        throw std::runtime_error("Has no value in array");
    }
    
    std::size_t left = 0;
    std::size_t right = size; // правая граница — исключительная [left, right)
    
    while (left < right) {
    	
        std::size_t mid = left + (right - left) / 2;
        
        if (data[mid] == value) {
            return mid;           // найдено
        } else if (data[mid] < value) {
            left = mid + 1;       // ищем в правой половине
        } else {
            right = mid;          // ищем в левой половине
        }
    }
    
    // Если цикл завершился — элемент не найден
    throw std::runtime_error("Has no value in array");
}
