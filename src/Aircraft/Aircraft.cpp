#include <Aircraft/Aircraft.hpp>

Aircraft::Aircraft(double initialRollRate, double rollDampingCoeff, double aileronEffectiveness):
    initialRollRate_{initialRollRate},
    rollDampingCoeff_{rollDampingCoeff},
    aileronEffectiveness_{aileronEffectiveness}
{
    rollRate_[0] = initialRollRate_;
};

const double& Aircraft::rollRate(const double& timeDelta, const unsigned int& t){
    auto rollAcc = rollDampingCoeff_*rollRate_[t-1] + aileronEffectiveness_*aileronDeflection_;
    rollRate_[t] = rollRate_[t-1] + rollAcc * timeDelta;
    return rollRate_[t]; 
};

void Aircraft::aileronDeflection(const double& aileronDeflection){
    aileronDeflection_ = aileronDeflection;
};