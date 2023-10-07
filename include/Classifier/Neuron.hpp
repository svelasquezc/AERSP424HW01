#ifndef NEURON_HPP
#define NEURON_HPP
#include <cmath>
#include <tuple>
#include<string>

#include "Vector.hpp"

namespace Classifier{

    double sigmoid(const double& z){
        return 1.0/(1.0 + exp(-z));
    }

    double gradientSigmoid(const double& z){
        return sigmoid(z)*(1-sigmoid(z));
    }

    double gradientCost(const double& predictedOutput, const double& expectedOutput){
        return 2*(predictedOutput - expectedOutput);
    }

    Vector gradientWeights(const Vector& weights, const Vector& input, const double& expectedOutput){
        auto z = dot(weights, input);
        auto predictedOutput = sigmoid(z);
        return gradientCost(predictedOutput, expectedOutput)*gradientSigmoid(z)*input;
    }

    void updateWeights(Vector& weights, const double& alpha, const Vector& input, const double& expectedOutput){
        weights = weights - alpha*gradientWeights(weights, input, expectedOutput);
    }

    class Neuron {
        Vector weights{0.0001, 0.0001, 0.0001};
        double alpha = 0.001;
        constexpr static double iterations = 200;  
        
    public:
        using InputType = Vector;
        using OutputType = double;
        using TrainingDataType = std::pair<InputType,OutputType>;

        Neuron() = default;

        void train(const std::vector<TrainingDataType>& trainingData){
            for (unsigned int i =0; i<iterations; ++i){
                for (const auto& trainingPair : trainingData){
                    auto inputData = std::get<InputType>(trainingPair);
                    auto expectedOutcome = std::get<OutputType>(trainingPair);

                    updateWeights(weights, alpha, inputData, expectedOutcome);
                }
            }
        }

        std::string predict(const InputType& input){
            auto z = dot(weights, input);
            auto predictedOutput = sigmoid(z);

            return predictedOutput > 0.5 ? "Jet" : "Turboprop";
        } 

        auto printWeights() const {
            return weights.print();
        }

    };

}
#endif /* NEURON_HPP */