#ifndef PERCEPTRON_HPP
#define PERCEPTRON_HPP

#include "data.hpp"
#include <vector>

class Perceptron{

    private:
        std::vector<double> weights;
        double bias;
        double learning_rate;

    public:
        // constructor sets up 784 weights to tiny random numbers
        Perceptron(double lr);

        // predicts 1 (if image is 0), else 0 
        int predict(const Matrix& image);

        //trains the single neuron on the image sample
        void train_sample(const Matrix& image, int true_label);
};

#endif
