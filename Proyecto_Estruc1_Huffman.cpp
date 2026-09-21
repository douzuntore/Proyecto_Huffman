#include "Functions.h"

int main()
{
    using namespace std;
	string palabra = "ASDJHFASDFLFSDAH";
	vector<BTree<CharInstance>*> list = createInstanceList(palabra);

	BTree<CharInstance>* instance_tree = createHuffmanTree(list);

	vector<CharInstance> coded_list = createCodification(instance_tree);
	showCodeTables(coded_list);
	string codificada = huffmanCoding(coded_list, palabra);
	cout << "Palabra encriptada:" << endl << codificada << endl;

	string decodificada = huffmanDecoding(instance_tree, codificada);
	cout << "Palabra decodificada: " << decodificada << endl << endl;
	delete instance_tree;


}