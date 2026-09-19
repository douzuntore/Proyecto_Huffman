#include "Funciones.h"

std::vector<Caracter> listarCaracteres(std::string cadena)
{
	using namespace std;
	vector<Caracter> listado;

	for (size_t i = 0; i < cadena.size(); i++)
	{
		if (listado.empty())
		{
			listado.push_back(
				Caracter(cadena.at(i))
			);
			cadena.erase(cadena.begin());
			i--;
		}
		else
		{
			bool nuevo = true;
			for (Caracter& chr : listado)
			{
				if (chr.getChr() == cadena.at(i))
				{
					chr.repeat();
					nuevo = false;
					break;
				}
			}
			if (nuevo)
			{
				listado.push_back(
					Caracter(cadena.at(i))
				);
				cadena.erase(cadena.begin());
				i--;
			}
		}
	}

	return listado;
}

void sortListado(std::vector<Caracter>& listado)
{
	for (size_t i = 0; i < listado.size(); i++)
	{
		int max = 0, rep_max = 1;
		for (size_t j = 0; j < listado.size() - i; j++)
		{
			if (listado.at(j).getReps() >= rep_max) {
				rep_max = listado.at(j).getReps();
				max = j;
			}
		}
		listado.push_back(listado.at(max));
		listado.erase(listado.begin() + max);
	}
}

ArbolBn<Caracter>* crearArbolBn(std::vector<Caracter> listado)
{
	ArbolBn<Caracter>* raiz_1 = nullptr;
	ArbolBn<Caracter>* raiz_2 = nullptr;
	for (int i = listado.size() - 2; i >= 0; i--)
	{
		if (raiz_1)
		{
			if (i == 0 || listado.at(i).getReps() >= raiz_1->getDato().getReps())
			{
				ArbolBn<Caracter>* nodo = new ArbolBn<Caracter>(listado.at(i));
				raiz_2 = raiz_1;
				raiz_1 = new ArbolBn<Caracter>(
					Caracter('\0', raiz_2->getDato().getReps() + nodo->getDato().getReps())
				);
				raiz_1->appendLeft(nodo);
				raiz_1->appendRight(raiz_2);
			}
			else
			{
				i--;
				ArbolBn<Caracter>* c_left = new ArbolBn<Caracter>(listado.at(i));
				ArbolBn<Caracter>* c_right = new ArbolBn<Caracter>(listado.at(i + 1));
				ArbolBn<Caracter>* left = new ArbolBn<Caracter>(
					Caracter('\0', c_left->getDato().getReps() + c_right->getDato().getReps())
				);
				left->appendLeft(c_left);
				left->appendRight(c_right);

				raiz_2 = raiz_1;
				raiz_1 = new ArbolBn<Caracter>(
					Caracter('\0', left->getDato().getReps() + raiz_2->getDato().getReps())
				);
				raiz_1->appendLeft(left);
				raiz_1->appendRight(raiz_2);
			}
		}
		else 
		{
			ArbolBn<Caracter>* left = new ArbolBn<Caracter>(listado.at(i));
			ArbolBn<Caracter>* right = new ArbolBn<Caracter>(listado.at(i + 1));
			raiz_1 = new ArbolBn<Caracter>(
				Caracter('\0', left->getDato().getReps() + right->getDato().getReps())
			);
			raiz_1->appendLeft(left);
			raiz_1->appendRight(right);
		}
	}
	return raiz_1;
}

