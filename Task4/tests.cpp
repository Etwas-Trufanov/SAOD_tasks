#include "sortLib.hpp"
#include "../Task1/rarray.hpp"
#include <cassert>
#include <vector>
#include <iostream>

void testBubbleSortEmptyArray() {
    // Проверяем пустой массив
    std::vector<int> vec = {};
    vec = slowSort::bubbleSort(vec);
    assert(is_sorted(vec));
    std::cout << "Сортировка пузырьком: пустой массив пройден\n";
}

void testBubbleSortSingleElement() {
    // Проверяем массив из одного элемента
    std::vector<int> vec = {5};
    vec = slowSort::bubbleSort(vec);
    assert(is_sorted(vec));
    std::cout << "Сортировка пузырьком: массив из одного элемента пройден\n";
}

void testBubbleSortSortedArray() {
    // Проверяем уже отсортированный массив
    std::vector<int> vec = {1, 2, 3, 4, 5};
    vec = slowSort::bubbleSort(vec);
    assert(is_sorted(vec));
    std::cout << "Сортировка пузырьком: отсортированный массив пройден\n";
}

void testBubbleSortNonUniqueElements() {
    // Проверяем массив с не уникальными элементами
    std::vector<int> vec = {3, 1, 4, 1, 5, 9, 2, 6, 5};
    vec = slowSort::bubbleSort(vec);
    assert(is_sorted(vec));
    std::cout << "Сортировка пузырьком: не уникальные элементы пройдены\n";
}

void testBubbleSortRightElementSmall() {
    // Проверяем массив, где правый элемент маленький
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 0};
    vec = slowSort::bubbleSort(vec);
    assert(is_sorted(vec));
    std::cout << "Сортировка пузырьком: правый элемент маленький пройден\n";
}

void testBubbleSortLeftElementLarge() {
    // Проверяем массив, где левый элемент большой
    std::vector<int> vec = {20, 1, 2, 3, 4, 5, 6};
    vec = slowSort::bubbleSort(vec);
    assert(is_sorted(vec));
    std::cout << "Сортировка пузырьком: левый элемент большой пройден\n";
}

void testInsertSortEmptyArray() {
    // Проверяем пустой массив
    std::vector<int> vec = {};
    vec = slowSort::insertSort(vec);
    assert(is_sorted(vec));
    std::cout << "Сортировка вставками: пустой массив пройден\n";
}

void testInsertSortSingleElement() {
    // Проверяем массив из одного элемента
    std::vector<int> vec = {5};
    vec = slowSort::insertSort(vec);
    assert(is_sorted(vec));
    std::cout << "Сортировка вставками: массив из одного элемента пройден\n";
}

void testInsertSortSortedArray() {
    // Проверяем уже отсортированный массив
    std::vector<int> vec = {1, 2, 3, 4, 5};
    vec = slowSort::insertSort(vec);
    assert(is_sorted(vec));
    std::cout << "Сортировка вставками: отсортированный массив пройден\n";
}

void testInsertSortNonUniqueElements() {
    // Проверяем массив с не уникальными элементами
    std::vector<int> vec = {3, 1, 4, 1, 5, 9, 2, 6, 5};
    vec = slowSort::insertSort(vec);
    assert(is_sorted(vec));
    std::cout << "Сортировка вставками: не уникальные элементы пройдены\n";
}

void testInsertSortRightElementSmall() {
    // Проверяем массив, где правый элемент маленький
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 0};
    vec = slowSort::insertSort(vec);
    assert(is_sorted(vec));
    std::cout << "Сортировка вставками: правый элемент маленький пройден\n";
}

void testInsertSortLeftElementLarge() {
    // Проверяем массив, где левый элемент большой
    std::vector<int> vec = {20, 1, 2, 3, 4, 5, 6};
    vec = slowSort::insertSort(vec);
    assert(is_sorted(vec));
    std::cout << "Сортировка вставками: левый элемент большой пройден\n";
}

void testShellSortEmptyArray() {
    // Проверяем пустой массив
    std::vector<int> vec = {};
    vec = slowSort::shellSort(vec);
    assert(is_sorted(vec));
    std::cout << "Сортировка Шелла: пустой массив пройден\n";
}

void testShellSortSingleElement() {
    // Проверяем массив из одного элемента
    std::vector<int> vec = {5};
    vec = slowSort::shellSort(vec);
    assert(is_sorted(vec));
    std::cout << "Сортировка Шелла: массив из одного элемента пройден\n";
}

void testShellSortSortedArray() {
    // Проверяем уже отсортированный массив
    std::vector<int> vec = {1, 2, 3, 4, 5};
    vec = slowSort::shellSort(vec);
    assert(is_sorted(vec));
    std::cout << "Сортировка Шелла: отсортированный массив пройден\n";
}

void testShellSortNonUniqueElements() {
    // Проверяем массив с не уникальными элементами
    std::vector<int> vec = {3, 1, 4, 1, 5, 9, 2, 6, 5};
    vec = slowSort::shellSort(vec);
    assert(is_sorted(vec));
    std::cout << "Сортировка Шелла: не уникальные элементы пройдены\n";
}

void testShellSortRightElementSmall() {
    // Проверяем массив, где правый элемент маленький
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 0};
    vec = slowSort::shellSort(vec);
    assert(is_sorted(vec));
    std::cout << "Сортировка Шелла: правый элемент маленький пройден\n";
}

void testShellSortLeftElementLarge() {
    // Проверяем массив, где левый элемент большой
    std::vector<int> vec = {20, 1, 2, 3, 4, 5, 6};
    vec = slowSort::shellSort(vec);
    assert(is_sorted(vec));
    std::cout << "Сортировка Шелла: левый элемент большой пройден\n";
}

void testQuickSortEmptyArray() {
    // Проверяем пустой массив
    std::vector<int> vec = {};
    vec = fastsort::quickSort<int>(vec);
    assert(is_sorted(vec));
    std::cout << "Quicksort: пустой массив пройден\n";
}

void testQuickSortSingleElement() {
    // Проверяем массив из одного элемента
    std::vector<int> vec = {5};
    vec = fastsort::quickSort<int>(vec);
    assert(is_sorted(vec));
    std::cout << "Quicksort: массив из одного элемента пройден\n";
}

void testQuickSortSortedArray() {
    // Проверяем уже отсортированный массив
    std::vector<int> vec = {1, 2, 3, 4, 5};
    vec = fastsort::quickSort<int>(vec);
    assert(is_sorted(vec));
    std::cout << "Quicksort: отсортированный массив пройден\n";
}

void testQuickSortNonUniqueElements() {
    // Проверяем массив с не уникальными элементами
    std::vector<int> vec = {3, 1, 4, 1, 5, 9, 2, 6, 5};
    vec = fastsort::quickSort<int>(vec);
    assert(is_sorted(vec));
    std::cout << "Quicksort: не уникальные элементы пройдены\n";
}

void testQuickSortRightElementSmall() {
    // Проверяем массив, где правый элемент маленький
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 0};
    vec = fastsort::quickSort<int>(vec);
    assert(is_sorted(vec));
    std::cout << "Quicksort: правый элемент маленький пройден\n";
}

void testQuickSortLeftElementLarge() {
    // Проверяем массив, где левый элемент большой
    std::vector<int> vec = {20, 1, 2, 3, 4, 5, 6};
    vec = fastsort::quickSort<int>(vec);
    assert(is_sorted(vec));
    std::cout << "Quicksort: левый элемент большой пройден\n";
}

void testQuickSortAllElementsExist() {
    // Проверяем массив, где левый элемент большой
    std::vector<int> vec = {20, 1, 2, 3, 4, 5, 6};
    vec = fastsort::quickSort<int>(vec);
    assert(is_sorted(vec));
    assert((vec == std::vector{1, 2, 3, 4, 5, 6, 20}));
    std::cout << "Quicksort: левый элемент большой пройден\n";
}

void testMergeSortEmptyArray() {
    // Проверяем пустой массив
    std::vector<int> vec = {};
    vec = fastsort::mergeSort<int>(vec);
    assert(is_sorted(vec));
    std::cout << "Mergesort: пустой массив пройден\n";
}

void testMergeSortSingleElement() {
    // Проверяем массив из одного элемента
    std::vector<int> vec = {5};
    vec = fastsort::mergeSort<int>(vec);
    assert(is_sorted(vec));
    std::cout << "Mergesort: массив из одного элемента пройден\n";
}

void testMergeSortSortedArray() {
    // Проверяем уже отсортированный массив
    std::vector<int> vec = {1, 2, 3, 4, 5};
    vec = fastsort::mergeSort<int>(vec);
    assert(is_sorted(vec));
    std::cout << "Mergesort: отсортированный массив пройден\n";
}

void testMergeSortNonUniqueElements() {
    // Проверяем массив с не уникальными элементами
    std::vector<int> vec = {3, 1, 4, 1, 5, 9, 2, 6, 5};
    vec = fastsort::mergeSort<int>(vec);
    assert(is_sorted(vec));
    std::cout << "Mergesort: не уникальные элементы пройдены\n";
}

void testMergeSortRightElementSmall() {
    // Проверяем массив, где правый элемент маленький
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 0};
    vec = fastsort::mergeSort<int>(vec);
    assert(is_sorted(vec));
    std::cout << "Mergesort: правый элемент маленький пройден\n";
}

void testMergeSortLeftElementLarge() {
    // Проверяем массив, где левый элемент большой
    std::vector<int> vec = {20, 1, 2, 3, 4, 5, 6};
    vec = fastsort::mergeSort<int>(vec);
    assert(is_sorted(vec));
    std::cout << "Mergesort: левый элемент большой пройден\n";
}

void testMergeSortAllElementsExist() {
    // Проверяем массив, где левый элемент большой
    std::vector<int> vec = {20, 1, 2, 3, 4, 5, 6};
    vec = fastsort::mergeSort<int>(vec);
    assert(is_sorted(vec));
    assert((vec == std::vector{1, 2, 3, 4, 5, 6, 20}));
    std::cout << "Mergesort: левый элемент большой пройден\n";
}



int main() {

    // Тесты для сортировки пузырьком
    testBubbleSortEmptyArray();
    testBubbleSortSingleElement();
    testBubbleSortSortedArray();
    testBubbleSortNonUniqueElements();
    testBubbleSortRightElementSmall();
    testBubbleSortLeftElementLarge();

    // Тесты для сортировки вставками
    testInsertSortEmptyArray();
    testInsertSortSingleElement();
    testInsertSortSortedArray();
    testInsertSortNonUniqueElements();
    testInsertSortRightElementSmall();
    testInsertSortLeftElementLarge();

    // Тесты для сортировки Шелла
    testShellSortEmptyArray();
    testShellSortSingleElement();
    testShellSortSortedArray();
    testShellSortNonUniqueElements();
    testShellSortRightElementSmall();
    testShellSortLeftElementLarge();

    // Тесты для быстрой сортировки
    testQuickSortEmptyArray();
    testQuickSortSingleElement();
    testQuickSortSortedArray();
    testQuickSortNonUniqueElements();
    testQuickSortRightElementSmall();
    testQuickSortLeftElementLarge();

    // Тесты для сортировки слиянием
    testMergeSortEmptyArray();
    testMergeSortSingleElement();
    testMergeSortSortedArray();
    testMergeSortNonUniqueElements();
    testMergeSortRightElementSmall();
    testMergeSortLeftElementLarge();

    std::cout << "Все тесты пройдены!\n";
    return 0;
}
