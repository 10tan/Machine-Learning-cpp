#include "/home/hardy/Desktop/Cpp/Machine-Learning-cpp/mnist-cpp/include/perceptron.hpp"
#include <random>

Perceptron::Perceptron(double lr){
    learning_rate = lr;
    bias = 0.0;

    //initialize 784 weights with small random values
    std::default_random_engine generator(std::random_device{}());
    std::uniform_real_distribution<double> distribution(-0.01, 0.01);


    weights.resize(784);
    for (int i=0; i < 784; ++i){
        weights[i] = distribution(generator);
    }
}

int Perceptron::predict (const Matrix& image){
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

void Perceptron::train_sample(const Matrix& image, int true_digits){
    // convert our 0-9 into a binary target
    int target = ( true_digits == 0 ) ? 1 : 0;

    int guess = predict(image);

    int error = target - guess;
    if (error != 0){
        bias += learning_rate * error;
        for (int i=0; i < 784; ++i){
            weights[i] += learning_rate * error * image.data[i];
        }
    }

}
