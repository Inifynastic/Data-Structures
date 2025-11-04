//This is Recursive hell!!!!! Everything has recursion
// Before writing this I thought recursions are useless and now I hate myself becuase of recursion and how useful it is
// Also I regret doing this but I am way too far in to quit now!

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
	bool DeleteLeafNode(Node<T>* tempPointer, Node<T>* swapPointer){ // tempPointer = the pointer we wanna delete(or root) and swampPointer = the pointer we wanna delete
		if((tempPointer->leftPointer == nullptr) && (tempPointer-> rightPointer == nullptr)){
			swapPointer->data = tempPointer->data;
			delete tempPointer;
			return true;
		}
		if(DeleteLeafNode(tempPointer->leftPointer)){
			return true;
		}if(DeleteLeafNode(tempPointer->rightPointer)){
			return true;
		}
		return false;
	}
	
	void inOrderTraversal(Node<T>* tempPointer){
		if(tempPointer == nullptr) return;
		
		inOrderTraversal(tempPointer->leftPointer);
		std::cout<< tempPointer->data <<std::endl;
		inOrderTraversal(tempPointer->rightPointer);
	}
	
	void reattach(Node<T>* tempPointer, Node<T>* parentNode){ // This is gonna be next level pain in the ass <3
		if(!parentNode){ //Root pointer case
			DeleteLeafNode(tempPointer, tempPointer);
			return;
		}if((!tempPointer->leftPointer) && (!tempPointer->rightPointer)){
			DeleteLeafNode(tempPointer, tempPointer);
			return;
		}if(!tempPointer->leftPointer){
			if(!parentNode->leftPointer){
				parentNode->leftPointer = tempPointer->leftPointer;
			}else{
				parentNode->rightPointer = tempPointer->leftPointer;
			}
			delete tempPointer;
			return;
		}if(!tempPointer->rightPointer){
			if(!parentNode->leftPointer){
				parentNode->leftPointer = tempPointer->rightPointer;
			}else{
				parentNode->rightPointer = tempPointer->rightPointer;
			}
			delete tempPointer;
			return;
			}
	}
	
	bool inOrderDelete(const T& value, Node<T>* tempPointer){
		Node<T>* parentPointer{nullptr};
		if(tempPointer->leftPointer != nullptr){
			if(tempPointer->leftPointer->data == value){
				reattach(tempPointer, parentPointer);
				delete tempPointer->leftPointer;
				return true;
			}
		}if(tempPointer->rightPointer != nullptr){
			if(tempPointer->leftPointer->data == value){
				reattach(tempPointer, parentPointer);
				delete tempPointer->rightPointer;
				return true;
			}
		}
		if(inOrderDelete(value, tempPointer->leftPointer)){
			parentPointer = tempPointer;
			return true;
		}
		if(inOrderDelete(value, tempPointer->rightPointer)){
			parentPointer = tempPointer;
			return true;
		}
		return false;
	}
	
	void destroy(Node<T>* current){
		if(current){
			if(current->leftPointer) destroy(current->leftPointer);
			if(current->rightPointer) destroy(current->rightPointer);
			delete current;
		}	
	}
	
	void deepCopy(Node<T>* current, Node<T>* otherRoot){//current = root
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
		void removeValue(T value){
			if(root == nullptr){
				throw std::runtime_error("The Tree is empty!");
			}
			inOrderDelete(value, root);
			
		}
		
		~BinaryTree(){ //Destructor
			destroy(root);
		}
		
		BinaryTree(const BinaryTree& other){ //Copy Constructor
			if(!other.root) throw std::runtime_error("The Tree is Empty!");
			root = new Node<T>;
			root->data = other.root->data;
			deepCopy(root, other.root);
		}
		BinaryTree& operator =(const BinaryTree& other){ //Copy Assignment Operator
			if(!other.root) return* this;
			destroy(root);
			root = new Node<T>;
			root->data = other.root->data;
		}
		BinaryTree(BinaryTree&& other) noexcept{ //Move Constructor
			root = other.root;
			other.root = nullptr;
		}
		BinaryTree& operator =(BinaryTree&& other) noexcept{ //Move Assignemnt Operator
			delete root;
			root = other.root;
			other.root = nullptr;
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
	
	c1.removeValue(5);
	c1.display();
}
