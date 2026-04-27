// timer.h
#pragma once
#include <chrono>

class TTimer {
public:
    using Milliseconds = std::chrono::milliseconds::rep;

    // Замеряет время выполнения произвольного вызываемого объекта
    template<typename Func>
    static Milliseconds measure(Func&& func) {
        auto start = std::chrono::steady_clock::now();
        std::forward<Func>(func)();  // выполняем функцию
        auto end = std::chrono::steady_clock::now();
        return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    }

    // Перезагружаемая версия: принимает аргументы для функции
    template<typename Func, typename... Args>
    static Milliseconds measure(Func&& func, Args&&... args) {
        auto start = std::chrono::steady_clock::now();
        std::forward<Func>(func)(std::forward<Args>(args)...);
        auto end = std::chrono::steady_clock::now();
        return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    }
};