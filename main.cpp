#include "HuffmanCode.h"

#include <fstream>
#include <iostream>
using namespace std;

/**
* Title : Heaps and AVL Trees
* Author : Munib Emre Sevilgen
* ID: 21602416
* Section : 1
* Assignment : 3
* Description : Main function
*/

int main(){

    char* characters = new char[100];
    int* freqs = new int[100];
    int maxNumberOfCharacters = 100;
    int numberOfCharacters = 0;
    string line;
    string inputName;
    string outputName;
    cout << "Enter the name of the input file: ";
    cin >> inputName;
    cout << "Enter the name of the output file: ";
    cin >> outputName;

    ifstream inputFile;
    inputFile.open(inputName.c_str());

    // Reads from the file
    if (inputFile.is_open()){
        while(!inputFile.eof()){
            if (numberOfCharacters + 1 > maxNumberOfCharacters){
                int maxSize = maxNumberOfCharacters*2;
                char* temp = new char[maxSize];
                int* temp2 = new int[maxSize];
                for (int i = 0; i< numberOfCharacters; i++){
                    temp[i] = characters[i];
                    temp2[i] = freqs[i];
                    delete [] characters;
                    characters = temp;
                    delete [] freqs;
                    freqs = temp2;
                }
            }
            inputFile >> characters[numberOfCharacters] >> freqs[numberOfCharacters];
            numberOfCharacters++;
        }
    }

    // Generates the shemes
    HuffmanCode* huffman = new HuffmanCode(characters, freqs, numberOfCharacters);

    string* schemes;
    char* chars;

    huffman->getHuffmanSchemes(chars, schemes);

    // for (int i = 0; i < 6; i++)
    //     cout << chars[i] << " - " << schemes[i] << endl;

    // Writes to the file
    ofstream outputFile;
    outputFile.open(outputName.c_str());
    if(outputFile.is_open()){
        for(int i = 0; i < numberOfCharacters; i++){
            outputFile << chars[i] << " " << schemes[i] << endl;
        }
        outputFile.close();
    }    

    delete [] characters;
    delete [] freqs;
    delete [] schemes;
    delete [] chars;
    delete huffman;

    return 0;

}