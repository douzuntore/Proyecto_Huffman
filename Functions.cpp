#include "Functions.h"

std::vector<CharInstance> createInstanceList(std::string string_input)
{
	using namespace std;
	vector<CharInstance> listado;

	for (size_t i = 0; i < string_input.size(); i++)
	{
		if (listado.empty())
		{
			listado.push_back(
				CharInstance(string_input.at(i))
			);
			string_input.erase(string_input.begin());
			i--;
		}
		else
		{
			bool is_new_instance = true;
			for (CharInstance& chr : listado)
			{
				if (chr.getChr() == string_input.at(i))
				{
					chr.repeat();
					is_new_instance = false;
					break;
				}
			}
			if (is_new_instance)
			{
				listado.push_back(
					CharInstance(string_input.at(i))
				);
				string_input.erase(string_input.begin());
				i--;
			}
		}
	}

	return listado;
}

void sortInstanceList(std::vector<CharInstance>& instance_list)
{
	for (size_t i = 0; i < instance_list.size(); i++)
	{
		int max_index = 0, max_instances = 1;
		for (size_t j = 0; j < instance_list.size() - i; j++)
		{
			if (instance_list.at(j).getReps() >= max_instances) {
				max_instances = instance_list.at(j).getReps();
				max_index = j;
			}
		}
		instance_list.push_back(instance_list.at(max_index));
		instance_list.erase(instance_list.begin() + max_index);
	}
}

BTree<CharInstance>* createHuffmanTree(std::vector<CharInstance> listado)
{
	BTree<CharInstance>* main_root = nullptr;

	for (int i = listado.size() - 2; i >= 0; i--)
	{
		if (main_root)
		{
			if (i == 0 || listado.at(i).getReps() >= main_root->getDato().getReps())
			{
				main_root = new BTree<CharInstance>(
					//definir dato interno
					CharInstance('\0', listado.at(i).getReps() + main_root->getDato().getReps()),
					//definir nodo izquierdo
					new BTree<CharInstance>(listado.at(i)),
					//definir nodo derecho
					main_root
				);
			}
			else
			{
				i--;

				BTree<CharInstance>* left_child = new BTree<CharInstance>(
					//definir dato interno
					CharInstance('\0', listado.at(i).getReps() + listado.at(i + 1).getReps()),
					//definir nodo izquierdo
					new BTree<CharInstance>(listado.at(i)),
					//definir nodo derecho
					new BTree<CharInstance>(listado.at(i + 1))
				);

				main_root = new BTree<CharInstance>(
					//definir dato interno
					CharInstance('\0', left_child->getDato().getReps() + main_root->getDato().getReps()),
					//definir nodo izquierdo
					left_child,
					//definir nodo derecho
					main_root
				);
			}
		}
		else 
		{
			main_root = new BTree<CharInstance>(
				//definir dato interno
				CharInstance('\0', listado.at(i).getReps() + listado.at(i + 1).getReps()),
				//definir nodo izquierdo
				new BTree<CharInstance>(listado.at(i)),
				//definir nodo derecho
				new BTree<CharInstance>(listado.at(i + 1))
			);
		}
	}

	return main_root;
}

