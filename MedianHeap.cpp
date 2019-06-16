#include "MedianHeap.h"
/**
* Title : Heaps and AVL Trees
* Author : Munib Emre Sevilgen
* ID: 21602416
* Section : 1
* Assignment : 3
* Description : MedianHeap implementation
*/

MedianHeap::MedianHeap(){
    smaller = new MaxHeap();
    greater = new MinHeap();
    median = -1;
}

MedianHeap::~MedianHeap(){
    delete smaller;
    delete greater;
}

void MedianHeap::insert(int value){
    if (median == -1){
        median = value;
    }
    else {
        if (value > median){
            greater->insert(value);
            if (greater->size() - 2 == smaller->size()){
                smaller->insert(median);
                median = greater->extractMin();
            }
        }
        else {
            smaller->insert(value);
            if(smaller->size() - 2 == greater->size()){
                greater->insert(median);
                median = smaller->extractMax();
            }
        }
    }
}

int MedianHeap::findMedian(){
    int greaterSize = greater->size();
    int smallerSize = smaller->size();

    if (greaterSize > smallerSize)
        return (greater->peek() + median) / 2;
    else if ( greaterSize < smallerSize)
        return (smaller->peek() + median) / 2;
    else
        return median;
}