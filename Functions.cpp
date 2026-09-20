#include "Functions.h"
#include <iomanip>

using list_type = std::vector<BTree<CharInstance>*>;

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

// --------------------

vector<CharInstance> createCodeTables(BTree<CharInstance>& node) {
	vector<CharInstance> vector;

	testeo(node, "",vector);
	return vector;
}

void showCodeTables(vector<CharInstance> vector) {

	cout << "Tabla de codigos" << endl;
	cout << left << setw(13) << "Codigo"
		<< setw(13) << "caracter"
		<< setw(13) << "frecuencia" << endl;
	for (int i = 0; i < vector.size(); i++){
		cout << left << setw(13) << vector[i].getCode()
			<< setw(13) << vector[i].getChr()
			<< setw(13) << vector[i].getInstances() << endl;
	}

}

void testeo(BTree<CharInstance>& node, string pos, vector<CharInstance>& resultado) {
	if (!node.getRight() && !node.getLeft())
	{
		CharInstance dada = node.getData();
		dada.addCode(pos);
		
		//return node.getDato();
		resultado.push_back(dada);
	}
	if (node.getLeft()) {
		
		testeo(*node.getLeft(),pos + "0", resultado);

	}
	if (node.getRight()) {
		
	    testeo(*node.getRight(), pos + "1", resultado);
	}
	
}



string prueba(vector<CharInstance> vector, string palabra) {

	string salida = "";
	for (int i = 0; i < palabra.size(); i++){
		char a = palabra[i];
		for (int i = 0; i < vector.size(); i++)
		{
			char ch = vector[i].getChr();
			if (ch==a)
			{
				salida += vector[i].getCode();
				break;
			}
		}
		



	}
	return salida;
}