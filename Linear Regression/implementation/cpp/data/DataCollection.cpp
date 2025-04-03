#include "./DataCollection.h"

// Defualt Constructor
DataCollection::DataCollection() : size(0), capacity(0), dataPoints(nullptr) {}

// Construcotr with array of pairs
DataCollection::DataCollection(const std::pair<double, double>* data, int size) 
    : size(size), capacity(size) {
    dataPoints = new std::pair<double, double>[capacity];
    for(int i = 0; i < size; i++) {
        dataPoints[i] = data[i];
    }
};

// Deconstructor
DataCollection::~DataCollection() {
    delete[] dataPoints;
}

// Add a new data point
void DataCollection::addDataPair(double x, double y) {
    if(size == capacity) {
        resize();
    }
    dataPoints[size++] = std::make_pair(x,y);
}

// Retrieve all data points
const std::pair<double, double>* DataCollection::getDataPoints() const {
    std::pair<double, double>* copy = new std::pair<double, double>[size];
    for(int i = 0; i < size; i++) {
        copy[i] = dataPoints[i];
    }

    return copy;
}

// Retrieve a specific data point by index
const std::pair<double, double>& DataCollection::getDataPoint(int index) const {
    if(index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }

    return dataPoints[index];
}

// Get the number of points
int DataCollection::getSize() const {
    return size;
}

// Resize the dynamic array
void DataCollection::resize() {
    capacity = (capacity == 0) ? 1 : capacity*2;
    std::pair<double, double>* newDataPairs = new std::pair<double, double>[capacity];
    for(int i = 0; i < size; i++) {
        newDataPairs[i] = dataPoints[i];
    }

    delete[] dataPoints;
    dataPoints = newDataPairs;
}