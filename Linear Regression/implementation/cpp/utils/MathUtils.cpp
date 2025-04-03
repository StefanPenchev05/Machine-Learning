#include "./MathUtils.h"
#include <stdexcept>

//Calculate the mean of the x or y values in DataCollection
double MathUtils::calculateMean(const DataCollection* data, bool isX) {
    int size = data->getSize();
    if(size == 0) {
        throw std::invalid_argument("Cannot calculate mean value of an empty dataset");
    }

    double sum = 0;
    for(int i = 0; i < size; i++) {
        if(isX) {
            sum += data->getDataPoint(i).first; // Sum of x values 
        } else {
            sum += data->getDataPoint(i).second; // Sum of y values
        }
    }

    return sum / size;
}

//Calcualte the covariance between x and y in the DataCollection
double MathUtils::calculateCovariance(const DataCollection* data) {
    int size = data->getSize();
    if(size == 0) {
        throw std::invalid_argument("Cannot calculate covarience of an empty dataset");
    }

    double meanX = calculateMean(data, true);
    double meanY = calculateMean(data, false);

    double covarience = 0.0;
    for(int i = 0; i < size; ++i) {
        double x = data->getDataPoint(i).first;
        double y = data->getDataPoint(i).second;
        covarience += (x - meanX) * (y - meanY);
    }

    return covarience / (size - 1);
}

// Calculate the variance of the x values in DataCollection
double MathUtils::calculateVariance(const DataCollection* data) {
    int size = data->getSize();
    if(size == 0) {
        throw std::invalid_argument("Cannot calculate covarience of an empty dataset");
    }

    double meanX = calculateMean(data, true);

    double variance = 0.0;
    for(int i = 0; i < size; ++i) {
        double x = data->getDataPoint(i).first;
        variance += (x - meanX) * (x - meanX);
    }

    return variance / (size - 1);
}
