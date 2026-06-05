#include "/home/hardy/Desktop/Cpp/Machine-Learning-cpp/mnist-cpp/include/sigmoid.hpp"
#include <vector>
#include <cmath>

std::vector<double> Sigmoid:: func(const std::vector<double>& numerics){
    std::vector<double> results ;

    for (double numeric : numerics){
        results.push_back(1/(1 + std::exp(-1 * numeric)));
    }

    return results;
}
