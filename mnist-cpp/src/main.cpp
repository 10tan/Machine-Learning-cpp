// #include "/home/hardy/Desktop/Cpp/Machine-Learning-cpp/mnist-cpp/include/perceptron.hpp"
#include "/home/hardy/Desktop/Cpp/Machine-Learning-cpp/mnist-cpp/include/data_handler.hpp"
//#include "/home/hardy/Desktop/Cpp/IMachine-Learning-cpp/mnist-cpp/include/multi_layer_perceptron.hpp"

#include "/home/hardy/Desktop/Cpp/Machine-Learning-cpp/mnist-cpp/include/plain_vanilla.hpp"
#include "/home/hardy/Desktop/Cpp/Machine-Learning-cpp/mnist-cpp/include/ascii.hpp"
#include <iostream>
#include <random>
#include <vector>
/*
void perceptron_call(){

    // instance of our loader and our perceptron
    DataHandler handler;
    
    // we set learning rate = 0.01, so the weights change gently
    Perceptron neuron(0.01);

    std::cout << "loading MNIST dataset.." << std::endl;
    handler.loadTrainingData("/home/hardy/Desktop/Cpp/Machine-Learning-cpp/mnist-cpp/data/raw/train-images.idx3-ubyte", "/home/hardy/Desktop/Cpp/Machine-Learning-cpp/mnist-cpp/data/raw/train-labels.idx1-ubyte");
    handler.loadTestData("/home/hardy/Desktop/Cpp/Machine-Learning-cpp/mnist-cpp/data/raw/t10k-images.idx3-ubyte", "/home/hardy/Desktop/Cpp/Machine-Learning-cpp/mnist-cpp/data/raw/t10k-labels.idx1-ubyte");

    if (handler.training_data.empty() || handler.test_data.empty()){
        std::cout << "error loading dataset, kindly check the paths " << std::endl;
    }

    std::cout << "starting training loop" << std::endl;

    int total_epoch;
    std::cout << "enter epoch : " ;
    std::cin >> total_epoch ;

    for (int epoch = 1; epoch <= total_epoch; ++epoch){
        int correct_guesses = 0;
        for (size_t i=0; i < handler.training_data.size(); ++i){
            Matrix image = handler.training_data[i].image;
            int true_label = handler.training_data[i].label;

            int expected_binary = (true_label == 0 ) ? 1 : 0;

            if (neuron.predict(image) == expected_binary){
                correct_guesses++;
            }

            //train the neuron on this sample, update weights
            neuron.train_sample(image,true_label);
        }
        double accuracy = ((double)correct_guesses / handler.training_data.size()) * 100;
        std::cout << "epoch " << epoch << " training accuracy " << accuracy <<"%" << std::endl; 
    }

    std::cout << "starting testing loops (unseen data) " << std::endl;

    int test_correct = 0;
    for (size_t i = 0; i < handler.test_data.size(); ++i){
        Matrix image = handler.test_data[i].image;
        int true_label = handler.test_data[i].label;
        int expected_binary = (true_label == 0) ? 1 : 0;
        if (neuron.predict(image) == true_label){
            test_correct ++;
        }
    }
    double test_accuracy = ((double)test_correct / handler.test_data.size()) * 100.0;
    std::cout << "final test accuracy on test data : " << test_accuracy << "%" << std::endl;

}
*/

/*
int get_network_guess(const Matrix& image, std::vector<Multi_layer_perceptron>& network){
    int best_digit= 0;
    double highest_score = network[0].get_weighted_sum(image);

    for (int i=1; i < 10 ; ++i){
        double current_score = network[i].get_weighted_sum(image);
        if(current_score > highest_score){
            highest_score = current_score;
            best_digit = i;
        }
    }
    return best_digit;
}
void multi_layer_perceptron_call(){
    std::cout << "MULTI-LAYER-PERCEPTRON" << std::endl;

    // instance of our loader and our perceptron
    DataHandler handler;
    
    // we set learning rate = 0.01, so the weights change gently
    //create a vecotr containing 10 specialized neurons
    std::vector<Multi_layer_perceptron> network;
    for (int i =0; i < 10; i++){
        network.push_back(Multi_layer_perceptron(0.005,i));
    }

    std::cout << "loading MNIST dataset.." << std::endl;
    handler.loadTrainingData("/home/hardy/Desktop/Cpp/Machine-Learning-cpp/mnist-cpp/data/raw/train-images.idx3-ubyte", "/home/hardy/Desktop/Cpp/Machine-Learning-cpp/mnist-cpp/data/raw/train-labels.idx1-ubyte");
    handler.loadTestData("/home/hardy/Desktop/Cpp/Machine-Learning-cpp/mnist-cpp/data/raw/t10k-images.idx3-ubyte", "/home/hardy/Desktop/Cpp/Machine-Learning-cpp/mnist-cpp/data/raw/t10k-labels.idx1-ubyte");

    if (handler.training_data.empty() || handler.test_data.empty()){
        std::cout << "error loading dataset, kindly check the paths " << std::endl;
    }

    std::cout << "starting training loop" << std::endl;

    int total_epoch;
    std::cout << "enter epoch : " ;
    std::cin >> total_epoch ;

    for (int epoch = 1; epoch <= total_epoch; ++epoch){
        int correct_guesses = 0;
        for (size_t i=0; i < handler.training_data.size(); ++i){
            Matrix image = handler.training_data[i].image;
            int true_label = handler.training_data[i].label;

            int network_guess = get_network_guess(image, network);

            if (network_guess == true_label){
                correct_guesses++;
            }
            else{
                network[network_guess].force_update_negative(image);
                network[true_label].force_update_positive(image);
            }

        }
        double accuracy = ((double)correct_guesses / handler.training_data.size()) * 100;
        std::cout << "epoch " << epoch << " training accuracy " << accuracy <<"%" << std::endl; 
    }

    std::cout << "starting testing loops (unseen data) " << std::endl;

    int test_correct = 0;
    for (size_t i = 0; i < handler.test_data.size(); ++i){
        Matrix image = handler.test_data[i].image;
        int true_label = handler.test_data[i].label;
        int expected_binary = (true_label == 0) ? 1 : 0;
        if (get_network_guess(image, network) == true_label){
            test_correct ++;
        }
    }
    double test_accuracy = ((double)test_correct / handler.test_data.size()) * 100.0;
    std::cout << "final test accuracy on test data : " << test_accuracy << "%" << std::endl;

}

SOME PROBLEM WITH THE MULTI LAYER PERCEPTRON , WILL FIX IT SOMETIME LATER
NOT MAKING A PLAIN VANILLA NEURAL NETWORK

I ALSO INCLUDED A ASCII ART FILE , JUST WANTED TO 
*/

void plain_vanilla(){

    DataHandler handler;
    std::cout << "loading the dataset MNIST" << std::endl;
    handler.loadTrainingData("/home/hardy/Desktop/Cpp/Machine-Learning-cpp/mnist-cpp/data/raw/train-images.idx3-ubyte", "/home/hardy/Desktop/Cpp/Machine-Learning-cpp/mnist-cpp/data/raw/train-labels.idx1-ubyte");
    handler.loadTestData("/home/hardy/Desktop/Cpp/Machine-Learning-cpp/mnist-cpp/data/raw/t10k-images.idx3-ubyte", "/home/hardy/Desktop/Cpp/Machine-Learning-cpp/mnist-cpp/data/raw/t10k-labels.idx1-ubyte");

    if(handler.training_data.empty() || handler.test_data.empty()){
        std::cout << "error loading dataset" << std::endl;
    }
    
    std::random_device asc;
    std::mt19937 gen(asc());
    std::uniform_int_distribution<int> distrib(1,60000);
    int random_num = distrib(gen);

    Ascii test_var;
    
    Plain_vanilla network;
    int epochs;
    std::cout << "enter epoch : " ;
    std::cin >> epochs;
    double learning_rate = 0.005;
    for (int i =0; i < epochs; i++){
        int correct_guesses = 0;
        test_var.pr_ascii(handler.training_data[random_num].image);
        for (size_t j = 0; j < handler.training_data.size(); j++){
            Matrix image = handler.training_data[j].image;
            int label = handler.training_data[j].label;

            std::vector<double> normalized_input = network.image_loader_and_normalizer(image);
            std::vector<double> z1 = network.z_values(network.weights_trans_1, network.bias_1, normalized_input);
            std::vector<double> a1 = network.activations(z1);
            std::vector<double> z2 = network.z_values(network.weights_trans_2, network.bias_2, a1);
            std::vector<double> a2 = network.activations(z2);
            std::vector<double> output_err = network.output_error(label, a2, a2);
            std::vector<double> hidden_err = network.output_error_hidden(output_err, network.weights_trans_2);
            network.weights_trans_2 = network.weight_updater(network.weights_trans_2, output_err, a1, learning_rate);
            network.bias_2 = network.bias_updater(network.bias_2, output_err, learning_rate);
            network.weights_trans_1 = network.weight_updater(network.weights_trans_1, hidden_err, normalized_input, learning_rate);
            network.bias_1 = network.bias_updater(network.bias_1, hidden_err, learning_rate);
            
        }
        std::cout << "epoch " << i+1 << " completed" << std::endl;
    }   


    
    

}
int main(){
    //perceptron_call();
    //multi_layer_perceptron_call();
    plain_vanilla();
    return 0;
}
