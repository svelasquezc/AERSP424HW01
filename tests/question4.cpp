#include<cassert>
#include<limits>
#include<iostream>
#include<cmath>

#include <Classifier/Vector.hpp>

int main(){
    Classifier::Vector w = {0.0001,0.0001,0.0001};
    Classifier::Vector x = {124,31.89,20.945};
    auto z = Classifier::dot(w,x);

    std::cout << "Dot product: "<< z <<std::endl;

    auto zero1 = std::abs(z-0.0176835);
    assert(zero1 <= std::max(z, 0.0176835)*std::numeric_limits<decltype(zero1)>::epsilon());
    return 0;
}