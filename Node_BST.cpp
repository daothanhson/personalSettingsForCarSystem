#include"Node_BST.h"

template<class T>
BST<T>::BST() {
	root = NULL;
}

template<class T>
BST<T>::~BST() {
	deleteTree();
}
template<class T>
void BST<T>::deleteTree() {
	deleteTree(root);
}
template<class T>
void BST<T>::deleteTree(Node<T>* pNode) {
	if (pNode != NULL) {
		deleteTree(pNode->left);
		deleteTree(pNode->right);
		delete pNode;
	}
}
template<class T>
Node<T>* BST<T>::createNode(T* data) {
	Node<T>* node = new Node<T>;
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}
template<class T>
void BST<T>::insertNode(T* data) {
	if (root != NULL) {
		insertNode(data, root);
	}
	else {
		root = createNode(data);
	}
}
template<class T>
void BST<T>::insertNode(T* data, Node<T>* pNode) {
	if (data->getKeyNum() < pNode->data->getKeyNum()) {
		if (pNode->left != NULL) {
			insertNode(data, pNode->left);
		}
		else {
			pNode->left = createNode(data);
		}
	}
	else if(data->getKeyNum() >=pNode->data->getKeyNum()){
		if (pNode->right != NULL) {
			insertNode(data, pNode->right);
		}
		else {
			pNode->right = createNode(data);
		}
	}
}

template<class T>
Node<T>* BST<T>::searchNodeByKey(string key) {
	return searchNodeByKey(key, root);
}

template<class T>
Node<T>* BST<T>::searchNodeByKey(string key, Node<T>* pNode) {
	if (pNode != NULL) {
		if (pNode->data->getKeyNum() == key) {
			return pNode;
		}
		else {
			if (key < pNode->data->getKeyNum()) {
				return searchNodeByKey(key, pNode->left);
			}
			else {
				return searchNodeByKey(key, pNode->right);
			}
		}
	}
	else {
		return NULL;
	}
}

template<class T>
int BST<T>::sizeTree(Node<T>* pNode) {
	if (pNode == NULL)
		return 0;
	else
		return(sizeTree(pNode->left) + 1 + sizeTree(pNode->right));
}
template<class T>
int BST<T>::sizeTree() {
	return sizeTree(root);
}
template<class T>
vector<Node<T>*> BST<T>::searchNodeByName(string name) {
	vNode.clear();
	searchNodeByName(name, root);
	return vNode;
}
template<class T>
void BST<T>::searchNodeByName(string name, Node<T>* pNode) {
	if (pNode != NULL) {
		if (pNode->data->getCarName() == name) {
			vNode.push_back(pNode);
		}
		searchNodeByName(name, pNode->left);
		searchNodeByName(name, pNode->right);
	}
}

template<class T>
vector<Node<T>*> BST<T>::sortNodeByName() {
	this->vNode.clear();
	sortNodeByName(root);
	Node<T>* temp;
	for (size_t i = 0; i < this->vNode.size() - 1; i++)
	{
		for (size_t j = 0; j < this->vNode.size() - 1; j++)
		{
			if (this->vNode[j]->data->getCarName() > this->vNode[j + 1]->data->getCarName())
			{
				temp = this->vNode[j];
				this->vNode[j] = this->vNode[j + 1];
				this->vNode[j + 1] = temp;
			}
		}
	}
	return vNode;
}
template<class T>
void BST<T>::sortNodeByName(Node<T>* pNode)
{
	if (pNode != NULL) {
		vNode.push_back(pNode);
		sortNodeByName(pNode->left);
		sortNodeByName(pNode->right);
	}
}
template<class T>
void BST<T>::saveDataNode() {
	ofstream file1("Setting.txt");
	try {
		if (file1.is_open()) {
			saveDataNode(root, file1);
			
		}
		else {
			throw exception();	//throw out the warning
		}
	}
	catch (...) {
		cerr << "Unable to open file to write " << "Setting.txt" << endl;
	}
}
template<class T>
void BST<T>::saveDataNode(Node<T>* pNode, ofstream& file) {
	if (root != NULL) {
		if (pNode->left != NULL) {
			saveDataNode(pNode->left, file);
		}
		file << "Common:" << pNode->data->getCarName() << "," << pNode->data->getEmail() << ","
			<< pNode->data->getKeyNum() << "," << pNode->data->getODO() << "," << pNode->data->getRemindService()
			<< ";" << "General:" << pNode->data->getGeneral()->getTimezone() << "," << pNode->data->getGeneral()->getLanguage()
			<< ";" << "Sound:" << pNode->data->getSound()->getCallVolumeLevel() << "," << pNode->data->getSound()->getMediaVolumeLevel()
			<< "," << pNode->data->getSound()->getNavigationVolumeLevel() << "," << pNode->data->getSound()->getNotificationVolumeLevel()
			<< ";" << "Display:" << pNode->data->getDisplay()->getLightLevel() << "," << pNode->data->getDisplay()->getScreenLightLevel()
			<< "," << pNode->data->getDisplay()->getTapLoLightLevel() << ";" << endl;
		if (pNode->right != NULL) {
			saveDataNode(pNode->right, file);
		}
	}
	else {
		cout << "the tree is empty" << endl;
	}
}
template<class T>
void BST<T>::inorder(int type) {
	inorder(type, root);
	cout << "\n";
}
template<class T>
void BST<T>::inorder(int type, Node<T>* leaf) {
	if (leaf != NULL) {
		switch (type)
		{
		case 1:
			inorder(1, leaf->left);
			leaf->data->outputInfor();
			leaf->data->getDisplay()->outputInforDisplay();
			cout << endl;
			inorder(1, leaf->right);
			break;
		case 2:
			inorder(2, leaf->left);
			leaf->data->outputInfor();
			leaf->data->getSound()->outputInforSound();
			cout << endl;
			inorder(2, leaf->right);
			break;
		case 3:
			inorder(3, leaf->left);
			leaf->data->outputInfor();
			leaf->data->getGeneral()->outputInforGeneral();
			inorder(3, leaf->right);
			break;
		default:
			break;
		}
	}
}
