#ifndef PLAIN_VANILLA_HPP
#define PLAIN_VANILLA_HPP

#include "data.hpp"
#include <vector>

class Plain_vanilla{
    private:
        std::vector<std::vector<double>> weights_trans_1;
        std::vector<std::vector<double>> weights_trans_2;
        std::vector<double> bias_trans_1;
        std::vector<double> bias_trans_2;

    public:
        Plain_vanilla();    
        std::vector<std::vector<double>> weight_updater(std::vector<std::vector<double>> weights, std::vector<double> output_err, std::vector<double> activation_val, double learning_rate);
        
        std::vector<double> bias_updater(std::vector<double> bias, std::vector<double> output_err, double learning_rate);

        std::vector<double> output_error(int label, std::vector<double> activations, std::vector<double> predictions);
        std::vector<double> output_error_hidden(std::vector<double> output_err, std::vector<std::vector<double>> weights);
        std::vector<double> image_loader_and_normalizer(const Matrix& image);
        double cost_function(int label, std::vector<double> predictions);
        std::vector<double> z_values(std::vector<std::vector<double>> weights, std::vector<double> bias, std::vector<double> input_vector);
        std::vector<double> activations(std::vector<double> z);
        std::vector<double> bias_rand(int cols);
        std::vector<std::vector<double>> weights_rand(int rows,int cols);

};

#endif
