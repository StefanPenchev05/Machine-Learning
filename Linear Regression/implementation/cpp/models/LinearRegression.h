#pragma once

#include <iostream>

#include "../data/DataCollection.h"
#include "../utils/MathUtils.h"

class LinearRegression {
public:
    // Constructor
    LinearRegression();

    // Method to fit the model to the data
    void fit(const DataCollection* data);

    // Train the model using gradient descent
    void train(const DataCollection* data, double learningRate, int iterations);

    // Method to predict the y value for a given x
    double predict(double x) const;

    // Getters for slope and intercept
    double getSlope() const;
    double getIntercept() const;

private:
    double slope;     // The slope of the best-fitting line
    double intercept; // The intercept of the best-fitting line
};