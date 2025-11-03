#include <iostream>

template <typename T>
struct Node{
	T data{0};
	
	Node<T>* leftPointer{nullptr};
	Node<T>* rightPointer{nullptr};
};

template<typename T>
class BinaryTree{
	Node<T>* root{nullptr};
	
	bool inOrderInsertion(Node<T>* current, Node<T>* tempPointer){ //This fked up my mind!!!
		if(tempPointer->leftPointer == nullptr){
			tempPointer->leftPointer =  current;
			return true;
		}else if(tempPointer-> rightPointer == nullptr){
			tempPointer->rightPointer = current;
			return true;
		}
		if(inOrderInsertion(current, tempPointer->leftPointer)){
			return true;
		}if(inOrderInsertion(current, tempPointer->rightPointer)){
			return true;
		}
		return false;
	}
	/*void inOrderTraversal(Node<T>* tempPointer){ //This works but too leanthy
		std::cout<< tempPointer->data <<std::endl;
		if((tempPointer->rightPointer == nullptr) && (tempPointer->leftPointer == nullptr)){
			return;
		}if(tempPointer->rightPointer == nullptr){
			inOrderTraversal(tempPointer->leftPointer);
			return;
		}
		if(tempPointer->leftPointer == nullptr){
			inOrderTraversal(tempPointer->rightPointer);
			return;
		}
		inOrderTraversal(tempPointer->rightPointer);
		inOrderTraversal(tempPointer->leftPointer);
	}*/
	
	void inOrderTraversal(Node<T>* tempPointer){
		if(tempPointer == nullptr) return;
		
		inOrderTraversal(tempPointer->leftPointer);
		std::cout<< tempPointer->data <<std::endl;
		inOrderTraversal(tempPointer->rightPointer);
	}
	
	bool inOrderDelete(){
		
	}
	
	public:
		//BinaryTree : root(nullptr) {} //This is a constructor!
		
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
		void removeValue(T value){
			
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
}
