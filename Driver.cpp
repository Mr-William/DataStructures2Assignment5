//***********************************************************
//
//     File:          Driver.cpp
//
//     Author:        William Gibbs
//
//     Course Name:   Data Structures 2
//
//     Course Number: COSC 3100
//
//     Description:   Huffman Code applied to Stock class.
//
//***********************************************************

#include "Node.h"
#include "Stock.h"
#include <iostream>
#include <limits>
#include <fstream>

void printArray(int path[], int pathLen, Node<Stock>* leaf);
void printPaths(Node<Stock>* node, int path[], int pathLen, int lr);

int main()
{
	using namespace std;

	fstream stocks;
	Stock s;
	const int numStocks = 10;
	int i = 0;
	Stock stockArr[numStocks];
	double freq[numStocks];

	Node<Stock>* elements[numStocks];

	stocks.open("Stocks.txt");
	
	while (!stocks.eof())
	{
		stocks >> s;
		stockArr[i] = s;
		freq[i] = s.getFreq();
		i++;
	}

	stocks.close();

	for (int j = 0; j < numStocks; ++j)
	{
		elements[j] = new Node<Stock>;
		elements[j]->value = stockArr[j];
		elements[j]->frequency = freq[j];
		elements[j]->left = nullptr;
		elements[j]->right = nullptr;
	}

	int index1;
	int index2;
	double freq1;
	double freq2;
	Node<Stock>* newNode;
	int removeIndex;
	int size = numStocks;

	while (size > 1)
	{
		index1 = index2 = 0;
		freq1 = freq2 = numeric_limits<double>::max();

		for (int j = 0; j < size; ++j)
		{
			if (elements[j]->frequency < freq1)
			{
				freq2 = freq1;
				freq1 = elements[j]->frequency;
				index1 = j;
			}
			else if ((elements[j]->frequency < freq2) && (j != index1))
			{
				freq2 = elements[j]->frequency;
				index2 = j;
			}
		}

		newNode = new Node<Stock>;
		newNode->left = elements[index1];
		newNode->right = elements[index2];
		newNode->frequency = freq1 + freq2;

		elements[index1] = newNode;

		for (int j = index2; j < size - 1; ++j)
		{
			elements[j] = elements[j + 1];
		}

		--size;
	}

	cout << "======Tree Display======" << endl;
	Node<Stock>* rootPtr = elements[0];
	int paths[numStocks];
	printPaths(rootPtr, paths, 0, -1);

	string sentence = "000101001111001111001101111111101";

	cout << "\n\n---Reviewing Sequence: " << sentence << "---\n" << endl;

	cout << "\n\nStocks represented in sequence: " << endl;
	i = 0;

	rootPtr = elements[0];

	while (i < sentence.size())
	{
		while ((rootPtr->left != nullptr) && (rootPtr->right != nullptr))
		{
			if (sentence[i] == '1')
			{
				rootPtr = rootPtr->right;
			}
			else
			{
				rootPtr = rootPtr->left;
			}
			++i;
		}
		cout << "======\n" << rootPtr->value;
		rootPtr = elements[0];
	}
	cout << endl;

	return 0;
}

void printPaths(Node<Stock>* node, int path[], int pathLen, int lr)
{
	if (node != nullptr)
	{
		if (lr != -1)
		{
			path[pathLen] = lr;
			++pathLen;
		}
		if ((node->left == nullptr) && (node->right == nullptr))
		{
			printArray(path, pathLen, node);
		}
		else
		{
			printPaths(node->left, path, pathLen, 0);
			printPaths(node->right, path, pathLen, 1);
		}
	}
}

void printArray(int path[], int pathLen, Node<Stock>* leaf)
{
	std::cout << leaf->value;
	std::cout << "Path: ";
	for (int j = 0; j < pathLen; j++)
	{
		std::cout << path[j] << " ";
	}
	std::cout << "\n" << std::endl;
}