#pragma once

#include "../data/DataCollection.h"

class MathUtils {
public:
    //Calculate the mean of the x or y values in DataCollection
    static double calculateMean(const DataCollection* data, bool isX);

    //Calcualte the covariance between x and y in the DataCollection
    static double calculateCovariance(const DataCollection* data);

    // Calculate the variance of the x values in DataCollection
    static double calculateVariance(const DataCollection* data);
};