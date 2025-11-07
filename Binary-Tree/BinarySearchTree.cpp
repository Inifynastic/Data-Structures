//I just modifed binary tree into BST LMAO THIS WAS SO MUCH EASIER!!!!

#include <iostream>

template <typename T>
struct Node{
	T data{};
	
	Node<T>* leftPointer{nullptr};
	Node<T>* rightPointer{nullptr};
};

template<typename T>
class BinaryTree{
	Node<T>* root{nullptr};
	
	bool inOrderInsertion(Node<T>* current, Node<T>* tempPointer){
		if(current->data < tempPointer->data){
			if(!tempPointer->leftPointer){
				tempPointer->leftPointer = current;
				return true;
			}else{
				return inOrderInsertion(current, tempPointer->leftPointer);
			}
		}
		if(current->data > tempPointer->data){
			if(!tempPointer->rightPointer){
				tempPointer->rightPointer = current;
				return true;
			}else{
				return inOrderInsertion(current, tempPointer->rightPointer);
			}
		}
		return false;
	}
	
	void inOrderTraversal(Node<T>*& tempPointer){
		if(tempPointer == nullptr) return;
		
		inOrderTraversal(tempPointer->leftPointer);
		std::cout<< tempPointer->data <<std::endl;
		inOrderTraversal(tempPointer->rightPointer);
	}
	
	bool inOrderTraversal(Node<T>*& tempPointer,const T& value){
		if(tempPointer == nullptr) return false;
		
		if(value == tempPointer->data){
			std::cout<<"Found! " << tempPointer->data << std::endl;
			return true;
		}
		
		if(value < tempPointer->data){
			return inOrderTraversal(tempPointer->leftPointer, value);
		}else{
			return inOrderTraversal(tempPointer->rightPointer, value);
		}
		return false;
	}
	
	void inOrderDelete(const T& value, Node<T>*& tempPointer){ 
		if(!tempPointer) return;
		if(tempPointer->data == value){
			if(!tempPointer->leftPointer && !tempPointer->rightPointer){
				delete tempPointer;
				tempPointer = nullptr;
				return;
			}
			if(!tempPointer->leftPointer && tempPointer->rightPointer){
				Node<T>* temp{tempPointer->rightPointer};
				delete tempPointer;
				tempPointer = temp;
				return;
			}
			if(tempPointer->leftPointer && !tempPointer->rightPointer){
				Node<T>* temp{tempPointer->leftPointer};
				delete tempPointer;
				tempPointer = temp;
				return;
			}
			if(tempPointer->leftPointer && tempPointer->rightPointer){
				tempPointer->data = deleteLeafNode(tempPointer);
				return;
			}
				
		}
		if(value < tempPointer->data){
			inOrderDelete(value, tempPointer->leftPointer);
		}else{
			inOrderDelete(value, tempPointer->rightPointer);
		}
		return;
	}
	T deleteLeafNode(Node<T>*& tempPointer){
		if(!tempPointer->leftPointer && !tempPointer->rightPointer){
			T DataStore = tempPointer->data;
			delete tempPointer;
			tempPointer = nullptr;
			return DataStore;
		}
		return deleteLeafNode(tempPointer->leftPointer);
	}
	
	void destroy(Node<T>*& current){
		if(current){
			if(current->leftPointer) destroy(current->leftPointer);
			if(current->rightPointer) destroy(current->rightPointer);
			delete current;
		}	
	}
	
	void deepCopy(Node<T>*& current, Node<T>*& otherRoot){
		if(otherRoot){
			if(otherRoot->leftPointer){
				current->leftPointer = new Node<T>;
				current->leftPointer->data = otherRoot->leftPointer->data;
			 }
			if(otherRoot->rightPointer){
				current->rightPointer = new Node<T>;
				current->rightPointer->data = otherRoot->rightPointer->data;
			 }
			
			deepCopy(current->leftPointer, otherRoot->leftPointer);
			deepCopy(current->rightPointer, otherRoot->rightPointer);
		}
		return;
	}
	
	public:
		BinaryTree(){
			root = nullptr;
		}
		
		void insertNode(T value){
			Node<T>* tempPointer;
			tempPointer = new Node<T>;
			tempPointer->data = value;
			
			if(root == nullptr){
				root = tempPointer;
				return;
			}
			inOrderInsertion(tempPointer, root);
		}
		
		void display(){
			inOrderTraversal(root);
		}
		
		void searchTree(const T& value){
			bool flag = inOrderTraversal(root, value);
			if(!flag){
				std::cout<<"Value not found!"<<std::endl;
			}
		}
		
		void removeValue(T value){
			if(root == nullptr) throw std::runtime_error("The Tree is empty!");
			inOrderDelete(value, root);
			
		}
		
		~BinaryTree(){ //Destructor
			destroy(root);
		}
		
		BinaryTree(const BinaryTree& other){ //Copy Constructor
			root = new Node<T>;
			root->data = other.root->data;
			deepCopy(root, other.root);
		}
		BinaryTree& operator =(const BinaryTree& other){ //Copy Assignment Operator
			if(!(other.root == root)){
				destroy(root);
				root = new Node<T>;
				root->data = other.root->data;
			}
			return* this;
		}
		BinaryTree(BinaryTree&& other) noexcept{ //Move Constructor
			root = other.root;
			other.root = nullptr;
		}
		BinaryTree& operator =(BinaryTree&& other) noexcept{ //Move Assignemnt Operator
			if(other.root == root) return* this;
			destroy(root);
			root = other.root;
			other.root = nullptr;
			return* this;
		}
};

int main(){
	BinaryTree<int> c1;
	c1.insertNode(1);
	c1.insertNode(2);
	c1.insertNode(3);
	c1.insertNode(4);
	c1.insertNode(5);
	c1.insertNode(6);
	c1.insertNode(7);
	c1.display();
	
	c1.searchTree(7);
	
	std::cout<<std::endl;
	
	c1.removeValue(5);
	c1.removeValue(3);
	c1.removeValue(1);
	c1.removeValue(4);
	c1.display();
	
	
	BinaryTree<int> c3;
	BinaryTree<int> c2;
	c2 = c1;
	c2.display();
}
