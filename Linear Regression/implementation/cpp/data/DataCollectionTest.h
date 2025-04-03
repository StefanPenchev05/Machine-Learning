#pragma once

#include<iostream>
#include<cassert>
#include "./DataCollection.h"

namespace DataCollectionTest {
    void testDefaultConstructor() {
        DataCollection collection;
        assert(collection.getSize() == 0);
        std::cout << "Default constructor test passed.\n";
    }

    void testConstructorWithArray() {
        std::pair<double, double> data[] = {
            {1.0, 2.0},
            {2.0, 4.0},
            {3.0, 6.0}
        };
        DataCollection collection(data, 3);
        assert(collection.getSize() == 3);
        assert(collection.getDataPoint(0) == std::make_pair(1.0, 2.0));
        assert(collection.getDataPoint(1) == std::make_pair(2.0, 4.0));
        assert(collection.getDataPoint(2) == std::make_pair(3.0, 6.0));
        std::cout << "Constructor with array test passed.\n";
    }

    void testAddDataPair() {
        DataCollection collection;
        collection.addDataPair(1.0, 2.0);
        collection.addDataPair(2.0, 4.0);
        collection.addDataPair(3.0, 6.0);
        assert(collection.getSize() == 3);
        assert(collection.getDataPoint(0) == std::make_pair(1.0, 2.0));
        assert(collection.getDataPoint(1) == std::make_pair(2.0, 4.0));
        assert(collection.getDataPoint(2) == std::make_pair(3.0, 6.0));
        std::cout << "Add data pair test passed.\n";
    }

    void testResize() {
        DataCollection collection;
        for (int i = 0; i < 100; ++i) {
            collection.addDataPair(i, i * 2);
        }
        assert(collection.getSize() == 100);
        for (int i = 0; i < 100; ++i) {
            assert(collection.getDataPoint(i) == std::make_pair((double)i, (double)(i * 2)));
        }
        std::cout << "Resize test passed.\n";
    }

    void testOutOfRange() {
        try {
            DataCollection collection;
            collection.addDataPair(1.0, 2.0);
            collection.getDataPoint(1); // This should throw an exception
            assert(false); // If no exception is thrown, fail the test
        } catch (const std::out_of_range& e) {
            std::cout << "Out of range test passed.\n";
        }
    }

    void runAllTests() {
        testDefaultConstructor();
        testConstructorWithArray();
        testAddDataPair();
        testResize();
        testOutOfRange();
        std::cout << "All DataCollection tests passed.\n";
    }
}