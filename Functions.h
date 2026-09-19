#pragma once
#include "CharInstance.h"
#include "BTree.h"
#include <string>
#include <vector>

std::vector<CharInstance> createInstanceList(std::string);

void sortInstanceList(std::vector<CharInstance>&);

BTree<CharInstance>* createHuffmanTree(std::vector<CharInstance>);