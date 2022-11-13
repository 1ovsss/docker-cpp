#include <immintrin.h>

#include <chrono>
#include <cmath>
#include "format.h"

uint64_t rdtsc() {
        uint32_t hi, lo;
        __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
        return ( (uint64_t)lo)|( ((uint64_t)hi)<<32 );
}

int main() {
        {
		nice::print_header("multiplication");
                for (size_t i = 4; i < 9; ++i) {
                        double val1 = 6.0;
                        double val2 = 4.0;
                        std::size_t operations = pow(10, i);
                        auto start = std::chrono::system_clock::now();
                        unsigned long long t1 = rdtsc();
                        for (size_t j = 0; j < pow(10, i); ++j) {
                                val1 = val1 * val2;
                        }
                        unsigned long long t2 = rdtsc();
                        std::chrono::duration<double> duration =
                            std::chrono::system_clock::now() - start;
                        double seconds = duration.count();
                        double operations_per_second = operations / seconds;
                        uint64_t processor_clocks = t2 - t1;
                        double processor_clocks_per_second = processor_clocks / seconds;
			nice::print_line(operations, seconds, operations_per_second,
                                   processor_clocks, processor_clocks_per_second);
                }
                nice::print_divider();
                nice::print_endls();
        }
        {
                nice::print_header("SSE2 multiplication");
                for (size_t i = 4; i < 9; ++i) {
                        const double array[2] = {6.0, 4.0};
                        const double array2[2] = {4.0, 4.0};
                        __m128d val1 = _mm_load_pd(&array[0]);
                        __m128d val2 = _mm_load_pd(&array2[0]);
                        std::size_t operations = pow(10, i);
                        auto start = std::chrono::system_clock::now();
                        unsigned long long t1 = rdtsc();
                        for (size_t j = 0; j < pow(10, i) / 2; ++j) {
                                val1 = _mm_mul_pd(val1, val2);
                        }
                        unsigned long long t2 = rdtsc();
                        std::chrono::duration<double> duration =
                            std::chrono::system_clock::now() - start;
                        double seconds = duration.count();
                        double operations_per_second = operations / seconds;
                        uint64_t processor_clocks = t2 - t1;
                        double processor_clocks_per_second = processor_clocks / seconds;
                        nice::print_line(operations, seconds, operations_per_second,
                                   processor_clocks, processor_clocks_per_second);
                }
                nice::print_divider();
                nice::print_endls();
        }
        {
                nice::print_header("AVX2 multiplication");
                for (size_t i = 4; i < 9; ++i) {
                        const double array[4] = {6.0, 6.0, 6.0, 6.0};
                        const double array2[4] = {4.0, 4.0, 4.0, 4.0};
                        __m256d val1 = _mm256_load_pd(&array[0]);
                        __m256d val2 = _mm256_load_pd(&array2[0]);
                        std::size_t operations = pow(10, i);
                        auto start = std::chrono::system_clock::now();
                        unsigned long long t1 = rdtsc();
                        for (size_t j = 0; j < pow(10, i) / 4; ++j) {
                                val1 = _mm256_mul_pd(val1, val2);
                        }
                        unsigned long long t2 = rdtsc();
                        std::chrono::duration<double> duration =
                            std::chrono::system_clock::now() - start;
                        double seconds = duration.count();
                        double operations_per_second = operations / seconds;
                        uint64_t processor_clocks = t2 - t1;
                        double processor_clocks_per_second = processor_clocks / seconds;
                        nice::print_line(operations, seconds, operations_per_second,
                                   processor_clocks, processor_clocks_per_second);
                }
                nice::print_divider();
        }
}
