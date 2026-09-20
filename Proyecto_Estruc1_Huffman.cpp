#include "Functions.h"

int main()
{
    using namespace std;
	
	vector<CharInstance> list = createInstanceList("abcdeabcdeabcdeabcdeabcdeabcdabaaaaaaaa");

	sortInstanceList(list);

	BTree<CharInstance>* instance_tree = createHuffmanTree(list);
	vector<CharInstance> codeTablesVector = createCodeTables(*instance_tree);
	showCodeTables(codeTablesVector);
	
	delete instance_tree;
}