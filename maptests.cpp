#include <iostream>
#include <iomanip>
#include <map>
#include <vector>
#include <chrono>
#include <cstdlib>
#include "AVLTree.h"
#include "EmployeeInfo.h"
#include "timer.h"

using namespace std;
using namespace std::chrono;

void testMaximumSizeStdMap();   // test3
void testLoadStdMap();          // test4
void testSearchSpeedStdMap();   // test6

void pauseBetweenTests();

// map is globally created and used!
map<int, EmployeeInfo> stdMap;

int main() {
    cout << "Starting std::map Benchmark Tests..." << endl;
    testMaximumSizeStdMap();
    testLoadStdMap();
    testSearchSpeedStdMap();
    cout << "std::map Benchmark Tests Completed." << endl;

    return 0;
}

void testMaximumSizeStdMap() {
    Timer timer;
    std::cout << "Testing Maximum Size for std::map..." << std::endl;

    std::map<int, EmployeeInfo> stdMap;
    size_t count = 0;
    const size_t maxIterations = 1500000000;

    timer.start();
    while (count < maxIterations) {
        try {
            EmployeeInfo empl;
            empl.sin = static_cast<int>(count); // Use count as the SIN
            empl.age = 30;
            empl.salary = 50000;
            empl.emplNumber = static_cast<int>(count);
            stdMap[count] = empl; // Inserting by count as key
            ++count;
        }
        catch (const std::bad_alloc& e) {
            std::cout << "Maximum elements before std::bad_alloc: " << count << std::endl;
            break; // Break on memory allocation failure
        }
        catch (const std::exception& e) {
            std::cout << "Caught exception: " << e.what() << " after inserting " << count << " elements.\n";
        }
    }
    timer.stop();

    stdMap.clear(); // Clearing the std::map after finishing the test for maximum size
    std::cout << "Test completed with " << count << " elements in std::map." << std::endl;

    double timeForMaximumSize = timer.currtime();
    std::cout << "Time to attempt loading " << maxIterations << " elements on the std::map: " 
              << std::fixed << std::setprecision(6) << timeForMaximumSize << " seconds" << std::endl;
}

void testLoadStdMap() {
    std::cout << "Testing Load..." << std::endl;
    const size_t numOfInsertions = 10000000; 
    Timer timer;
    timer.start();
    for (size_t i = 0; i < numOfInsertions; ++i) {
        EmployeeInfo empl;
        empl.sin = static_cast<int>(i); // Use count as the SIN
        empl.age = 30;
        empl.salary = 50000;
        empl.emplNumber = static_cast<int>(i);
        stdMap[i] = empl; // Inserting by count as key
    }
    timer.stop();
    std::cout << "Time taken to load " << numOfInsertions << " elements into std::map: " 
              << std::fixed << std::setprecision(6) << timer.currtime() << " seconds." << std::endl;
    // Not clearing the map and using the same map for the next test to find Speed of search.
}

void testSearchSpeedStdMap(){
    std::cout << "Testing Speed of search Size..." << std::endl;
    Timer timer;
    size_t minKey = 0; // Assuming keys start at 0 for simplicity
    size_t maxKey = stdMap.rbegin()->first; // Last element's key

    timer.start();
    auto minIt = stdMap.find(minKey);
    timer.stop();
    std::cout << "Time to find minimum key in std::map: " 
              << std::fixed << std::setprecision(8) << timer.currtime() << " seconds." << std::endl;

    timer.reset();

    timer.start();
    auto maxIt = stdMap.find(maxKey);
    timer.stop();
    std::cout << "Time to find maximum key in std::map: " 
              << std::fixed << std::setprecision(8) << timer.currtime() << " seconds." << std::endl;

    std::cout << "Minimum node SIN: " << minIt->second.sin << std::endl;
    std::cout << "Maximum node SIN: " << maxIt->second.sin << std::endl;
}


void pauseBetweenTests() {
    cout << "Press enter to continue..." << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}