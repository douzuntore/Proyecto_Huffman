#pragma once
#include "Pila.h"
#include "Caracter.h"
#include "ArbolBn.h"
#include <string>
#include <vector>

std::vector<Caracter> listarCaracteres(std::string cadena);
void sortListado(std::vector<Caracter>& listado);
ArbolBn<Caracter>* crearArbolBn(std::vector<Caracter> listado);
