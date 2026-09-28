#include "Functions.h"

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "spanish");

	if (argc < 2) {
		cout << "Ingrese una cadena de entrada. (20 caracteres min.)" << endl;
		return 0;
	}
	string palabra = "";
	for (int i = 1; i < argc; i++)
	{
		palabra += argv[i];
		if (i != argc-1)
			palabra += " ";
	}
		
	if (palabra.size() < 20) {
		cout << "La cadena debe tener al menos 20 caracteres" << endl;
		return 0;
	}

    using namespace std;

	vector<BTree<CharInstance>*> list = createInstanceList(palabra);

	BTree<CharInstance>* instance_tree = createHuffmanTree(list);

	vector<CharInstance> coded_list = createCodification(instance_tree);

	showCodeTables(coded_list);

	string codificada = huffmanCoding(coded_list, palabra);
	cout << endl << "Palabra encriptada:" << endl << codificada << endl;

	string decodificada = huffmanDecoding(instance_tree, codificada);
	cout << "Palabra decodificada: " << decodificada << endl << endl;

	cout << "Tamaño original: " << bitsInDecodedString(decodificada) << endl;
	cout << "Tamaño codificado: " << bitsInEncodedString(codificada) << endl;
	cout << "Porcentaje de ahorro: " << compressionRatio(decodificada, codificada) << "%" << endl;

	delete instance_tree;
}