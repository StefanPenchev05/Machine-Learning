#include "LinearRegression.h"

// Constructor
LinearRegression::LinearRegression() : slope(0.0), intercept(0.0) {}

// Fit the model to the data
void LinearRegression::fit(const DataCollection* data) {
    // Calculate the slope (m) and intercept (b) using MathUtils
    double covariance = MathUtils::calculateCovariance(data);
    double varianceX = MathUtils::calculateVariance(data);
    double meanX = MathUtils::calculateMean(data, true);
    double meanY = MathUtils::calculateMean(data, false);

    slope = covariance / varianceX;
    intercept = meanY - slope * meanX;
}

// Train the model using gradient descent
void LinearRegression::train(const DataCollection* data, double learningRate, int iterations) {
    int size = data->getSize();
    if(size == 0) {
        throw std::invalid_argument("Cannot train on an empty dataset");
    }

    for(int iter = 0; iter < iterations; iter++) {
        double gradientSlope = 0.0;
        double gradientIntercept = 0.0;

        // Gradient Calculations
        for (int i = 0; i < size; i++) {
            double x = data->getDataPoint(i).first;
            double y = data->getDataPoint(i).second;
            double prediction = slope * x + intercept;

            // Partial Der
            gradientSlope += (prediction - y) * x;
            gradientIntercept += (prediction - y);
        }

        gradientSlope /= size;
        gradientIntercept /= size;

        // Update parameters
        slope -= learningRate * gradientSlope;
        intercept -= learningRate * gradientIntercept;

        // Lets print the progress
        if(iter % 100 == 0) {
            std::cout << "Iteration " << iter << ": Cost = "
                      << (gradientSlope * gradientSlope + gradientIntercept * gradientIntercept) / 2
                      << ", Slope = " << slope << ", Intercept = " << intercept << std::endl;
        }
    }
}

// Predict the y value for a given x
double LinearRegression::predict(double x) const {
    return slope * x + intercept;
}

// Getters for slope and intercept
double LinearRegression::getSlope() const {
    return slope;
}

double LinearRegression::getIntercept() const {
    return intercept;
}