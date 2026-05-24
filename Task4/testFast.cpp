#include "sortLib.hpp"
#include "../Task1/rarray.hpp"
#include <cassert>
#include <vector>
#include <iostream>

void testBubbleSortEmptyArray() {
    // Проверяем пустой массив
    std::vector<int> vec = {};
    vec = fastsort::quickSort<int>(vec);
    assert(is_sorted(vec));
    std::cout << "Quicksort: пустой массив пройден\n";
}

void testBubbleSortSingleElement() {
    // Проверяем массив из одного элемента
    std::vector<int> vec = {5};
    vec = fastsort::quickSort<int>(vec);
    assert(is_sorted(vec));
    std::cout << "Quicksort: массив из одного элемента пройден\n";
}

void testBubbleSortSortedArray() {
    // Проверяем уже отсортированный массив
    std::vector<int> vec = {1, 2, 3, 4, 5};
    vec = fastsort::quickSort<int>(vec);
    assert(is_sorted(vec));
    std::cout << "Quicksort: отсортированный массив пройден\n";
}

void testBubbleSortNonUniqueElements() {
    // Проверяем массив с не уникальными элементами
    std::vector<int> vec = {3, 1, 4, 1, 5, 9, 2, 6, 5};
    vec = fastsort::quickSort<int>(vec);
    assert(is_sorted(vec));
    std::cout << "Quicksort: не уникальные элементы пройдены\n";
}

void testBubbleSortRightElementSmall() {
    // Проверяем массив, где правый элемент маленький
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 0};
    vec = fastsort::quickSort<int>(vec);
    assert(is_sorted(vec));
    std::cout << "Quicksort: правый элемент маленький пройден\n";
}

void testBubbleSortLeftElementLarge() {
    // Проверяем массив, где левый элемент большой
    std::vector<int> vec = {20, 1, 2, 3, 4, 5, 6};
    vec = fastsort::quickSort<int>(vec);
    assert(is_sorted(vec));
    std::cout << "Quicksort: левый элемент большой пройден\n";
}


int main() {
    // Тесты для быстрой сортировки
    testBubbleSortEmptyArray();
    testBubbleSortSingleElement();
    testBubbleSortSortedArray();
    testBubbleSortNonUniqueElements();
    testBubbleSortRightElementSmall();
    testBubbleSortLeftElementLarge();

    std::cout << "Все тесты пройдены!\n";
    return 0;
}
