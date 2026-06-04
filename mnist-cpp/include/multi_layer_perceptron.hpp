#ifndef MULTI_LAYER_PERCEPTRON_HPP
#define MULTI_LAYER_PERCEPTRON_HPP

#include "data.hpp"
#include <vector>

class Multi_layer_perceptron{

    private:
        std::vector<double> weights;
        double bias;
        double learning_rate;
        int neuron_id;

    public:
        // constructor sets up 784 weights to tiny random numbers
        Multi_layer_perceptron(double lr, int id);

        // predicts 1 (if image is 0), else 0 
        int predict(const Matrix& image);

        //return raw scores
        double get_weighted_sum(const Matrix& image);

        //trains the single neuron on the image sample
        void train_sample(const Matrix& image, int true_label);

        void force_update_positive(const Matrix& image);

        void force_update_negative(const Matrix& image);
};

#endif
