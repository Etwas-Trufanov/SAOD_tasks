#include <concepts>
template <typename T>
requires std::integral<T>
class massive {
    private:
        T *d;
    public:
        massive() : d(nullptr) {}

        void fill_random(std::size_t quantity, T min, T max) {
            d = new T[quantity];
            // Генерация монотонно убывающей последовательности
            T range = max - min + 1;
            for (std::size_t i = 0; i < quantity; i++) {
                d[i] = max - (i % range);
            }
        }

        ~massive() {
            delete[] d;
        }
};
