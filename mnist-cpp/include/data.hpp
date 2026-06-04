#ifndef DATA_HPP
#define DATA_HPP

#include <vector>
#include <random>
#include <cmath>
#include <stdexcept>

struct Matrix{
    int rows;
    int cols;
    std::vector<double> data;

    //default
    Matrix(){
        rows = 0;
        cols = 0;
    }

    // Main constructor to allocate space and optionally random-initialize weights
    
    Matrix(int r, int c, bool init_random = false){
        rows = r;
        cols = c;
        data.resize(r*c, 0.0); // allocate all elements in a flat continous line
        if (init_random){
            // xavier initialization
            std::default_random_engine generator(std::random_device{}());
            double limit = std::sqrt(2.0/ (rows + cols));
            std::normal_distribution<double> distribution(0.0, limit);

            for(int i=0; i < rows * cols ; ++i){
                data[i] = distribution(generator);
            }
        }                              
    }

    // simple 2d indexing mapping helper : row r, col c
    double at(int r, int c) const {
        return data[r * cols + c];
    }
    //version that allows changing values at a row and cols
    double &at(int r,int c) {
        return data[r * cols + c];
    }
};

    //bundles a single MNIST image with its label
    struct MNISTSample{
        Matrix image;
        int label;
    };

    // Matrix multiplication mismatch function
    //
    inline Matrix multiply(const Matrix& A, const Matrix& B){
        if(A.cols != B.rows){
            throw std::runtime_error("Matrix dimension mismatch");
        }

        Matrix C(A.rows, B.cols);// output matrix

        for(int r =0; r < A.rows; r++){
            for (int c= 0; c < C.cols; c++){
                double sum = 0.0;
                for (int k=0; k < A.cols; ++k){
                    sum += A.at(r,k) * B.at(k,c);
                }
                C.at(r,c) = sum;
            }
        }
        return C ;
    }
#endif
