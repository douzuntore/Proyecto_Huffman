#include "Funciones.h"

int main()
{
    using namespace std;
	
	vector<CharInstance> list = createInstanceList("abcdeabcdeabcdeabcdeabcdeabcdabaaaaaaaa");

	sortInstanceList(list);

	BTree<CharInstance>* instance_tree = createHuffmanTree(list);

	delete instance_tree;
}