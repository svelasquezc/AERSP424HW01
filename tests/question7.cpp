#include<cassert>
#include<limits>
#include<iostream>
#include<cmath>

#include <Classifier/Vector.hpp>
#include <Classifier/Neuron.hpp>

int main(){
    Classifier::Vector w {0.0001,0.0001,0.0001};
    Classifier::Vector x {124,31.89,20.945};
    double alpha = 0.001;
    auto z = Classifier::dot(w,x);

    auto dw = Classifier::gradientWeights(w,x,1);
    Classifier::updateWeights(w,alpha,x,1);

    std::cout << "weights gradient: " << dw.print() << std::endl;
    std::cout << "new weights: " << w.print() << std::endl;

    assert(true);
    return 0;
}