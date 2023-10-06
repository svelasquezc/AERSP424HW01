#ifndef AIRCRAFT_HPP
#define AIRCRAFT_HPP
#include <map>

class Aircraft{
private:
    double initialRollRate_;
    double rollDampingCoeff_;
    double aileronEffectiveness_;
    double aileronDeflection_;
    std::map<unsigned int, double> rollRate_;
    unsigned int t = 0;

    friend class AutoPilot;
public:
    Aircraft(double initialRollRate, double rollDampingCoeff, double aileronEffectiveness);
    const double& rollRate(const double& timeDelta);
    void aileronDeflection(const double& aileronDeflection);

};

#endif AIRCRAFT_HPP