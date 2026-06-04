#include <iostream>
#include "/home/hardy/Desktop/Cpp/Machine-Learning-cpp/mnist-cpp/include/data_handler.hpp"

int main(){

    //creating an instance of our data loader class
    DataHandler handler; 

    std::cout << "OPENING MNIST DATASET files.. " << std::endl;

    //load the training dataset
    handler.loadTrainingData("/home/hardy/Desktop/Cpp/Machine-Learning-cpp/mnist-cpp/data/raw/train-images.idx3-ubyte", "/home/hardy/Desktop/Cpp/Machine-Learning-cpp/mnist-cpp/data/raw/train-labels.idx1-ubyte");

        if (handler.training_data.empty()){
            std::cout << " failed to load data" << std::endl;
            return 1;
        };
    int sample_num;
    std::cout << "enter sample index :";
    std::cin >> sample_num;
    MNISTSample some_sample = handler.training_data[sample_num];
    std::cout << "ASCII for sample " << sample_num << std::endl;
    for(int r=0; r < 28; r++){
        for (int c = 0 ; c < 28; c++){
            double pixel_value = some_sample.image.data[r*28 + c];

            if (pixel_value > 0.5){
                std::cout << "##" ;
            } else if(pixel_value > 0.1) {
                std::cout << ".." ;
            }else{
                std::cout << "  ";
            }

        }
        std::cout << std::endl; // new line after finishing a row
    }
    return 0;
}
