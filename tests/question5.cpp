#include<cassert>
#include<limits>
#include<iostream>
#include<cmath>

#include <Classifier/Vector.hpp>
#include <Classifier/Neuron.hpp>

int main(){
    Classifier::Vector w {0.0001,0.0001,0.0001};
    Classifier::Vector x {124,31.89,20.945};
    auto z = Classifier::dot(w,x);

    auto sigmoid = Classifier::sigmoid(z);
    auto gradient = Classifier::gradientSigmoid(z);

    std::cout << "sigmoid: " << sigmoid << std::endl;
    std::cout << "sigmoid gradient: " << gradient << std::endl;

    auto zero1 = std::abs(sigmoid-0.504421);
    auto zero2 = std::abs(gradient - 0.24998);

    assert(zero1 <= std::max(sigmoid, 0.504421)*std::numeric_limits<decltype(zero1)>::epsilon());
    assert(zero2 <= std::max(gradient, 0.24998)*std::numeric_limits<decltype(zero2)>::epsilon());
    return 0;
}