#include "Funciones.h"

int main()
{
    using namespace std;
	
	vector<Caracter> listado = listarCaracteres("aaaabbccd");

	sortListado(listado);

	crearArbolBn(listado);
}