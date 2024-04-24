#include <iostream>
#include <map>
#include "AVLTree.h" // Include your AVL Tree header
#include "EmployeeInfo.h" // Include the EmployeeInfo structure

void testAVLAndMap() {
    AVL avlTree;
    std::map<int, EmployeeInfo> stdMap;

    const int numEmployees = 5;
    EmployeeInfo employees[numEmployees] = {
        {50000, 30, 1, 123456789},
        {55000, 35, 2, 987654321},
        {60000, 40, 3, 123123123},
        {65000, 45, 4, 321321321},
        {70000, 50, 5, 111222333}
    };

    // Inserting data into both AVL tree and std::map
    for (int i = 0; i < numEmployees; ++i) {
        avlTree.insert(employees[i]);
        stdMap[employees[i].sin] = employees[i];
    }

    // Getting size of both
    std::cout << "AVL Tree Size: " << avlTree.getSize() << std::endl;
    std::cout << "std::map Size: " << stdMap.size() << std::endl;

    // Finding elements
    int sinToFind = 123123123;
    node* foundInAVL = avlTree.Find(avlTree.GetRoot(), sinToFind);
    std::cout << sinToFind << " Found in AVL"<< std::endl;
    
    auto foundInMap = stdMap.find(sinToFind);
    std::cout << sinToFind << " Found in std::map"<< std::endl;

    // Removing an element from both
    int sinToRemove = 123456789;
    avlTree.remove(sinToRemove);
    stdMap.erase(sinToRemove);

    // Display sizes after removal
    std::cout << "AVL Tree Size after removal: " << avlTree.getSize() << std::endl;
    std::cout << "std::map Size after removal: " << stdMap.size() << std::endl;

}

int main() {
    testAVLAndMap();
    return 0;
}
