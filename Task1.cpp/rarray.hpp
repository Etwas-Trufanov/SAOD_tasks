#include <concepts>
#include <fstream>
#include <iostream>

// Шаблон класса для работы с массивами целых чисел
template <typename T>
requires std::integral<T>
class massive {
    private:
        T *data;
        std::size_t quantity;
    public:
        // Конструктор по умолчанию
        massive() : data(nullptr) {}

        // Метод для заполнения массива готовым массивом
        void fill(const T *input_data, std::size_t input_quantity) {
            quantity = input_quantity;
            data = new T[quantity];
            for (std::size_t i = 0; i < quantity; i++) {
                data[i] = input_data[i];
            }
        }
        
        // Метод для заполнения массива возрастающими случайными числами в заданном диапазоне
        void fill_random(std::size_t input_quantity, T min, T max) {
            srand(static_cast<unsigned int>(time(nullptr))); // Инициализация генератора случайных чисел
            quantity = input_quantity;
            data = new T[quantity];
            // Генерация случайных чисел в диапазоне [min, max]
            for (std::size_t i = 0; i < quantity; i++) {
                data[i] = min + rand() % (max - min + 1);
            }
        }

        // Метод для заполнения массива возрастающими случайными числами в диапазоне [min, max]
        void fill_inc_random(std::size_t input_quantity, T min, T max) {
            srand(static_cast<unsigned int>(time(nullptr))); // Инициализация генератора случайных чисел
            quantity = input_quantity;
            data = new T[quantity];
            // Сначала просто заполняем массив неслучайными числами в диапазоне [min, max]
            for (std::size_t i = 0; i < quantity; i++) {
                data[i] = min + ((max/quantity) * i);

            }
            // Создаём массив, того на сколько каждое число может быть увеличено, чтобы сохранить порядок возрастания
            T *increments = new T[quantity];
            increments[quantity-1] = max - data[quantity-1]; // Последний элемент может быть увеличен до max
            for (std::size_t i = 0; i < quantity-1; i++) {
                increments[i] = data[i+1] - data[i];
            }
            // Теперь добавляем к каждому элементу массива случайное число из диапазона [0, increments[i]]
            for (std::size_t i = 0; i < quantity; i++) {
                if (increments[i] > 0) {
                    data[i] += rand() % (increments[i] + 1);
                }
            }
        }

        // Метод для проверки, отсортирован ли массив по возрастанию
        bool is_sorted() const {
            for (std::size_t i = 1; i < quantity; i++) {
                if (data[i] < data[i - 1]) {
                    return false;
                }
            }
            return true;
        }

        // Метод для печати элементов массива
        void print() const {
            for (std::size_t i = 0; i < quantity; i++) {
                std::cout << data[i] << std::endl;
            }
        }

        // Метод для сохранения элементов массива в файл
        void save_to_file(const char* filename) {
            std::ofstream file;
            file.open(filename);
            for (std::size_t i = 0; i < quantity; i++) {
                file << data[i] << std::endl;
            }
            file.close();
        }

        // Деструктор для освобождения выделенной памяти
        ~massive() {
            delete[] data;
        }
};
