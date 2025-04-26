#include <iostream>
#include "tiny_timer.h"

void foo(int a)
{
    printf("Hello World %d\n", a);
}


int32_t main()
{
    int a = 11;
    tiny::Timer timer;
    for (size_t i = 0; i < 1'000'000; i++)
    {
        a = i;
    }
    printf("%d\n", a);

    // tiny::Timer t2;
    // tiny::Call_Stats stats = CALLING_DURATION(t2, foo, 900, 13);
    // printf("cnt = %lu\n", stats.m_call_count);
    return EXIT_SUCCESS;
}