#include <mutex>

#include <hpx/algorithm.hpp>
#include <hpx/execution.hpp>
#include <hpx/hpx_main.hpp>
#include <hpx/iostream.hpp>
#include <hpx/runtime_local/runtime_local_fwd.hpp>

int main() {
    constexpr int work_items = 16;
    const auto worker_count = hpx::get_num_worker_threads();
    std::mutex output_mutex;

    hpx::experimental::for_loop(
        hpx::execution::par, 0, work_items,
        [worker_count, &output_mutex](int iteration) {
            std::lock_guard<std::mutex> lock(output_mutex);
            hpx::cout << "Hello World from iteration " << iteration
                      << " on worker " << hpx::get_worker_thread_num() << " of "
                      << worker_count << '\n'
                      << std::flush;
        });

    return 0;
}