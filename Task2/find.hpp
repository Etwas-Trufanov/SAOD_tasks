#include <concepts>
#include <cstddef>
#include <cstdint>
#include <vector>

// Просто ищем первое совпадение в массиве, применим к неотсортированным массивам
// T *data - массив, size - размер массива, T value - искомое значение
// ok - флаг, указывающий, найдено ли значение
// макс size_t
template <typename T>
requires std::integral<T>
std::size_t linearSearch(T *data, std::size_t size, T value) {
    for (std::size_t i = 0; i < size; ++i) {
        if (data[i] == value) {
            return i;
        }
    }
    return SIZE_MAX; // Возвращаем 0, если значение не найдено
}

// Перегрузка для std::vector
template <typename T>
requires std::integral<T>
std::size_t linearSearch(std::vector<T> &data, T value) {
    return linearSearch(data.data(), data.size(), value);
}

// Бинарный поиск в массиве, применим только к отсортированным массивам по возрастанию
// T *data - массив, size - размер массива, T value - искомое значение
// ok - флаг, указывающий, найдено ли значение
template <typename T>
requires std::integral<T>
std::size_t binSearch(T *data, std::size_t size, T value) {
    if (size == 0) {
        return SIZE_MAX;
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
    return SIZE_MAX;
}

// Перегрузка для std::vector
template <typename T>
requires std::integral<T>
std::size_t binSearch(std::vector<T> &data, T value) {
    return binSearch(data.data(), data.size(), value);
}

template <typename T>
bool contain(std::vector<T> data, T value) {
    return linearSearch(data.data(), data.size(), value) != SIZE_MAX;
}

// Перегрузка для обычного массива
template <typename T>
bool contain(T *data, std::size_t size, T value) {
    return linearSearch(data, size, value) != SIZE_MAX;
}
