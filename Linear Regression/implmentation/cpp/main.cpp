#include <iostream>
#include <string>
#include "./utils/MathUtils.h"
#include "./data/DataCollection.h"

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

    return 0;
}