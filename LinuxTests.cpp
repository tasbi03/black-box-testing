#include <iostream>
#include <map>
#include <iomanip>
#include "AVLTree.h"
#include "EmployeeInfo.h"
#include "timer.h"

AVL tree; // Assuming global AVL tree for ease of use in this example
std::map<int, EmployeeInfo> stdMap; // Global std::map for similar reason

// Include your test functions here
void testMaximumSize();
void testSpeedOfSearch();
void testMaximumSizeStdMap();
void testSearchSpeedStdMap();

int main() {
    // Run your tests here
    testMaximumSize();
    testSpeedOfSearch();
    testMaximumSizeStdMap();
    testSearchSpeedStdMap();
    
    return 0;
}

// Define your test functions after main or in a separate file that you include

void testMaximumSize() {
    Timer timer;
    std::cout << "Testing Maximum Size..." << std::endl;

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
            tree.insert(empl);
            ++count;
        }
        catch (const std::bad_alloc& e) {
            std::cout << "Maximum elements before std::bad_alloc: " << count << std::endl;
            break;
        }
        catch (const std::exception& e) {
            std::cout << "Caught exception: " << e.what() << " after inserting " << count << " elements.\n";
        }
    }
    timer.stop();

    // tree.clear();
    // not clearing the tree and using the same tree to perform speed of search!
    std::cout << "Test completed with " << count << " elements." << std::endl;

    double timeForMaximumSize = timer.currtime();
    std::cout << "Time to attempt loading " << maxIterations << " elements on the std::map: " 
              << std::fixed << std::setprecision(6) << timeForMaximumSize << " seconds" << std::endl;
}

void testSpeedOfSearch() {
    std::cout << "Testing Speed of Search..." << std::endl;
    Timer timer;

    // Search for the minimumnode
    timer.start();
    node* minNode = tree.findMinPublic();
    timer.stop();
    double timeForMinSearch = timer.currtime();
    std::cout << "Time to find minimum node: " << std::fixed << std::setprecision(8) << timeForMinSearch << " seconds" << std::endl;

    timer.reset();

    // Search for the maximum node
    timer.start();
    node* maxNode = tree.findMaxPublic();
    timer.stop();
    double timeForMaxSearch = timer.currtime();
    std::cout << "Time to find maximum node: " << std::fixed << std::setprecision(8) << timeForMaxSearch << " seconds" << std::endl;

    // Displaying the nodes found
    if (minNode != NULL) {
        std::cout << "Minimum node SIN: " << minNode->empl.sin << std::endl;
    }
    if (maxNode != NULL) {
        std::cout << "Maximum node SIN: " << maxNode->empl.sin << std::endl;
    }
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

    // stdMap.clear(); // Clearing the std::map after finishing the test for maximum size
    // not clearing the map and using the same map to perform speed of search
    std::cout << "Test completed with " << count << " elements in std::map." << std::endl;

    double timeForMaximumSize = timer.currtime();
    std::cout << "Time to attempt loading " << maxIterations << " elements on the std::map: " 
              << std::fixed << std::setprecision(6) << timeForMaximumSize << " seconds" << std::endl;
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
