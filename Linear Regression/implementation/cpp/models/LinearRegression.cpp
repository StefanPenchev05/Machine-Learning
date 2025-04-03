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