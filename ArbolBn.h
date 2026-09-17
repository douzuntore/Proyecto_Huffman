#pragma once

template <typename _t>
class ArbolBn 
{
	_t dato;
	ArbolBn<_t>* hijos[2] = { nullptr, nullptr };
public:
	ArbolBn(_t dato);
	~ArbolBn();
	void appendLeft(ArbolBn<_t>* nodo);
	void appendRight(ArbolBn<_t>* nodo);
	_t getDato();
};

template <typename _t>
ArbolBn<_t>::ArbolBn(_t dato) :
	dato(dato)
{
}

template <typename _t>
ArbolBn<_t>::~ArbolBn()
{
	for (ArbolBn<_t>* hijo : hijos)
	{
		delete hijo;
	}
}

template <typename _t>
void ArbolBn<_t>::appendLeft(ArbolBn<_t>* nodo)
{
	hijos[0] = nodo;
}

template <typename _t>
void ArbolBn<_t>::appendRight(ArbolBn<_t>* nodo)
{
	hijos[1] = nodo;
}

template <typename _t>
_t ArbolBn<_t>::getDato()
{
	return dato;
}


