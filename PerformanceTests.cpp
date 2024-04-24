#include <iostream>
#include <map>
#include <vector>
#include <chrono>
#include <cstdlib> // For system("pause")

#include "AVLTree.h"
#include "EmployeeInfo.h"
#include "timer.h"

using namespace std;
using namespace std::chrono;

std::ofstream insert1;

AVL tree;   // globally declaring AVL tree and using the same tree everytime to clear it when using SIGINT.

// Signal handler function
void signalHandler(int signal) {
    std::cout << "\nCtrl+C pressed. Cleaning up and exiting..." << std::endl;
    
    if (tree.GetRoot() != NULL) {
        tree.clear(); 
    }
    exit(signal);
}

void DisplayTree(node* t)
	{
		if (t == NULL)
			return;
		DisplayTree(t->left);
		insert1 << " height:" << t->height << " sin:" << t->empl.sin << " employee number:" << t->empl.emplNumber << " salary:" << t->empl.salary << " age:" << t->empl.age << endl;
		DisplayTree(t->right);
	}

// Function prototypes
void testInsertion();
void testDeletion();
void testMaximumSize();
void testLoad();
void testSpeedOfSearch();
void pauseBetweenTests();

int main() {
    signal(SIGINT, signalHandler);
    cout << "Starting performance tests..." << endl;

    testInsertion();
    pauseBetweenTests();

    testDeletion();
    pauseBetweenTests();

    testMaximumSize();
    pauseBetweenTests();

    testLoad();
    pauseBetweenTests();

    testSpeedOfSearch();
    pauseBetweenTests();

    cout << "Performance tests completed." << endl;
    return 0;
}

void testInsertion() {
    cout << "Testing Insertion..." << endl;
    insert1.open("insertDelete3.txt");

    const size_t numOfInsertions = 15; 
    for (size_t i = 0; i < numOfInsertions; ++i) {
        EmployeeInfo empl;
        empl.sin = static_cast<int>(i); // Use count as the SIN
        empl.age = 30;
        empl.salary = 50000;
        empl.emplNumber = static_cast<int>(i);
        tree.insert(empl); // Inserting by count as key
    }
    insert1 << "Insertion" << endl;
    insert1 << "INORDER (NUM=" << numOfInsertions << ", height=" << tree.GetRoot()->height << "): root node has sin:" << tree.GetRoot()->empl.sin << endl << endl;
    DisplayTree(tree.GetRoot());
    // insert1.close();
}

void testDeletion() {
    cout << "Testing Deletion..." << endl;
    // delete1.open("insertDelete1.txt");

    tree.remove(18);
    tree.remove(15);
    tree.remove(11);
    tree.remove(10);

    insert1 << "Deletion" << endl;
    insert1 << "INORDER (NUM=" << 15 << ", height=" << tree.GetRoot()->height << "): root node has sin:" << tree.GetRoot()->empl.sin << endl << endl;
    DisplayTree(tree.GetRoot());
    insert1.close();
    // Implement deletion test for both AVLTree and std::map
}

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

    tree.clear();
    std::cout << "Test completed with " << count << " elements." << std::endl;

    double timeForMaximumSize = timer.currtime();
    std::cout << "Time to attempt loading " << maxIterations << " elements on the std::map: " 
              << std::fixed << std::setprecision(6) << timeForMaximumSize << " seconds" << std::endl;
}

void testLoad() {
    cout << "Testing Load..." << endl;
    const size_t numOfInsertions = 10000000; 
    Timer timer;
    timer.start();
    for (size_t i = 0; i < numOfInsertions; ++i) {
        EmployeeInfo empl;
        empl.sin = static_cast<int>(i); // Use count as the SIN
        empl.age = 30;
        empl.salary = 50000;
        empl.emplNumber = static_cast<int>(i);
        tree.insert(empl); // Inserting by count as key
    }
    timer.stop();
    std::cout << "Time taken to load " << numOfInsertions << " elements into AVLTree: " 
              << std::fixed << std::setprecision(6) << timer.currtime() << " seconds." << std::endl;
    // Not clearing the tree and using the same tree for the next test to find Speed of search.
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


void pauseBetweenTests() {
    cout << "Press enter to continue..." << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
