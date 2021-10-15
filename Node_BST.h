#include<iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;

template<class T>
class Node {
public:
	T* data;
	Node* left;
	Node* right;
};

template<class T>
class BST {
private:
	Node<T>* root;
	vector<Node<T>*> vNode;
	Node<T>* createNode(T* data);						// create new Node
	void insertNode(T* data, Node<T>* pNode);			// add node to tree
	void saveDataNode(Node<T>* pNode, ofstream& file);  // save data to file (Setting.txt)
	Node<T>* searchNodeByKey(string key, Node<T>* pNode);
	void searchNodeByName(string name, Node<T>* pNode);
	void deleteTree(Node<T>* leaf);
	int sizeTree(Node<T>* pNode);
	void sortNodeByName(Node<T>* pNode);
	void inorder(int type, Node<T>* leaf);
public:
	BST();
	~BST();
	void insertNode(T* data);
	vector<Node<T>*>sortNodeByName();
	void saveDataNode();
	Node<T>* searchNodeByKey(string key);
	void deleteTree();
	int sizeTree();
	vector<Node<T>*>searchNodeByName(string name);
	void inorder(int type);
};