#pragma once
#include "CharInstance.h"
#include "BTree.h"
#include <string>
#include <vector>

std::vector<BTree<CharInstance>*> createInstanceList(std::string);

void sortInstanceList(std::vector<CharInstance>&);

BTree<CharInstance>* createHuffmanTree(std::vector<BTree<CharInstance>*>);

vector<CharInstance> createCodeTables(BTree<CharInstance>&);

void testeo(BTree<CharInstance>&, string, vector<CharInstance>&);

void showCodeTables(vector<CharInstance> vector);