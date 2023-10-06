#ifndef AUTOPILOT_HPP
#define AUTOPILOT_HPP

#include "Aircraft.hpp"

class AutoPilot {
private:
    double controlGain_;
public:
    void feedbackControl(Aircraft& aircraft);
    void adaptiveFeedbackControl(Aircraft& aircraft);
};

#endif AUTOPILOT_HPP