#include <iostream>
#include <vector>
#include <chrono>
#include <random>

double sum_of_squares(const std::vector<double>& arr) {
    double total = 0;
    for (double i : arr) {
        total += i * i;
    }
    return total;
}

int main() {
    std::vector<double> data(10000000);
    std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution(0.0,1.0);

    // Generate random numbers
    for (double& value : data) {
        value = distribution(generator);
    }

    // Time the execution
    auto start_time = std::chrono::high_resolution_clock::now();
    double result = sum_of_squares(data);
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end_time - start_time;

    std::cout << "Result: " << result << std::endl;
    std::cout << "Time taken with C++: " << elapsed.count() << " seconds" << std::endl;

    return 0;
}
