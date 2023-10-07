#include<iostream>
#include <cassert>
#include <Aircraft/Aircraft.hpp>


int main(){
    Aircraft aircraft{1 /*rad/s*/, -0.3, 0.2};
    double timeDelta {0.01};
    unsigned int t = 1;
    double time = timeDelta;
    aircraft.aileronDeflection(1);
    while (time <= 5){
        if (time > 2){
            aircraft.aileronDeflection(0);
        }

        std::cout << "roll rate "<< aircraft.rollRate(timeDelta,t) << "at time " << time <<std::endl;
        time += timeDelta;
        ++t;
    } 
    assert(true);
    return 0;
}