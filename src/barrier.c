
#include <stdio.h>
#include <omp.h>

int main(void)
{
    #pragma omp parallel num_threads(4)
    {
        int thread_id = omp_get_thread_num();

        printf("Thread %d reached the first phase\n", thread_id);

        #pragma omp barrier

        printf("Thread %d passed the barrier\n", thread_id);
    }

    return 0;
}
