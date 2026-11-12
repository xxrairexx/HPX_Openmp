#include <iostream>
#include <omp.h>

int main() {
    constexpr int work_items = 16;

    #pragma omp parallel for
    for (int iteration = 0; iteration < work_items; ++iteration)
    {
        int thread_id = omp_get_thread_num();
        int total_threads = omp_get_num_threads();

        #pragma omp critical
        {
            std::cout << "Hello World from iteration " << iteration
                      << " on thread " << thread_id << " of " << total_threads
                      << std::endl;
        }
    }

    return 0;
}
