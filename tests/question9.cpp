#include<cassert>
#include<limits>
#include<iostream>
#include<cmath>

#include <Classifier/Neuron.hpp>

int main(){
    Classifier::Neuron neuron{};
    using TrainingDataType = Classifier::Neuron::TrainingDataType;
    using InputType =  Classifier::Neuron::InputType;

    std::vector<TrainingDataType> trainingData = {
        {{124,31.89,20.945},1},
        {{74,51.08,9.170},0},
        {{103,34.67,8.3},1},
        {{77,52.0,9.4},0},
        {{104,35.63,13},1},
        {{92,56,12.5},0},
        {{130,31.29,17.637},1},
        {{73,52,9.6},0}
        };

    neuron.train(trainingData);

    std::vector<InputType> testData = {
        {87,38.67,6},
        {79,52.08,8},
        {92,33.75,7.804},
        {91,59.25,16}
        };

    for (const auto& test: testData){
        std::cout << "Prediction for: "<< test.print() << " is " << neuron.predict(test) << std::endl;
    }

    assert(true);
    return 0;
}