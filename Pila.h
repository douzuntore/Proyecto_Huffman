#pragma once
#include "List.h"

template<typename _t>
class Pila
{
	List<_t> lista;
public:
	Pila();
	void push(_t elemento);
	void pop();
	_t peek();
	bool estaVacia();
};

template<typename _t>
Pila<_t>::Pila()
{
}

template<typename _t>
void Pila<_t>::push(_t elemento)
{
	lista.insert(elemento, lista.end());
}

template<typename _t>
void Pila<_t>::pop()
{
	lista.deletePos(lista.end());
}

template<typename _t>
_t Pila<_t>::peek()
{
	lista.retrieve(lista.end());
}

template<typename _t>
bool Pila<_t>::estaVacia()
{
	return lista.first() == lista.end();
}

