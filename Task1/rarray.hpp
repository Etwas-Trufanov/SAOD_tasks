#include <concepts>
#include <cstddef>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <random> 

// Шаблон функции для работы с массивами целых чисел
template <typename T>
requires std::integral<T>
// Метод для заполнения массива случайными числами в заданном диапазоне
T* fill_random(std::size_t input_quantity, T min, T max) {
    std::random_device rd; 
    std::mt19937 gen(rd()); // Инициализация генератора случайных чисел
    std::uniform_int_distribution<> distrib(min, max);
    T* data = new T[input_quantity];
    // Генерация случайных чисел в диапазоне [min, max]
    for (std::size_t i = 0; i < input_quantity; i++) {
        data[i] = min + distrib(gen) % (max - min + 1);
    }
    return data;
}

template <typename T>
requires std::integral<T>
// Метод для заполнения массива возрастающими случайными числами в диапазоне [min, max]
T* fill_inc_random(std::size_t input_quantity, T min, T max) {
    srand(static_cast<unsigned int>(time(nullptr))); // Инициализация генератора случайных чисел
    T *data = new T[input_quantity];
    // Сначала просто заполняем массив неслучайными числами в диапазоне [min, max]
    for (std::size_t i = 0; i < input_quantity; i++) {
        data[i] = min + ((max/input_quantity) * i);

    }
    // Создаём массив, того на сколько каждое число может быть увеличено, чтобы сохранить порядок возрастания
    T *increments = new T[input_quantity];
    increments[input_quantity-1] = max - data[input_quantity-1]; // Последний элемент может быть увеличен до max
    for (std::size_t i = 0; i < input_quantity-1; i++) {
        increments[i] = data[i+1] - data[i];
    }
    // Теперь добавляем к каждому элементу массива случайное число из диапазона [0, increments[i]]
    for (std::size_t i = 0; i < input_quantity; i++) {
        if (increments[i] > 0) {
            data[i] += rand() % (increments[i] + 1);
        }
    }

    return data;
}

template <typename T>
requires std::integral<T>
// Метод для проверки, отсортирован ли массив по возрастанию
bool is_sorted(T *data, std::size_t input_quantity) {
    for (std::size_t i = 1; i < input_quantity; i++) {
        if (data[i] < data[i - 1]) {
            return false;
        }
    }
    return true;
}

template <typename T>
requires std::integral<T>
// Метод для печати элементов массива
void print(T *data, std::size_t input_quantity) {
    for (std::size_t i = 0; i < input_quantity; i++) {
        std::cout << data[i] << std::endl;
    }
}

template <typename T>
requires std::integral<T>
// Метод для сохранения элементов массива в файл
void save_to_file(const char* filename, T *data, std::size_t input_quantity) {
    std::ofstream file;
    file.open(filename);
    for (std::size_t i = 0; i < input_quantity; i++) {
        file << data[i] << std::endl;
    }
    file.close();
}
