
#include <stdio.h>
#include <omp.h>

#define ITERATIONS 10000000LL

int main(void)
{
    int thread_counts[] = {1, 2, 4, 8};
    int number_of_tests = sizeof(thread_counts) / sizeof(thread_counts[0]);

    printf("Synchronization Mechanism Benchmark\n");
    printf("Shared increments: %lld\n\n", ITERATIONS);
    printf("Mechanism | Threads | Final Count | Time (seconds)\n");

    for (int t = 0; t < number_of_tests; t++)
    {
        int threads = thread_counts[t];
        long long counter = 0;
        double start, elapsed;

        start = omp_get_wtime();

        #pragma omp parallel for num_threads(threads)
        for (long long i = 0; i < ITERATIONS; i++)
        {
            counter++;
        }

        elapsed = omp_get_wtime() - start;

        printf("None      | %7d | %11lld | %.6f\n",
               threads, counter, elapsed);

        counter = 0;
        start = omp_get_wtime();

        #pragma omp parallel num_threads(threads) shared(counter)
        {
            for (long long i = 0; i < ITERATIONS / threads; i++)
            {
                #pragma omp critical
                {
                    counter++;
                }
            }
        }

        elapsed = omp_get_wtime() - start;

        printf("Critical  | %7d | %11lld | %.6f\n",
               threads, counter, elapsed);

        counter = 0;
        start = omp_get_wtime();

        #pragma omp parallel num_threads(threads) shared(counter)
        {
            for (long long i = 0; i < ITERATIONS / threads; i++)
            {
                #pragma omp atomic
                counter++;
            }
        }

        elapsed = omp_get_wtime() - start;

        printf("Atomic    | %7d | %11lld | %.6f\n",
               threads, counter, elapsed);
        printf("-----------------------------------------------\n");
    }

    printf("Expected correct final count = %lld\n", ITERATIONS);
    return 0;
}
