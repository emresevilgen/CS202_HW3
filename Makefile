# Title : Heaps and AVL Trees
# Author : Munib Emre Sevilgen
# ID: 21602416
# Section : 1
# Assignment : 3
# Description : makefile



hw3: main.o HuffmanCode.o HuffmanHeap.o HuffmanQueue.o MaxHeap.o MinHeap.o MedianHeap.o
	g++ main.o HuffmanCode.o HuffmanHeap.o HuffmanQueue.o MaxHeap.o MinHeap.o MedianHeap.o -o hw3
	rm *.o

main.o: main.cpp
	g++ -c main.cpp

HuffmanCode.o: HuffmanCode.cpp HuffmanCode.h
	g++ -c HuffmanCode.cpp

HuffmanHeap.o: HuffmanHeap.cpp HuffmanHeap.h
	g++ -c HuffmanHeap.cpp

HuffmanQueue.o: HuffmanQueue.cpp HuffmanQueue.h
	g++ -c HuffmanQueue.cpp

MaxHeap.o: MaxHeap.cpp MaxHeap.h
	g++ -c MaxHeap.cpp

MinHeap.o: MinHeap.cpp MinHeap.h
	g++ -c MinHeap.cpp

MedianHeap.o: MedianHeap.cpp MedianHeap.h
	g++ -c MedianHeap.cpp

clean:
	rm hw3
	
