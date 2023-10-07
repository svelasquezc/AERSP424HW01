#include<cassert>
#include<limits>
#include<iostream>
#include<cmath>

#include <Classifier/Neuron.hpp>

int main(){
    double expectedOutput = 1;
    double predictedOutput = 0.504421;

    auto cost = Classifier::gradientCost(predictedOutput, expectedOutput);

    std::cout << "Gradient cost: "<< cost <<std::endl;

    auto zero1 = std::abs(cost+0.991158);
    assert(zero1 <= std::max(std::abs(cost), std::abs(-0.991158))*std::numeric_limits<decltype(zero1)>::epsilon());
    return 0;
}