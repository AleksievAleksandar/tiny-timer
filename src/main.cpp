#include <iostream>
#include <chrono>
#include <functional>

#define CALLING_DURATION(timer, func, duration, ...) \
    (timer).calling_duration(func, duration, #func, ##__VA_ARGS__)


void foo(int a)
{
    printf("Hello World %d\n", a);
}

struct Call_Stats 
{
    size_t m_call_count;
    int64_t m_duration_us;
};

class Timer
{
public:
    Timer()
        : m_start {std::chrono::high_resolution_clock::now()}
        , m_stop_is_called {false}
    {}

    ~Timer()
    {
        if(!m_stop_is_called)
        {
            auto l_end {stop()};
            printf("Duration: %ldus (%0.2fms)\n", l_end, l_end * 0.001);
            printf("file: %s | line: %d | func: %s\n", __FILE__, __LINE__, __func__);
        }
    }

    auto stop() -> int64_t
    {
        auto l_end_time {std::chrono::high_resolution_clock::now()};

        auto l_start {std::chrono::time_point_cast<std::chrono::microseconds>(m_start).time_since_epoch().count()};
        auto l_end {std::chrono::time_point_cast<std::chrono::microseconds>(l_end_time).time_since_epoch().count()};
        m_stop_is_called = true;
        return l_end - l_start;
    }

        // Run this function f() as many times as you can for exactly p_us microseconds, 
    // then stop, and report how many times it ran.
    /**
     * @brief Executes the provided function repeatedly for a specified duration.
     * 
     * @tparam F The callable type (e.g., function, lambda, or functor).
     * @tparam Args The types of the arguments to be passed to the callable.
     * @param f The callable to be executed.
     * @param p_us The duration in microseconds for which the function should be executed.
     * @param func_name The name of the function.
     * @param args The arguments to be passed to the callable.
     * @return size_t The number of times the callable was executed within the specified duration.
     */
    template <typename F, typename... Args>
    Call_Stats calling_duration(F&& f, int64_t p_us, const char* func_name, Args&&... args)
    {
        auto l_start {std::chrono::high_resolution_clock::now()};
        size_t l_call_cnt {0};
        while (true)
        {
            std::invoke(std::forward<F>(f), std::forward<Args>(args)...);
            auto now = std::chrono::high_resolution_clock::now();
            ++l_call_cnt;
            if (std::chrono::duration_cast<std::chrono::microseconds>(now - l_start).count() >= p_us)
                break;
        }
        printf("Function name: %s()\n", func_name);
        printf("call cnt = %lu\n", l_call_cnt);

        int64_t l_elapsed = std::chrono::duration_cast<std::chrono::microseconds>(
            std::chrono::high_resolution_clock::now() - l_start).count();

        return {l_call_cnt, l_elapsed};
    }

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> m_start;
    bool m_stop_is_called;
};

int32_t main()
{
    // int a = 11;
    // Timer timer;
    // for (size_t i = 0; i < 1'000'000; i++)
    // {
    //     a = i;
    // }
    // printf("%d\n", a);

    Timer t2;
    Call_Stats stats = CALLING_DURATION(t2, foo, 900, 13);
    printf("cnt = %lu\n", stats.m_call_count);
    return EXIT_SUCCESS;
}