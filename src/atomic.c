
#include <stdio.h>
#include <omp.h>

int main(void)
{
    long long counter = 0;

    #pragma omp parallel num_threads(4)
    {
        for (long long i = 0; i < 2500000; i++)
        {
            #pragma omp atomic
            counter++;
        }
    }

    printf("Counter = %lld\n", counter);
    printf("Expected Counter = 10000000\n");

    return 0;
}
