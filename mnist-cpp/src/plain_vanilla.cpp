#include "/home/hardy/Desktop/Cpp/Machine-Learning-cpp/mnist-cpp/include/plain_vanilla.hpp"
#include <random>
#include <cmath>
#include "/home/hardy/Desktop/Cpp/Machine-Learning-cpp/mnist-cpp/include/sigmoid.hpp"
/*
Plain_vanilla::Plain_vanilla(){
                  weights_trans_1 = weights_rand(784,29);
                  weights_trans_2 = weights_rand(20,10);

                  bias_trans_1 = bias_rand(20);
                  bias_trans_2 = bias_rand(10);

                
}

*/

std::vector<double> Plain_vanilla::image_loader_and_normalizer(const Matrix& image){
    std::vector<double> normalized;
    normalized.reserve(784);
    for (int i=0; i < 784; i++){
        normalized.push_back(image.data[i]/ 255);
    }
    return normalized;
}

double deri_sigm(double z){
    return (z*exp(z)/ ( 1 + exp(-1 * z)));
}

std::vector<double> Plain_vanilla::output_error(int label, std::vector<double> activations, std::vector<double> predictions){
    std::vector<double> error_derivative_matrix;
    error_derivative_matrix.reserve(10);
    for (int i=0; i < 10; i++){
        for(int i=0; i < 10; i++){
        if ( i == label ){
            error_derivative_matrix.push_back((predictions[i]-1)* activations[i]*(1-activations[i]));
        }else{
            error_derivative_matrix.push_back((predictions[i]) * activations[i]*(1-activations[i]));
        }
    }

    }

    return error_derivative_matrix;
}

std::vector<double> Plain_vanilla::z_values(std::vector<std::vector<double>> weights, std::vector<double> bias, std::vector<double> input_vector){
       
    std::vector<double> a_values;
    int wt_rows = weights.size();
    int wt_cols = weights[0].size(); 
    for(int i =0; i < wt_rows; i ++){
        for (int j = 0; j < wt_cols; j++){
            a_values.push_back(weights[i][j]*input_vector[j] + bias[i]);
        }
    }
    return a_values;
}

std::vector<double> Plain_vanilla::activations(std::vector<double> z){
    Sigmoid sigm;
    return sigm.func(z);
}
double Plain_vanilla::cost_function(int label, std::vector<double> predictions){
    double cost = 0.0;
    
    for(int i=0; i < 10; i++){
        if ( i == label ){
            cost = cost + (predictions[i]-1)*(predictions[i]-1);
        }else{
            cost = cost + (predictions[i])*(predictions[i]);
        }
    }

    return cost/2;
}

std::vector<std::vector<double>> Plain_vanilla::weights_rand(int rows, int cols){
    std::default_random_engine generator (std::random_device{}());
    std::uniform_real_distribution<double> distribution(-2,2);
    
    std::vector<std::vector<double>> weights(rows);
    
    for (int i=0; i < rows; i++){
        weights[i].reserve(cols);
        for (int j=0; j < cols; j++){
            weights[i].push_back(distribution(generator));
        }
    }
    return weights;
}

std::vector<double> Plain_vanilla::bias_rand(int cols){
    
    std::vector<double> bias;
    bias.reserve(cols);
    std::default_random_engine generator (std::random_device{}());
    std::uniform_real_distribution<double> distribution(0,10);

    for (int i=0; i < cols; i++){
        bias.push_back(distribution(generator));
    }
    return bias;
}

