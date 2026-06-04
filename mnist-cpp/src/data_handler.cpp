#include "/home/hardy/Desktop/Cpp/Machine-Learning-cpp/mnist-cpp/include/data_handler.hpp"
#include <fstream>
#include <iostream>
#include <cstdint>


// the MNIST binary dataset stores numbers backwards, (big endian)

uint32_t DataHandler::flipBytes(uint32_t n) {
    
    uint32_t b0 = (n & 0x000000ff) << 24;
    uint32_t b1 = (n & 0x0000ff00) << 8;
    uint32_t b2 = (n & 0x00ff0000) >> 8 ;
    uint32_t b3 = (n & 0xff000000) >> 24; 
    return (b0 | b1 | b2 | b3);
}

void DataHandler::loadTrainingData(const std::string& image_path, const std::string& label_path) {
    
    // opening the image file and label file in binary mode

    std::ifstream image_file(image_path, std::ios::binary);
    std::ifstream label_file(label_path, std::ios::binary);

    if (!image_file.is_open() || !label_file.is_open()) {
        std::cout << "Error : cound not open training files! " << std::endl;
        return;
    }

    uint32_t magic_number = 0;
    uint32_t num_images = 0;
    uint32_t rows = 0;
    uint32_t cols = 0;

    image_file.read((char*)&magic_number, 4);
    image_file.read((char*)&num_images, 4);
    num_images = flipBytes(num_images);
    image_file.read((char*)&rows, 4);
    rows = flipBytes(rows);
    image_file.read((char*)&cols, 4);
    cols = flipBytes(cols);

    //skip the label file header, not required its magic number or cound
    label_file.seekg(0);

    int total_pixels = rows * cols ;
    
    for (uint32_t i =0; i < num_images; i++){
    
        MNISTSample sample;
        sample.image = Matrix(total_pixels, 1);// creates a totalpixel * 1 col matrix
        
        //read all pixels for this single image
        for (int p =0; p < total_pixels; p++){
            unsigned char pixel_byte = 0;
            image_file.read((char*)&pixel_byte, 1);

            //normalize the pixel value
            sample.image.data[p] = (double)pixel_byte / 255.0;
        }

        //read the matching 1 byte label 0 to 9 
        unsigned char label_byte = 0;
        label_file.read((char*)&label_byte, 1);
        sample.label = (int)label_byte;

        // save the sample to our training array
        training_data.push_back(sample);

    }
    std::cout << "successfully loaded " << training_data.size() << " training samples !" << std::endl;
    image_file.close();
    label_file.close();
}

void DataHandler::loadTestData(const std::string& image_path, const std::string& label_path) {
    
    std::ifstream image_file(image_path, std::ios::binary);
    std::ifstream label_file(label_path, std::ios::binary);

    if(!image_file.is_open() || ! label_file.is_open() ){
        std::cout << " Error in opening the test files" << std::endl;
        return;
    }

    uint32_t magic_number = 0;
    uint32_t num_images = 0;
    uint32_t rows = 0;
    uint32_t cols = 0;

    image_file.read((char*)&magic_number, 4);
    image_file.read((char*)&num_images, 4);
    num_images = flipBytes(num_images);
    image_file.read((char*)&rows, 4);
    rows = flipBytes(rows);
    image_file.read((char*)&cols, 4);
    cols = flipBytes(cols);

    label_file.seekg(0);
    int total_pixels = rows * cols;
    for (uint32_t i=0; i < num_images; i ++){
        MNISTSample sample;
        sample.image = Matrix(total_pixels, 1); 

        for (int p =0; p < total_pixels; p++){
            unsigned char pixel_byte = 0;
            image_file.read((char*)&pixel_byte, 1);

            sample.image.data[p] = (double)pixel_byte / 255.0 ;
        }

        unsigned char label_byte = 0;
        label_file.read((char*)&label_byte, 1);
        sample.label = (int)label_byte;

        test_data.push_back(sample);
    }

    std::cout << "success for loading the test data " << test_data.size() << " Test samples" << std::endl;
    image_file.close();
    label_file.close();


}
