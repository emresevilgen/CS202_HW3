#ifndef MINHEAP_H
#define MINHEAP_H
#include <iostream>
using namespace std;
/**
* Title : Heaps and AVL Trees
* Author : Munib Emre Sevilgen
* ID: 21602416
* Section : 1
* Assignment : 3
* Description : MinHeap header file
*/

class MinHeap {
public:
    MinHeap();
    ~MinHeap();

    void insert(int value); // inserts integer into heap
    int peek(); // returns the value of the min element
    int extractMin(); // retrieves and removes the min element
    int size(); // returns the number of elements in the heap

protected:
    void heapRebuild(int root); // Converts the semiheap rooted at 

private:
    int* items; // array of heap items
    int numberOfItems; // number of heap items
    int maxSize;
};

#endif