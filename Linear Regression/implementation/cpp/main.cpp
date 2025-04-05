#include <iostream>
#include <string>

#include "./utils/MathUtils.h"
#include "./data/DataCollection.h"
#include "./models/LinearRegression.h"

#include "./data/DataCollectionTest.h"
#include "./utils/MathUtilsTest.h"

// Main function
int main(int argc, char* argv[]) {
    // Run tests if "--run-tests" argument is provided
    if (argc > 1 && std::string(argv[1]) == "--run-tests") {
        DataCollectionTest::runAllTests();
        MathUtilsTest::runAllTests();
        return 0;
    }

    // Dataset: Pairs of (x, y) values
    std::pair<double, double> data[] = {
        {10.0, 25.0}, {20.0, 50.5}, {30.0, 75.2}, {40.0, 100.1}, {50.0, 125.3},
        {60.0, 150.7}, {70.0, 175.6}, {80.0, 200.2}, {90.0, 225.8}, {100.0, 250.0},
        {110.0, 275.4}, {120.0, 300.1}, {130.0, 325.6}, {140.0, 350.3}, {150.0, 375.9},
        {160.0, 400.5}, {170.0, 425.2}, {180.0, 450.8}, {190.0, 475.6}, {200.0, 500.0},
        {210.0, 525.3}, {220.0, 550.7}, {230.0, 575.1}, {240.0, 600.4}, {250.0, 625.8},
        {260.0, 650.2}, {270.0, 675.5}, {280.0, 700.0}, {290.0, 725.3}, {300.0, 750.6},
        {310.0, 775.9}, {320.0, 800.2}, {330.0, 825.5}, {340.0, 850.8}, {350.0, 875.1},
        {360.0, 900.4}, {370.0, 925.7}, {380.0, 950.0}, {390.0, 975.3}, {400.0, 1000.6},
        {410.0, 1025.9}, {420.0, 1050.2}, {430.0, 1075.5}, {440.0, 1100.8}, {450.0, 1125.1},
        {460.0, 1150.4}, {470.0, 1175.7}, {480.0, 1200.0}, {490.0, 1225.3}, {500.0, 1250.6}
    };

    // Create a DataCollection object for the dataset
    DataCollection* collection = new DataCollection(data, 50);

    // Step 1: Fit the model using the closed-form solution (before training)
    LinearRegression modelBeforeTraining;
    modelBeforeTraining.fit(collection);

    // Output the equation of the line before training
    std::cout << "Equation of the line before training: y = " 
              << modelBeforeTraining.getSlope() << "x + " 
              << modelBeforeTraining.getIntercept() << std::endl;

    // Predict a value using the model before training
    double xBefore = 1200.43;
    double predictedYBefore = modelBeforeTraining.predict(xBefore);
    std::cout << "Predicted value for x = " << xBefore 
              << " (before training): y = " << predictedYBefore << std::endl;

    // Step 2: Train the model using gradient descent
    LinearRegression modelAfterTraining;
    modelAfterTraining.train(collection, 0.00001, 10000);

    // Output the equation of the line after training
    std::cout << "Equation of the line after training: y = " 
              << modelAfterTraining.getSlope() << "x + " 
              << modelAfterTraining.getIntercept() << std::endl;

    // Predict a value using the model after training
    double xAfter = 1200.43;
    double predictedYAfter = modelAfterTraining.predict(xAfter);
    std::cout << "Predicted value for x = " << xAfter 
              << " (after training): y = " << predictedYAfter << std::endl;

    // Clean up dynamically allocated memory
    delete collection;

    return 0;
}