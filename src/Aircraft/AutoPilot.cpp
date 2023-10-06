#include <Aircraft/AutoPilot.hpp>

AutoPilot::AutoPilot(double initialControlGain, double adaptiveControlRate, Aircraft& aircraft):
    initialControlGain_{initialControlGain},
    adaptiveControlRate_{adaptiveControlRate},
    aircraft_{aircraft}
    {
        controlGain_[0] = initialControlGain_;
    }

void AutoPilot::constantFeedbackControl(const unsigned int& t){
    aircraft_.aileronDeflection_ = -initialControlGain_ *aircraft_.rollRate_[t];
};

void AutoPilot::adaptiveFeedbackControl(const unsigned int& t){
    aircraft_.aileronDeflection_ = -controlGain_[t-1] *aircraft_.rollRate_[t-1];
    controlGain_[t] = controlGain_[t-1] + adaptiveControlRate_ * (aircraft_.rollRate_[t]*aircraft_.rollRate_[t]);
};