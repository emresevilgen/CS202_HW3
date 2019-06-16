#include "HuffmanHeap.h"

/**
* Title : Heaps and AVL Trees
* Author : Munib Emre Sevilgen
* ID: 21602416
* Section : 1
* Assignment : 3
* Description : HuffmanHeap implementation
*/

HuffmanHeap::HuffmanHeap(){
    numberOfItems = 0;
    items = NULL;
    maxSize = 0;
}

HuffmanHeap::~HuffmanHeap(){
    for (int i = 0; i < numberOfItems; i++)
        items[i] = NULL;
    delete [] items;
}

void HuffmanHeap::insert(MinHeapNode* value){
    if (items == NULL){
        items = new MinHeapNode* [100];
        maxSize = 100;
    }
    if (numberOfItems >= maxSize){
        int maxSize2 = maxSize*2;
        MinHeapNode** temp = new MinHeapNode* [maxSize2];
        for (int i = 0; i < numberOfItems; i++){
            temp[i] = items[i];
        }
        MinHeapNode** toDelete = items;
        items = temp;
        // delete [] toDelete;
        maxSize = maxSize2;

    }
    // Place the new item at the end of the heap
    items[numberOfItems] = value;

    // Trickle new item up to its proper position
    int place = numberOfItems;
    int parent = (place - 1)/2;

    while ((place > 0) && (items[place]->freq < items[parent]->freq)){
		MinHeapNode* temp = items[parent];
		items[parent] = items[place];
		items[place] = temp;

		place = parent;
		parent = (place - 1)/2;
	}
 	++numberOfItems;
}

HuffmanHeap::MinHeapNode* HuffmanHeap::peek(){
    if (numberOfItems > 0){
        return items[0];
    }
    else
        return NULL;
}

HuffmanHeap::MinHeapNode* HuffmanHeap::extractMin(){
    if (numberOfItems > 0){
        MinHeapNode* rootItem = items[0];
        items[0] = items[--numberOfItems];
        heapRebuild(0);
        return rootItem;
    }
    else
        return NULL;
}

int HuffmanHeap::size(){
    return numberOfItems;
}

void HuffmanHeap::heapRebuild(int root){
    int child = 2*root + 1; // index of root's left child, if any
    if (child < numberOfItems){
        // root is not a leaf so that it has a left child
        int rightChild = child + 1;  // index of a right child, if any

        // If root has right child, find larger child
        if ((rightChild < numberOfItems) &&  (items[rightChild]->freq < items[child]->freq))
            child = rightChild;

        // If root’s item is smaller than larger child, swap values 
        if (items[root]->freq > items[child]->freq){
			MinHeapNode* temp = items[root];
			items[root] = items[child];
			items[child] = temp;

			// transform the new subtree into a heap
			heapRebuild(child);
		}
    }
}


