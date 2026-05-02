// timer.h
#pragma once
#include <chrono>

class TTimer {
public:
    using Milliseconds = std::chrono::milliseconds::rep;
    using Nanoseconds = std::chrono::nanoseconds::rep;

    // Замер принимаемой лямбда функции
    template<typename Func, typename... Args>
    static Milliseconds measure(Func&& func, Args&&... args) {
        auto start = std::chrono::steady_clock::now();
        std::forward<Func>(func)(std::forward<Args>(args)...);
        auto end = std::chrono::steady_clock::now();
        return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    }

    // Замер времени в наносекундах
    template<typename Func>
    static Nanoseconds measureNano(Func &&func) {
        auto start = std::chrono::high_resolution_clock::now();

        func();

        auto end = std::chrono::high_resolution_clock::now();

        return std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    }
};
