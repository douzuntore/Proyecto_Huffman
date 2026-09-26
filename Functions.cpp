#include "Functions.h"
#include <iomanip>

using list_type = std::vector<BTree<CharInstance>*>;

// ---------- LECTURA DEL STRING DE ENTRADA ----------

list_type createInstanceList(std::string string_input)
{
	using namespace std;
	list_type instance_list;

	for (size_t i = 0; i < string_input.size(); i++)
	{
		if (instance_list.empty())
		{
			instance_list.push_back(
				new BTree<CharInstance>(
					CharInstance(string_input.at(i))
				)
			);
			string_input.erase(string_input.begin());
			i--;
		}
		else
		{
			bool is_new_instance = true;
			for (BTree<CharInstance>* chr : instance_list)
			{
				if (chr->getData().getChr() == string_input.at(i))
				{
					chr->getData().repeat();
					is_new_instance = false;
					break;
				}
			}
			if (is_new_instance)
			{
				instance_list.push_back(
					new BTree<CharInstance>(
						CharInstance(string_input.at(i))
					)
				);
				string_input.erase(string_input.begin());
				i--;
			}
		}
	}

	return instance_list;
}

// ---------- CREACION DE ARBOL DE HUFFMAN ----------

BTree<CharInstance>* createHuffmanTree(list_type instance_list)
{
	while (instance_list.size() > 1)
	{
		BTree<CharInstance>* new_tree_nodes[2];
		for (BTree<CharInstance>*& new_tree_node : new_tree_nodes)
		{
			new_tree_node = instance_list.at(0);
			size_t min_index = 0;
			int min_instances = instance_list.at(0)->getData().getInstances();
			for (size_t i = 1; i < instance_list.size(); i++)
			{
				BTree<CharInstance>* chr_node = instance_list[i];
				if (min_instances > chr_node->getData().getInstances())
				{
					min_instances = chr_node->getData().getInstances();
					new_tree_node = chr_node;
					min_index = i;
				}
			}
			instance_list.erase(instance_list.begin() + min_index);
		}
		BTree<CharInstance>* new_tree = new BTree<CharInstance>(
			//definir dato interno
			CharInstance('\0', new_tree_nodes[1]->getData().getInstances() + new_tree_nodes[0]->getData().getInstances()),
			//definir nodo izquierdo
			new_tree_nodes[1],
			//definir nodo derecho
			new_tree_nodes[0]
		);
		instance_list.push_back(new_tree);
	}

	return instance_list.at(0);
}

// ---------- CREACION DE CODIGOS ----------

vector<CharInstance> createCodification(BTree<CharInstance>* node) {

	vector<CharInstance> coded_instance_list;
	searchCharInstanceInTree(node, "", coded_instance_list);
	return coded_instance_list;

}

void searchCharInstanceInTree(BTree<CharInstance>* node, string codification, vector<CharInstance>& coded_instance_list) {

	if (!node->getRight() && !node->getLeft())
	{
		CharInstance node_data = node->getData();
		node_data.addCode(codification);
		coded_instance_list.push_back(node_data);
	}
	else 
	{
		if (node->getLeft())
			searchCharInstanceInTree(node->getLeft(), codification + "0", coded_instance_list);
		if (node->getRight())
			searchCharInstanceInTree(node->getRight(), codification + "1", coded_instance_list);
	}

}

// ---------- CREACION DE TABLA ----------

void sortInstanceList(std::vector<CharInstance>& instance_list)
{
	for (size_t i = 0; i < instance_list.size(); i++)
	{
		int max = 0, rep_max = 1;
		for (size_t j = 0; j < instance_list.size() - i; j++)
		{
			if (instance_list.at(j).getInstances() >= rep_max) {
				rep_max = instance_list.at(j).getInstances();
				max = j;
			}
		}
		instance_list.push_back(instance_list.at(max));
		instance_list.erase(instance_list.begin() + max);
	}
}

void showCodeTables(vector<CharInstance> vector) {

	sortInstanceList(vector);
	cout << "Tabla de codigos" << endl;
	cout << left << setw(13) << "Codigo"
		<< setw(13) << "caracter"
		<< setw(13) << "frecuencia" << endl;
	for (int i = 0; i < vector.size(); i++) {
		cout << left << setw(13) << vector[i].getCode()
			<< setw(13) << vector[i].getChr()
			<< setw(13) << vector[i].getInstances() << endl;
	}

}

// ---------- CODIFICACION ----------

string huffmanCoding(vector<CharInstance> coded_instance_list, string string_input) {

	string encoded = "";
	for (char str_char : string_input)
		for (CharInstance instance : coded_instance_list)
			if (str_char == instance.getChr())
				encoded += instance.getCode();

	return encoded;

}

// ---------- DECODIFICACION ----------

string huffmanDecoding(BTree<CharInstance>* root, string code) {

	string decoded = "";
	BTree<CharInstance>* node = root;
	for (int i = 0; i < code.size(); i++)
		if (node->getLeft() && node->getRight())
		{
			if (code[i] == '0') {
				node = node->getLeft();
			}
			else if (code[i] == '1') {
				node = node->getRight();
			}
			if (!node->getLeft() && !node->getRight()) {
				decoded += node->getData().getChr();
				node = root;
			}
		}

	return decoded;

}

// ---------- CALCULO DE BITS ----------

unsigned int bitsInDecodedString(string input)
{
	return input.size() * 8;
}

unsigned int bitsInEncodedString(string encoded_input)
{
	return encoded_input.size();
}

unsigned double compressionRatio(string input, string encoded_input)
{
	unsigned double ahorro = ((double)(bitsInDecodedString(input) - (double)bitsInEncodedString(encoded_input)) / (double)bitsInDecodedString(input)) * 100;
	return ahorro;
}

