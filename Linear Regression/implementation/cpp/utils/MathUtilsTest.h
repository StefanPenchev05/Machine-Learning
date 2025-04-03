#pragma once

#include <iostream>
#include <cassert>
#include "../data/DataCollection.h"
#include "MathUtils.h"

namespace MathUtilsTest {

    void testCalculateMean() {
        std::pair<double, double> data[] = {
            {1.0, 2.0},
            {2.0, 4.0},
            {3.0, 6.0}
        };
        DataCollection* collection = new  DataCollection(data, 3);

        double meanX = MathUtils::calculateMean(collection, true);
        double meanY = MathUtils::calculateMean(collection, false);

        assert(meanX == 2);
        assert(meanY == 4);

        std::cout << "MathUtils::calculateMean test passed.\n";
    }

    void testCalculateCovariance() {
        std::pair<double, double> data[] = {
            {1.0, 2.0},
            {2.0, 4.0},
            {3.0, 6.0}
        };
        DataCollection* collection = new  DataCollection(data, 3);

        double covariance = MathUtils::calculateCovariance(collection);

        assert(covariance == 2.0);

        std::cout << "MathUtils::calculateCovariance test passed.\n";
    }

    void testCalculateVariance() {
        std::pair<double, double> data[] = {
            {1.0, 2.0},
            {2.0, 4.0},
            {3.0, 6.0}
        };
        DataCollection* collection = new  DataCollection(data, 3);

        double varianceX = MathUtils::calculateVariance(collection);

        assert(varianceX == 2.0 / 3.0);

        std::cout << "MathUtils::calculateVariance test passed.\n";
    }

    void runAllTests() {
        testCalculateMean();
        testCalculateCovariance();
        testCalculateVariance();
        std::cout << "All MathUtils tests passed.\n";
    }
}