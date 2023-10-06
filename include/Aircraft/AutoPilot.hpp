#ifndef AUTOPILOT_HPP
#define AUTOPILOT_HPP
#include<map>

#include "Aircraft.hpp"


class AutoPilot {
private:
    double initialControlGain_;
    double adaptiveControlRate_;
    std::map<unsigned int, double> controlGain_;
    Aircraft& aircraft_;
public:
    AutoPilot(double initialControlGain, double adaptiveControlRate, Aircraft& aircraft);
    void constantFeedbackControl(const unsigned int& t);
    void adaptiveFeedbackControl(const unsigned int& t);
};

#endif /* AUTOPILOT_HPP */