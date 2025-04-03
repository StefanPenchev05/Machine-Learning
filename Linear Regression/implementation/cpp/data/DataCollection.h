#pragma once
#include <utility>
#include <stdexcept>

class DataCollection {
public:
    // Constructor can accepts an array of pairs - cordinates
    DataCollection(const std::pair<double, double>* data, int size);

    // Default Constructor
    DataCollection();

    // Deconstructor
    ~DataCollection();

    // Method for adding new pair
    void addDataPair(double x, double y);

    // Method to retrive all data points
    const std::pair<double, double>* getDataPoints() const;

    // Method to retrieve a specific data point by index
    const std::pair<double, double>& getDataPoint(int index) const;

    // Method to get the number of points
    int getSize() const;

private:
    // Dynamic array to store data points
    std::pair<double, double>* dataPoints;

    // Current size of the array
    int size;

    // Capacity of the array
    int capacity;

    // Method to resize the array when needed
    void resize();
};