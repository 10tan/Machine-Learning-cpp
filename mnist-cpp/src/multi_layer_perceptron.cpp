#include "/home/hardy/Desktop/Cpp/Machine-Learning-cpp/mnist-cpp/include/multi_layer_perceptron.hpp"
#include <random>

Multi_layer_perceptron::Multi_layer_perceptron(double lr, int id){
    learning_rate = lr;
    neuron_id = id;
    bias = 0.0;

    //initialize 784 weights with small random values
    std::default_random_engine generator(std::random_device{}());
    std::uniform_real_distribution<double> distribution(-0.01, 0.01);


    weights.resize(784);
    for (int i=0; i < 784; ++i){
        weights[i] = distribution(generator);
    }
}

int Multi_layer_perceptron::predict (const Matrix& image){
    double weighted_sum = bias;

    //multiply each pixel by its weight
    for(int i=0; i < 784; ++i){
        weighted_sum += image.data[i] * weights[i];
    }
    
    // step activation functions
    if(weighted_sum > 0.0){
        return 1; // neuron thinks it is a '0'
    }else{
        return 0; // neuron thinks it is not 0
    }
}

double Multi_layer_perceptron::get_weighted_sum(const Matrix& image){
    double score = bias;
    for(int i =0; i < 784; ++i){
        score += image.data[i] * weights[i];
    }
    return score; // returns raw score could be positive or negative
}

void Multi_layer_perceptron::train_sample(const Matrix& image, int true_digits){
    // convert our 0-9 into a binary target
    int target = ( true_digits == neuron_id ) ? 1 : 0;

    int guess = predict(image);

    int error = target - guess;
    if (error != 0){
        bias += learning_rate * error;
        for (int i=0; i < 784; ++i){
            weights[i] += learning_rate * error * image.data[i];
        }
    }

}

void Multi_layer_perceptron::force_update_positive(const Matrix& image){
    bias += learning_rate * 1.0;
    for (int i=0; i < 784; ++i){
        weights[i] += learning_rate * 1.0 * image.data[i];
    }
}

void Multi_layer_perceptron::force_update_negative(const Matrix& image){
    bias += learning_rate * -1.0;
    for(int i=0; i < 784; ++i){
        weights[i] += learning_rate * -1.0 * image.data[i];
    }
}
