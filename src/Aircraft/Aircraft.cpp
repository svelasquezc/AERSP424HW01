#include <Aircraft/Aircraft.hpp>

Aircraft::Aircraft(double initialRollRate, double rollDampingCoeff, double aileronEffectiveness):
    initialRollRate_{initialRollRate},
    rollDampingCoeff_{rollDampingCoeff},
    aileronEffectiveness_{aileronEffectiveness}
{
    rollRate_[t] = initialRollRate_;
};

const double& Aircraft::rollRate(const double& timeDelta){
    auto rollAcc = rollDampingCoeff_*rollRate_[t] + aileronEffectiveness_*aileronDeflection_;
    rollRate_[t+1] = rollRate_[t] + rollAcc * timeDelta;
    return rollRate_[t+1]; 
};

void Aircraft::aileronDeflection(const double& aileronDeflection){
    aileronDeflection_ = aileronDeflection;
};