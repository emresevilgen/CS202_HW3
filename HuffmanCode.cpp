#include "HuffmanCode.h"

/**
* Title : Heaps and AVL Trees
* Author : Munib Emre Sevilgen
* ID: 21602416
* Section : 1
* Assignment : 3
* Description : HuffmanCode implementation
*/

HuffmanCode::HuffmanCode(char* characters, int* freqs, int numberOfCharacters){
    queue = new HuffmanQueue();
    this->numberOfCharacters = numberOfCharacters;
    // Adds the nodes to the queue
    for(int i = 0; i < numberOfCharacters; i++){
        HuffmanHeap::MinHeapNode* temp = new HuffmanHeap::MinHeapNode();
        temp->character = characters[i];
        temp->freq = freqs[i];
        temp->left = NULL;
        temp->right = NULL;
        queue->insert(temp);
    }
    generateHuffmanTree();
}

HuffmanCode::~HuffmanCode(){
    delete queue;
    if(huffmanTree != NULL)
        deleteTree(huffmanTree);
}

void HuffmanCode::deleteTree(HuffmanHeap::MinHeapNode* current){
    if (current->left != NULL)
        deleteTree(current->left);
    
    if (current->right != NULL)
        deleteTree(current->right);

    delete current;
}

void HuffmanCode::getHuffmanSchemes(char* &characters, string* &schemes){
    string forNow = "";
    int index = 0;
    // Calls the recursive function
    characters = new char[numberOfCharacters];
    schemes = new string[numberOfCharacters];
    getHuffmanSchemesRec(characters, schemes, huffmanTree, index, forNow);
}

void HuffmanCode::getHuffmanSchemesRec(char* characters, string* schemes, HuffmanHeap::MinHeapNode* current, int &index, string forNow){
    // Checks whether the node is character node or not
    if (current->character != '\0'){
        characters[index] = current->character;
        schemes[index] = forNow;
        ++index;
    } else{
        string temp = forNow + '0';
        // Calls the function for left and right recursively
        if (current->left != NULL)
            getHuffmanSchemesRec(characters, schemes, current->left, index, temp);
        temp = forNow + '1';
        if (current->right != NULL)
            getHuffmanSchemesRec(characters, schemes, current->right, index, temp);
    }
}

void HuffmanCode::generateHuffmanTree(){
    int size = queue->size();
    // Generates the huffman tree
    for(int i = 0; i < size - 1; i++){
        HuffmanHeap::MinHeapNode* temp = new HuffmanHeap::MinHeapNode();
        temp->left = queue->extractMin();
        temp->right = queue->extractMin();
        temp->freq = temp->left->freq + temp->right->freq;
        temp->character = '\0';
        queue->insert(temp);
    }
    huffmanTree = queue->extractMin();

}