#include <iostream>
#include "/home/hardy/Desktop/Cpp/Machine-Learning-cpp/mnist-cpp/include/ascii.hpp"

void Ascii::pr_ascii(const Matrix& image){
    for (int r=0; r < 28; r++){
        for (int c= 0; c < 28 ; c++){
            double pixel_value = image.data[r*28 + c];
            if(pixel_value > 0.5) {
                std::cout << "##";
            } else if(pixel_value > 0.1) {
                std::cout << "..";
            } else {
                std::cout << "  ";
            }
        }
        std::cout << std::endl;
    }
}

