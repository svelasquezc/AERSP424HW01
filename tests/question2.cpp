#include<iostream>
#include <cassert>

#include <Aircraft/Aircraft.hpp>
#include <Aircraft/AutoPilot.hpp>


int main(){

    double timeDelta {0.01};
    unsigned int t = 1;
    double time = timeDelta;

    Aircraft aircraft{1 /*rad/s*/, -0.3, 0.2};
    AutoPilot constantAutoPilot {2.5, 0, aircraft}; 
    aircraft.aileronDeflection(1);
    while (time <= 5){
        constantAutoPilot.constantFeedbackControl(t);
        std::cout << "roll rate "<< aircraft.rollRate(timeDelta,t) << "at time " << time <<std::endl;
        time += timeDelta;
        ++t;
    } 
    assert(true);
    return 0;
}