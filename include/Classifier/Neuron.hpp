#ifndef NEURON_HPP
#define NEURON_HPP
#include <cmath>

#include "Vector.hpp"

namespace Classifier{

    double sigmoid(const double& z){
        return 1.0/(1.0 + exp(-z));
    }

    double gradientSigmoid(const double& z){
        return sigmoid(z)*(1-sigmoid(z));
    }

    double gradientCost(const double& predictedOutput, const double& expectedOutput){
        return 2*(predictedOutput - expectedOutput);
    }

    Vector gradientWeights(const Vector& weights, const Vector& input, const double& expectedOutput){
        auto z = dot(weights, input);
        auto predictedOutput = sigmoid(z);
        return gradientCost(predictedOutput, expectedOutput)*gradientSigmoid(z)*input;
    }

    void updateWeights(Vector& weights, const double& alpha, const Vector& input, const double& expectedOutput){
        weights = weights - alpha*gradientWeights(weights, input, expectedOutput);
    }
}
#endif /* NEURON_HPP */