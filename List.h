#pragma once
#include <iostream>

template<typename _t>
class List
{
	_t* list = nullptr;
	int size = 0;
public:
	List();
	~List();
	int end();
	void makeNull();
	int first();
	void printList();
	void insert(_t val, int pos);
	int locate(_t val);
	_t retrieve(int pos);
	void deletePos(int pos);
	int next(int pos);
	int previous(int pos);
};

template <typename _t>
List<_t>::List()
{
}

template <typename _t>
List<_t>::~List()
{
	makeNull();
}

template <typename _t>
int List<_t>::end()
{
	return size;
}

template <typename _t>
void List<_t>::makeNull()
{
	if (list)
	{
		delete[] list;
		list = nullptr;
	}
}

template <typename _t>
int List<_t>::first()
{
	if (end() != 0)
		return 0;
	else
		return end();
}

template <typename _t>
void List<_t>::printList()
{
	using namespace std;

	cout << "{" << endl;
	for (int i = first(); i < end(); i++)
	{
		cout << i + 1 << ": " << list[i] << endl;
	}
	cout << "}" << endl;
}

template <typename _t>
void List<_t>::insert(_t val, int pos)
{
	size++;

	if (pos < first() || pos > end())
	{
		size--;
		throw 1;
	}

	_t* new_list = new _t[size];

	if (list)
	{
		bool ahead = false;
		for (int i = first(); i < end(); i++)
		{
			if (i == pos)
			{
				new_list[i] = val;
				ahead = true;
			}
			else
				new_list[i] = list[i - ahead];
		}
		delete[] list;
	}
	else
	{
		new_list[0] = val;
	}
	list = new_list;
}

template <typename _t>
int List<_t>::locate(_t val)
{
	for (int i = first(); i < end(); i++)
	{
		if (val == list[i])
			return i;
	}
	throw 1;
}

template <typename _t>
_t List<_t>::retrieve(int pos)
{
	if (pos < first() || pos > end())
		throw 1;

	return list[pos];
}

template <typename _t>
void List<_t>::deletePos(int pos)
{
	if (pos < first() || pos > end())
		throw 1;

	size--;

	if (first() == end())
	{
		makeNull();
	}
	else
	{
		_t* new_list = new _t[size];

		bool ahead = false;
		for (int i = first(); i < end(); i++)
		{
			if (i == pos)
			{
				ahead = true;
			}
			else
				new_list[i - ahead] = list[i];
		}
		delete[] list;
		list = new_list;
	}

}

template <typename _t>
int List<_t>::next(int pos)
{
	if (pos >= end() || pos < first())
		throw 1;

	return ++pos;
}

template <typename _t>
int List<_t>::previous(int pos)
{
	if (pos > end() || pos <= first())
		throw 1;

	return --pos;
}