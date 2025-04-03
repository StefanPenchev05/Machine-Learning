#include <iostream>
#include <string>
#include "./utils/MathUtils.h"
#include "./data/DataCollection.h"
#include "./models/LinearRegression.h"

#include "./data/DataCollectionTest.h"
#include "./utils/MathUtilsTest.h"

// Create the mathematical algorithm for calulating the best fitting line in the system
// Output the result(the formula for the line)

int main(int argc, char* argv[]) {
    // Run tests for DataCollection
    if(argc > 1 && std::string(argv[1]) == "--run-tests") {
        DataCollectionTest::runAllTests();
        MathUtilsTest::runAllTests();
    }

    // Create a DataCollection object with some data points
    std::pair<double, double> data[] = {
        {1.0, 2.0},
        {2.0, 4.0},
        {3.0, 6.0},
        {4.0, 8.0}
    };
    DataCollection* collection = new DataCollection(data, 4);

    // Create a LinearRegression object and fit the model
    LinearRegression model;
    model.fit(collection);

    // Output the equation of the best-fitting line
    std::cout << "Equation of the line: y = " << model.getSlope() << "x + " << model.getIntercept() << std::endl;

    // Predict a value
    double x = 5.0;
    double predictedY = model.predict(x);
    std::cout << "Predicted value for x = " << x << ": y = " << predictedY << std::endl;

    return 0;
}