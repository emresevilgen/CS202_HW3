#ifndef HUFFMANCODE_H
#define HUFFMANCODE_H

#include "HuffmanQueue.h"
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

class HuffmanCode {
public:
    HuffmanCode(char* characters, int* freqs, int numberOfCharacters);
    ~HuffmanCode();
    void getHuffmanSchemes(char* &characters, string* &schemes);

protected:
    void generateHuffmanTree();
    void getHuffmanSchemesRec(char* characters, string* schemes, HuffmanHeap::MinHeapNode* current, int &index, string forNow);
    void deleteTree(HuffmanHeap::MinHeapNode* current);


private:
    HuffmanQueue* queue;
    HuffmanHeap::MinHeapNode* huffmanTree;
    int numberOfCharacters;
};
#endif