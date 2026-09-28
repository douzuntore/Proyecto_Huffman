#pragma once

template <typename _t>
class BTree 
{
	_t data;
	BTree<_t>* nodes[2] = { nullptr, nullptr };
public:
	BTree(_t);
	BTree(_t, BTree<_t>*, BTree<_t>*);
	~BTree();
	void appendLeft(BTree<_t>*);
	void appendRight(BTree<_t>*);
	_t& getData();
	BTree<_t>* getLeft();  
	BTree<_t>* getRight();
	
};

template <typename _t>
BTree<_t>::BTree(_t data) :
	data(data)
{
}

template <typename _t>
BTree<_t>::BTree(_t data, BTree<_t>* left_node, BTree<_t>* right_node) :
	data(data)
{
	appendLeft(left_node);
	appendRight(right_node);
}

template <typename _t>
BTree<_t>::~BTree()
{
	for (BTree<_t>* node : nodes)
		if (node)
			delete node;
}

template <typename _t>
void BTree<_t>::appendLeft(BTree<_t>* node)
{
	nodes[0] = node;
}

template <typename _t>
void BTree<_t>::appendRight(BTree<_t>* node)
{
	nodes[1] = node;
}

template <typename _t>
_t& BTree<_t>::getData()
{
	return data;
}
template <typename _t>
BTree<_t>* BTree<_t>::getLeft()
{
	return nodes[0];
}

template <typename _t>
BTree<_t>* BTree<_t>::getRight()
{
	return nodes[1];
}

