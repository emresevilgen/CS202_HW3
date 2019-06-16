#ifndef HUFFMANHEAP_H
#define HUFFMANHEAP_H

#include <iostream>
using namespace std;

/**
* Title : Heaps and AVL Trees
* Author : Munib Emre Sevilgen
* ID: 21602416
* Section : 1
* Assignment : 3
* Description : HuffmanHeap header file
*/

class HuffmanHeap {
public:
    struct MinHeapNode {
        char character ; // An input character
        int freq ; // Frequency of the character
        MinHeapNode * left , * right ; // Left and right child
    };

    HuffmanHeap();
    ~HuffmanHeap();

    void insert(MinHeapNode* value); // inserts into heap
    MinHeapNode* peek(); // returns the max element
    MinHeapNode* extractMin(); // retrieves and removes the max element
    int size(); // returns the number of elements in the heap

protected:
    void heapRebuild(int root); // Converts the semiheap rooted at 

private:
    MinHeapNode** items; // array of heap items
    int numberOfItems; // number of heap items
    int maxSize;

};
#endif