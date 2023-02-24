
#include <iostream>
#include <string>
#include <cstring>


using namespace std;

template<class elemType>
class binarySearchTree;

template<class elemType>
class Node
{
	friend class binarySearchTree<elemType>;
private:
	elemType data;

public:
	Node* left, * right;
	Node() { left = NULL;right = NULL;}
	Node(const elemType& x, Node* l = NULL, Node* r = NULL)
	{ data = x;left = l;right = r; }
};

template<class elemType>
class binarySearchTree
{
private:
	Node<elemType>* root;
	bool search(const elemType& x, Node<elemType>* t)const;
	void insert(const elemType& x, Node<elemType>*& t);
	void remove(const elemType& x, Node<elemType>*& t);
	void remove_interval(const elemType& x, elemType& y, Node<elemType>*& t);
	int search_ith(const elemType& x, Node<elemType>*& t);
public:
	binarySearchTree() { root = NULL; }
	bool search(const elemType& x)const;
	void insert(const elemType& x);
	void remove(const elemType& x);
	void remove_interval(const elemType& x, elemType& y);
	int search_ith(const elemType& x);

};


int ct = 0;

template<class elemType>
void binarySearchTree<elemType>::insert(const elemType& x)
{
	insert(x, root);
}
template<class elemType>
void binarySearchTree<elemType>::insert(const elemType& x, Node<elemType>*& t)
{
	
	if (!t) { t = new Node<elemType>(x);ct++;return; }
	if (x == t->data) return;
	if (x < t->data) insert(x, t->left);
	else insert(x, t->right);
}

template<class elemType>
bool binarySearchTree<elemType>::search(const elemType&x)const
{
	return search(x, root);
}
template<class elemType>
bool binarySearchTree<elemType>::search(const elemType& x, Node<elemType>* t)const
{
	if (!t) return false;

	if (x == t->data) return true;
	if (x < t->data) return search(x, t->left);
	else return search(x, t->right);
}

template<class elemType>
void binarySearchTree<elemType>::remove(const elemType& x)
{
	remove(x, root);
}

template<class elemType>
void binarySearchTree<elemType>::remove(const elemType& x, Node<elemType>*& t)
{
	if (!t) return;
	if (x < t->data) remove(x, t->left);
	else if (x > t->data) remove(x, t->right);
	else
	{
		if (!t->left && !t->right)
		{
			delete t;
			t = NULL;
			ct--;
			return;
		}
		if (!t->left || !t->right)
		{
			Node<elemType>* tmp;
			tmp = t;
			t = (t->left) ? t->left : t->right;
			delete tmp;
			ct--;
			return;
		}

		Node<elemType>* p, *substitute;
		p = t->right;
		while (p->left)p = p->left;
		substitute = p;
		t->data = substitute->data;
		remove(substitute->data, t->right);
	}
}

template<class elemType>
void binarySearchTree<elemType>::remove_interval(const elemType& x, elemType& y)
{
	remove_interval(x, y, root);
}

template<class elemType>
void binarySearchTree<elemType>::remove_interval(const elemType& x, elemType& y, Node<elemType>*& t)
{
	if (t == NULL) return;
	if (t->data <= x)
	{
		remove_interval(x, y, t->right);
	}
	if (t->data >= y)
	{
		remove_interval(x, y, t->left);
	}
	else if (t->data > x and t->data < y)
	{
		remove_interval(x, y, t->left);
		remove_interval(x, y, t->right);
		remove(t->data, t);

	}

}

template<class elemType>
int height(Node<elemType>*& t)
{
	if (t == NULL) return 0;
	else return 1 + height(t->left) + height(t->right);
}

template<class elemType>
int binarySearchTree<elemType>::search_ith(const elemType& x)
{
	return search_ith(x, root);

}

template<class elemType>
int binarySearchTree<elemType>::search_ith(const elemType& x, Node<elemType>*& t)
{
	int num = height(t->left);
	if (num == x - 1) return t->data;
	if (num < x - 1) return search_ith(x - num - 1, t->right);
	return search_ith(x, t->left);
}






binarySearchTree<int>* root = NULL;

int main()
{
	binarySearchTree<int> root;
	char op[100];
	int x;
	int steps = 0;
	cin >> steps;
	for (int i = 1;i <= steps;i++)
	{
		cin >> op;
		if (!strcmp(op, "insert"))
		{
			cin >> x;
			root.insert(x);
		}
		if (!strcmp(op, "find"))
		{
			cin >> x;
			if (root.search(x)) cout << "Y" << endl;
			else cout << "N" << endl;
		}
		if (!strcmp(op, "find_ith"))
		{
			cin >> x;
			if (x > ct) cout << "N" << endl;
			else cout << root.search_ith(x) << endl;
			
		}
		if (!strcmp(op, "delete"))
		{
			cin >> x;
			root.remove(x);
		}
		if (!strcmp(op, "delete_interval"))
		{
			int s, l;
			cin >> s >> l;
			root.remove_interval(s, l);
		}

	}
}

