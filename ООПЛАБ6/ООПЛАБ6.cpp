#include <iostream>
#include <vld.h>

template< class T > class BinaryTree;

template <class T>
class TreeNode {
	friend class BinaryTree<T>;
public:
	TreeNode();
	TreeNode(T);
	~TreeNode();
	
private:
	T data;
	TreeNode<T>* left;
	TreeNode<T>* right;
	void printInfix();
};

template <class T>
class BinaryTree {
	//friend class TreeNode<T>;
public:
	BinaryTree();
	~BinaryTree();
	void insert(T);
	void printTreeInfix(); 
	void deleteTree();
private:
	TreeNode<T>* root;

	void deleteTreeHelper(TreeNode<T>*&);
};

//Class tree methods--------------------------------

template <typename T>
BinaryTree<T>::BinaryTree() {
	root = NULL;
}

template <typename T>
void BinaryTree<T>::insert(T data) {
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
BinaryTree<T>::~BinaryTree() {
	this->deleteTree();
}

template <typename T>
void BinaryTree<T>::printTreeInfix() {
	root->printInfix();
}

template<class T>
void BinaryTree<T>::deleteTree() {
	deleteTreeHelper(root);
}

template<class T>
void BinaryTree<T>::deleteTreeHelper(TreeNode<T>*& node) {
	if (node) {
		deleteTreeHelper(node->left);
		deleteTreeHelper(node->right);
		delete node;
	}
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
	BinaryTree <int> tree;
	tree.insert(6);
	tree.insert(7);
	tree.insert(5);
	tree.insert(0);
	tree.insert(9);
	tree.insert(55);
	tree.printTreeInfix();
}
