#include "MinHeap.h"

/**
* Title : Heaps and AVL Trees
* Author : Munib Emre Sevilgen
* ID: 21602416
* Section : 1
* Assignment : 3
* Description : MinHeap implementation
*/

MinHeap::MinHeap(){
    numberOfItems = 0;
    items = NULL;
    maxSize = 0;
}

MinHeap::~MinHeap(){
    delete [] items;
}

void MinHeap::insert(int value){
    if (items == NULL){
        items = new int [1000];
        maxSize = 1000;
    }
    if (numberOfItems >= maxSize){
        int maxSize2 = maxSize*2;
        int* temp = new int [maxSize2];
        for (int i = 0; i < numberOfItems; i++){
            temp[i] = items[i];
        }
        int* toDelete = items;
        items = temp;
        delete [] toDelete;
        maxSize = maxSize2;

    }
    // Place the new item at the end of the heap
    items[numberOfItems] = value;

    // Trickle new item up to its proper position
    int place = numberOfItems;
    int parent = (place - 1)/2;

    while ((place > 0) && (items[place] < items[parent])){
		int temp = items[parent];
		items[parent] = items[place];
		items[place] = temp;

		place = parent;
		parent = (place - 1)/2;
	}
 	++numberOfItems;
}

int MinHeap::peek(){
   if (numberOfItems > 0){
        return items[0];
    }
    else
        return -1;
}


int MinHeap::extractMin(){
    if (numberOfItems > 0){
        int rootItem = items[0];
        items[0] = items[--numberOfItems];
        heapRebuild(0);
        return rootItem;
    }
    else
        return -1;
}


int MinHeap::size(){
    return numberOfItems;
}

void MinHeap::heapRebuild(int root){
    int child = 2*root + 1; // index of root's left child, if any
    if (child < numberOfItems){
        // root is not a leaf so that it has a left child
        int rightChild = child + 1;  // index of a right child, if any

        // If root has right child, find larger child
        if ((rightChild < numberOfItems) &&  (items[rightChild] < items[child]))
            child = rightChild;

        // If root’s item is smaller than larger child, swap values 
        if (items[root] > items[child]){
			int temp = items[root];
			items[root] = items[child];
			items[child] = temp;

			// transform the new subtree into a heap
			heapRebuild(child);
		}
  
    }
}

