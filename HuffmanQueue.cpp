#include "HuffmanQueue.h"

/**
* Title : Heaps and AVL Trees
* Author : Munib Emre Sevilgen
* ID: 21602416
* Section : 1
* Assignment : 3
* Description : HuffmanQueue implementation
*/

HuffmanQueue::HuffmanQueue(){
    heap = new HuffmanHeap();
}

HuffmanQueue::~HuffmanQueue(){
    delete heap;
}

void HuffmanQueue::insert(HuffmanHeap::MinHeapNode* value){
    heap->insert(value);
}

HuffmanHeap::MinHeapNode* HuffmanQueue::peek(){
    return heap->peek();
}

HuffmanHeap::MinHeapNode* HuffmanQueue::extractMin(){
    return heap->extractMin();
}

int HuffmanQueue::size(){
    return heap->size();
}



