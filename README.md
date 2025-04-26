# tiny-timer

tiny-timer is a simple, lightweight C++ library that measures how many times a function can be called within a specific time frame (in microseconds).
It also offers easy-to-use scope timing for benchmarking and profiling.
---
✨ Features

    Measure function call throughput
    Supports any callable: functions, lambdas, functors
    RAII-based scope timer
    No external dependencies
    Header-only usage possible
    Lightweight & portable
---
🚀 Installation

    git clone https://github.com/AleksievAleksandar/tiny-timer.git
    cd tiny-timer
    mkdir build
    cd build
    cmake ..
    make
---
📚 Usage

Measure how many times a function can run in 1 millisecond:

```c
#include "timer.hpp"

void my_function(int x) 
{
    // Simulate work
}

int main() 
{
    Timer t;
    auto result = CALLING_DURATION(t, my_function, 1000, 13);

    std::cout << "Executed " << result.call_count 
                << " times in " << result.elapsed_time_us << "us\n";
}
```
---
Scope Timing Example

Measure duration of a code block automatically:
```c
{
    Timer t; // Starts timing
    // ... your code ...
} // Automatically prints elapsed time at scope end
```
---
📦 API Overview

    Function                    | Description
    Timer::call_for_duration    | Run a callable for a set microsecond duration
    Timer::~Timer               | Print elapsed time when object goes out of scope
    Timer::stop                 | Manually stop the timer and get elapsed time
---
✅ Planned Features

    Add unit tests (Catch2)
    Optional compile flags (quiet output)
    Support min/avg/max time per call