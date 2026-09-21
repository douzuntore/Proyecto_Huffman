#include "Functions.h"

int main()
{
    using namespace std;
	string palabra = "ESTRUCTURA DE DATOS I";
	vector<BTree<CharInstance>*> list = createInstanceList(palabra);

	//sortInstanceList(list);

	BTree<CharInstance>* instance_tree = createHuffmanTree(list);
	vector<CharInstance> codeTablesVector = createCodeTables(*instance_tree);
	showCodeTables(codeTablesVector);
	string codificada = coding(codeTablesVector, palabra);
	cout << "Palabra encriptada:" << endl << codificada << endl;

	string decodificada = decoding(instance_tree, codificada);
	cout << "Palabra decodificada: " << decodificada << endl << endl;
	delete instance_tree;
}