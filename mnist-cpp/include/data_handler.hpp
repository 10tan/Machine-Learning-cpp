// classes responsible for handling data and data splittling

#ifndef DATA_HANDLER_HPP
#define DATA_HANDLER_HPP

#include "data.hpp"
#include <string>
#include <vector>
#include <cstdint>
class DataHandler {
    
    private:
        // helper function to handle big endian binary files
        uint32_t flipBytes(uint32_t n);

    public:
        // Arrays to store our split datasets
        std::vector<MNISTSample> training_data; 
        std::vector<MNISTSample> test_data;

        // function to read the raw files
        void loadTrainingData(const std::string& image_path, const std::string& label_path);
        void loadTestData(const std::string& image_path, const std::string& label_path);
};

#endif
