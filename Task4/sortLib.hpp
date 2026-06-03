#pragma once
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <vector>

typedef std::size_t sz;

// bigO
// quickSort
// худший:  O(n^2)
// средний: O(n log n)
// Лучший:  O(n log n)

// shellSort
// худший:  O(n^2)
// средний: O(n^1.5)
// Лучший:  O(n log n)

// insertSort
// худший:  O(n^2)
// средний: O(n^2)
// Лучший:  O(n)

// bubbleSort
// худший:  O(n^2)
// средний: O(n^2)
// Лучший:  O(n)

// mergeSort
// худший:  O(n log n)
// средний: O(n log n)
// Лучший:  O(n log n)

// Быстрые сортировки
namespace fastsort {
    namespace {
        // array - массив
        // lPoint - левая граница
        // rPoint - правая граница
        template<typename T>
        void _quickSort(std::vector<T> &array, std::int64_t lPoint, std::int64_t rPoint) {
            // если n = 1, или границы перехлестнулись -> чиллим
            if (lPoint >= rPoint) return;

            // опорная точка - правый элемент
            T pivot = array[rPoint];

            // i - левая граница
            std::int64_t i = lPoint;

            // Перебираем массив до правой границы
            for (std::int64_t j = lPoint; j < rPoint; j++) {
                // Если элемент меньше или равен опорной точки
                if (array[j] <= pivot) {
                    // Меняем j и i местами и увеличиваем i++
                    T tmp = array[i];
                    array[i] = array[j];
                    array[j] = tmp;
                    i++;
                }
            }

            // Меняем i и rPoint местами
            T tmp = array[i];
            array[i] = array[rPoint];
            array[rPoint] = tmp;

            // Сортируем левую часть и правую
            _quickSort(array, lPoint, i-1);
            _quickSort(array, i+1, rPoint);

        }


    }
    template<typename T>
    std::vector<T> quickSort(std::vector<T> array) {
        _quickSort<T>(array, 0, array.size()-1);
        return array;
    }
    namespace {
        // Сливаем два отсортированных подмассива в один
        template<typename T>
        void merge(std::vector<T> &array, sz left, sz mid, sz right) {
            sz n1 = mid - left + 1;  // Размер левого подмассива
            sz n2 = right - mid;     // Размер правого подмассива

            // Создаем временные массивы
            std::vector<T> L(n1), R(n2);

            // Копируем данные во временные массивы
            for (sz i = 0; i < n1; i++)
                L[i] = array[left + i];
            for (sz j = 0; j < n2; j++)
                R[j] = array[mid + 1 + j];

            // Слияние временных массивов обратно в array[left..right]
            sz i = 0, j = 0, k = left;
            while (i < n1 && j < n2) {
                if (L[i] <= R[j]) {
                    array[k] = L[i];
                    i++;
                } else {
                    array[k] = R[j];
                    j++;
                }
                k++;
            }

            // Копируем оставшиеся элементы
            while (i < n1) {
                array[k] = L[i];
                i++;
                k++;
            }

            // Копируем оставшиеся элементы
            while (j < n2) {
                array[k] = R[j];
                j++;
                k++;
            }
        }

        template<typename T>
        void _mergeSort(std::vector<T> &array, sz left, sz right) {
            if (left < right) {
                sz mid = left + (right - left) / 2;  // Находим середину

                // Сортируем первую и вторую половины
                _mergeSort(array, left, mid);
                _mergeSort(array, mid + 1, right);

                // Сливаем отсортированные половины
                merge(array, left, mid, right);
            }
        }
    }

    template<typename T>
    std::vector<T> mergeSort(std::vector<T> array) {
        if (array.size() <= 1) {
            return array;
        }
        _mergeSort(array, 0, array.size() - 1);
        return array;
    }



}


// Медленные сортировки
namespace slowSort {
    // Сортировка Шелла -> модифицированная вставками
    template<typename T>
    std::vector<T> shellSort(std::vector<T> array) {
        auto gap = array.size()/2;
        while (gap > 0) {
            for (std::size_t i = gap; i < array.size(); i++) {
                T tmp = array[i];
                std::size_t j = i;
                while (j >= gap && array[j - gap] > tmp) {
                    array[j] = array[j - gap];
                    j = j - gap;
                }
                array[j] = tmp;
            }
            gap /= 2;
        }
        return array;
    }

    // Сортировка пузырьком
    template<typename T>
    std::vector<T> bubbleSort(std::vector<T> array) {
        if (array.empty()) {
            return array;
        }
        bool isSorted = false;
        while (!isSorted) {
            isSorted = true;
            for (std::size_t i = 0; i < array.size()-1; i++) {
                if (array[i] > array[i+1]) {
                    isSorted = false;
                    T tmp = array[i];
                    array[i] = array[i+1];
                    array[i+1] = tmp;
                }
            }
        }
        return array;
    }

    // Сортировка вставками
    template<typename T>
    std::vector<T> insertSort(std::vector<T> array) {
        for (std::size_t i = 1; i < array.size(); i++) {
            T tmp = array[i];
            std::size_t j = i;
            while (j > 0 && array[j-1] > tmp) {
                array[j] = array[j-1];
                j--;
            }
            array[j] = tmp;
        }
        return array;
    }
}
