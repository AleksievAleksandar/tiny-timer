#include "tiny_timer.h"

using namespace tiny;

Timer::Timer()
    : m_start {std::chrono::high_resolution_clock::now()}
    , m_stop_is_called {false}
{}

Timer::~Timer()
{
    if(!m_stop_is_called)
    {
        auto l_end {stop()};
        printf("Duration: %ldus (%0.2fms)\n", l_end, l_end * 0.001);
        printf("file: %s | line: %d | func: %s\n", __FILE__, __LINE__, __func__);
    }
}

auto Timer::stop() -> int64_t
{
    auto l_end_time {std::chrono::high_resolution_clock::now()};

    auto l_start {std::chrono::time_point_cast<std::chrono::microseconds>(m_start).time_since_epoch().count()};
    auto l_end {std::chrono::time_point_cast<std::chrono::microseconds>(l_end_time).time_since_epoch().count()};
    m_stop_is_called = true;
    return l_end - l_start;
}

