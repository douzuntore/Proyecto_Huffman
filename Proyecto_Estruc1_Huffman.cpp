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
	cout << "Palabra encriptada:" << endl << prueba(codeTablesVector, palabra) << endl;
	delete instance_tree;
}