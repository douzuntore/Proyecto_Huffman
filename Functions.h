#pragma once
#include "CharInstance.h"
#include "BTree.h"
#include <string>
#include <vector>

std::vector<BTree<CharInstance>*> createInstanceList(std::string);

void sortInstanceList(std::vector<CharInstance>&);

BTree<CharInstance>* createHuffmanTree(std::vector<BTree<CharInstance>*>);

vector<CharInstance> createCodification(BTree<CharInstance>*);

void searchCharInstanceInTree(BTree<CharInstance>*, string, vector<CharInstance>&);

void showCodeTables(vector<CharInstance>);

string huffmanCoding(vector<CharInstance>, string);

string huffmanDecoding(BTree<CharInstance>* ,string);

unsigned int bitsInDecodedString(string input);
unsigned int bitsInEncodedString(string encoded_input);

unsigned int compressionRatio(string input, string encoded_input);