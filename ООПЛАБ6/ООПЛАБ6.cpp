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
	void printInfix();
private:
	T data;
	TreeNode<T>* left;
	TreeNode<T>* right;
};

template <class T>
class Tree {
public:
	Tree();
	~Tree();
	void insert(T);
	void printInfix();
private:
	TreeNode<T>* root;
	void printInfixHelper(TreeNode<T>*);
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
	}
	TreeNode<T>* temp = root;
	while (temp) {
		if (data < temp->get_data()) {
			temp = temp->left;
		}
		else {
			temp = temp->right;
		}
	}
	temp = new TreeNode<T> (data);
}

template <typename T>
Tree<T>::~Tree() {
}

template <typename T>
void Tree<T>::printInfix() {
	printInfixHelper(root)
}

template<class T>
void Tree<T>::printInfixHelper(TreeNode<T>* currentNode) {
	if (currentNode) {
		currentNode->printInfixHelper(currentNode->left);
		std::cout << root->data << "\t";
		currentNode->printInfixHelper(currentNode->right);
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
	delete left;
	delete right;
}

template<typename T>
T TreeNode<T>::get_data() const {
	return data;
}


int main()
{
	Tree <int> tree;
	tree.insert(6);
	tree.printInfix();
}
