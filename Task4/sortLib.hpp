#pragma once
#include <cstddef>
#include <vector>

namespace fastsort {
    template<typename T>
    std::vector<T> operator+(std::vector<T> left, const std::vector<T>& right) {
        left.insert(left.end(), right.begin(), right.end());
        return left;
    }

    template<typename T>
    std::vector<T> quickSort(const std::vector<T> &array) {
        if (array.size() < 2) {
            return array;
        }

        T pivot = array[array.size()/2];
        std::vector<T> left;
        std::vector<T> right;

        for (std::size_t i = 0; i < array.size()-1; i++) {
            if (array[i] <= pivot) {
                left.emplace_back(array[i]);
            } else {
                right.emplace_back(array[i]);
            }
        }
        return quickSort<T>(left) + std::vector<T>{pivot} + quickSort<T>(right);
    }
}

namespace slowSort {
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
