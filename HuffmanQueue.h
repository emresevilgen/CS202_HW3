#ifndef HUFFMANQUEUE_H
#define HUFFMANQUEUE_H

#include "HuffmanHeap.h"
#include <iostream>
using namespace std;

/**
* Title : Heaps and AVL Trees
* Author : Munib Emre Sevilgen
* ID: 21602416
* Section : 1
* Assignment : 3
* Description : HuffmanQueue header file
*/

class HuffmanQueue {
public:
    HuffmanQueue();
    ~HuffmanQueue();

    void insert(HuffmanHeap::MinHeapNode* value); // inserts into heap
    HuffmanHeap::MinHeapNode* peek(); // returns the min element
    HuffmanHeap::MinHeapNode* extractMin();

    int size(); // returns the number of elements in the heap,

private:
    HuffmanHeap* heap;

};
#endif