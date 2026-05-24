#include <concepts>
#include <cstddef>
#include <vector>

// Просто ищем первое совпадение в массиве, применим к неотсортированным массивам
// T *data - массив, size - размер массива, T value - искомое значение
// ok - флаг, указывающий, найдено ли значение
// макс size_t
template <typename T>
requires std::integral<T>
std::size_t linearSearch(T *data, std::size_t size, T value, bool &ok) {
    for (std::size_t i = 0; i < size; ++i) {
        if (data[i] == value) {
            ok = true;
            return i;
        }
    }
    ok = false;
    return 0; // Возвращаем 0, если значение не найдено
}

// Перегрузка для std::vector
template <typename T>
requires std::integral<T>
std::size_t linearSearch(std::vector<T> &data, T value, bool &ok) {
    return linearSearch(data.data(), data.size(), value, ok);
}

// Бинарный поиск в массиве, применим только к отсортированным массивам по возрастанию
// T *data - массив, size - размер массива, T value - искомое значение
// ok - флаг, указывающий, найдено ли значение
template <typename T>
requires std::integral<T>
std::size_t binSearch(T *data, std::size_t size, T value, bool &ok) {
    if (size == 0) {
        ok = false;
        return 0;
    }

    std::size_t left = 0;
    std::size_t right = size; // правая граница — исключительная [left, right)

    while (left < right) {
        std::size_t mid = left + (right - left) / 2;

        if (data[mid] == value) {
            ok = true;
            return mid;           // найдено
        } else if (data[mid] < value) {
            left = mid + 1;       // ищем в правой половине
        } else {
            right = mid;          // ищем в левой половине
        }
    }

    // Если цикл завершился — элемент не найден
    ok = false;
    return 0;
}

// Перегрузка для std::vector
template <typename T>
requires std::integral<T>
std::size_t binSearch(std::vector<T> &data, T value, bool &ok) {
    return binSearch(data.data(), data.size(), value, ok);
}

template <typename T>
bool contain(std::vector<T> data, T value) {
    bool ok;
    std::size_t index = linearSearch(data.data(), data.size(), value, ok);
    return ok;
}

// Перегрузка для обычного массива
template <typename T>
bool contain(T *data, std::size_t size, T value) {
    bool ok;
    std::size_t index = linearSearch(data, size, value, ok);
    return ok;
}
