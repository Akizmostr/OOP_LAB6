#include <iostream>

template< class T > class Tree;

template <class T>
class TreeNode {
	friend class Tree<T>;
public:
	TreeNode();
	TreeNode(T);
	~TreeNode();
	T get_data() const;
	
private:
	T data;
	TreeNode<T>* left;
	TreeNode<T>* right;
	void printInfix();
};

template <class T>
class Tree {
	//friend class TreeNode<T>;
public:
	Tree();
	~Tree();
	void insert(T);
	void printTreeInfix();
private:
	TreeNode<T>* root;
};

//Class tree methods--------------------------------

template <typename T>
Tree<T>::Tree() {
	root = NULL;
}

template <typename T>
void Tree<T>::insert(T data) {
	if (root == 0) {
		root = new TreeNode<T>(data);
		return;
	}
	TreeNode<T>* prev = NULL;
	TreeNode<T>* temp = root;
	bool left = 0;
	while (temp) {
		prev = temp;
		if (data < temp->data) {
			temp = temp->left;
			left = 1;
		}
		else {
			temp = temp->right;
			left = 0;
		}
	}
	temp = new TreeNode<T> (data);
	if (left) {
		prev->left = temp;
	}
	else {
		prev->right = temp;
	}
}

template <typename T>
Tree<T>::~Tree() {
}

template <typename T>
void Tree<T>::printTreeInfix() {
	root->printInfix();
}

//Class TreeNode methods --------------------------------------------
template <typename T>
TreeNode<T>::TreeNode() {
	left = NULL;
	right = NULL;
}

template <typename T>
TreeNode<T>::TreeNode(const T new_data) {
	data = new_data;
	left = NULL;
	right = NULL;
}

template <typename T>
TreeNode<T>::~TreeNode() {
	delete left;
	delete right;
}

template<typename T>
T TreeNode<T>::get_data() const {
	return data;
}

template<class T>
void TreeNode<T>::printInfix() {
	if (this) {
		this->left->printInfix();
		std::cout << this->data << "\t";
		this->right->printInfix();
	}
}




int main()
{
	Tree <int> tree;
	tree.insert(6);
	tree.insert(7);
	tree.insert(5);
	tree.insert(0);
	tree.insert(9);
	tree.insert(55);
	tree.printTreeInfix();
}
