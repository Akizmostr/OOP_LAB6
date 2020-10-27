#include <iostream>
#include <vld.h>

template< class T > class BinaryTree;

template <class T>
class TreeNode {
	friend class BinaryTree<T>;
public:
	TreeNode(const T&);
	~TreeNode();
	
private:
	T data;
	TreeNode<T>* left;
	TreeNode<T>* right;
	void printInfix();
};

template <class T>
class TreeNode<T*> {
	friend class BinaryTree<T*>;
public:
	TreeNode<T*>(T*&);
	~TreeNode<T*>();

private:
	T* data;
	TreeNode<T*>* left;
	TreeNode<T*>* right;
	void printInfix();
};

template <class T>
class BinaryTree {
	//friend class TreeNode<T>;
public:
	BinaryTree();
	~BinaryTree();
	void insert(T&);
	void printTreeInfix(); 
	void deleteTree();
private:
	TreeNode<T>* root;

	void deleteTreeHelper(TreeNode<T>*&);
};

template <class T>
class BinaryTree<T*> {
public:
	~BinaryTree();
	void insert(T*&);
	void printTreeInfix();
	void deleteTree();
private:
	TreeNode<T*>* root;

	void deleteTreeHelper(TreeNode<T*>*&);
};

//Class tree methods--------------------------------

template <typename T>
BinaryTree<T>::BinaryTree() {
	root = NULL;
}

template <typename T>
void BinaryTree<T>::insert(T& data) {
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
void BinaryTree<T*>::insert(T*& data) {
	if (root == 0) {
		root = new TreeNode<T*>(data);
		return;
	}
	TreeNode<T*>* prev = NULL;
	TreeNode<T*>* temp = root;
	bool left = 0;
	while (temp) {
		prev = temp;
		if (*data < *(temp->data)) {
			temp = temp->left;
			left = 1;
		}
		else {
			temp = temp->right;
			left = 0;
		}
	}
	temp = new TreeNode<T*>(data);
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
BinaryTree<T*>::~BinaryTree() {
	this->deleteTree();
}

template <typename T>
void BinaryTree<T>::printTreeInfix() {
	root->printInfix();
}

template <typename T>
void BinaryTree<T*>::printTreeInfix() {
	root->printInfix();
}

template<class T>
void BinaryTree<T>::deleteTree() {
	deleteTreeHelper(root);
}

template<class T>
void BinaryTree<T*>::deleteTree() {
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

template<class T>
void BinaryTree<T*>::deleteTreeHelper(TreeNode<T*>*& node) {
	if (node) {
		deleteTreeHelper(node->left);
		deleteTreeHelper(node->right);
		delete node;
	}
}

//Class TreeNode methods --------------------------------------------

template <class T>
TreeNode<T>::TreeNode(const T& new_data) {
	data = new_data;
	left = NULL;
	right = NULL;
}

template<class T>
TreeNode<T*>::TreeNode(T*& new_data) {
	data = new T(*new_data);
	left = NULL;
	right = NULL;
}

template <typename T>
TreeNode<T>::~TreeNode() {
}

template <class T>
TreeNode<T*>::~TreeNode<T*>() {
	delete data;
}

template<class T>
void TreeNode<T>::printInfix() {
	if (this) {
		this->left->printInfix();
		std::cout << this->data << "\t";
		this->right->printInfix();
	}
}

template<class T>
void TreeNode<T*>::printInfix() {
	if (this) {
		this->left->printInfix();
		std::cout << *(this->data) << "\t";
		this->right->printInfix();
	}
}

int main()
{
	BinaryTree <char> char_tree;
	BinaryTree <double> double_tree;
	BinaryTree <std::string> string_tree;
	BinaryTree <int*> intptr_tree;
	char arr[7] = {'d', 'f', 'e', 'a', '^', 'W', 'q'};
	double arr2[7] = { 2.5, 6, 0.6, 1, 9, 7 };
	std::string arr3[3] = { "Hello world1", "Hello world3", "Hello world2" };
	for (auto var : arr) {
		char_tree.insert(var);
	}
	for (auto var : arr2) {
		double_tree.insert(var);
	}
	for (auto var : arr3) {
		string_tree.insert(var);
	}

	int* xptr = new int{0};
	int* yptr = new int{-4};
	intptr_tree.insert(xptr);
	intptr_tree.insert(yptr);


	char_tree.printTreeInfix();
	std::cout << std::endl;
	double_tree.printTreeInfix();
	std::cout << std::endl;
	string_tree.printTreeInfix();
	std::cout << std::endl;
	*xptr = -10;
	intptr_tree.printTreeInfix();
	std::cout << *xptr << "\t" << *yptr << std::endl;
	delete xptr;
	delete yptr;

	char* str = new char[6]{"Hello"};
	BinaryTree<char*> charptr_tree;
	charptr_tree.insert(str);
	charptr_tree.printTreeInfix();
	delete str;
}
