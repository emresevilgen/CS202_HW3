#ifndef MEDIANHEAP_H
#define MEDIANHEAP_H

#include "MaxHeap.h"
#include "MinHeap.h"
#include <iostream>
using namespace std;

/**
* Title : Heaps and AVL Trees
* Author : Munib Emre Sevilgen
* ID: 21602416
* Section : 1
* Assignment : 3
* Description : MedianHeap header file
*/

class MedianHeap {
public:
    MedianHeap();
    ~MedianHeap();
    void insert(int value); // inserts an element into MedianHeap
    int findMedian(); // returns the value of the median

private:
    int median;
    MaxHeap* smaller;
    MinHeap* greater;
};
#endif