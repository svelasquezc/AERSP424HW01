#include<cassert>
#include<limits>
#include<iostream>

#include <Classifier/Vector.hpp>

int main(){
    Classifier::Vector w = {0.0001,0.0001,0.0001};
    Classifier::Vector x = {124,31.89,20.945};
    auto z = Classifier::dot(w,x);

    std::cout << z;

    assert(z-0.0176835 <= (z-0.0176835)*std::numeric_limits<decltype(z-0.0176835)>::lowest());
    return 0;
}