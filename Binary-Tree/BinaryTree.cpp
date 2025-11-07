//This is Recursive hell!!!!! Everything has recursion
// Before writing this I thought recursions are useless and now I hate myself becuase of recursion and how useful it is
// Also I regret doing this but I am way too far in to quit now!

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
	void inOrderTraversal(Node<T>*& tempPointer){
		if(tempPointer == nullptr) return;
		
		inOrderTraversal(tempPointer->leftPointer);
		std::cout<< tempPointer->data <<std::endl;
		inOrderTraversal(tempPointer->rightPointer);
	}
	
	void inOrderDelete(const T& value, Node<T>*& tempPointer){ // 3 FUCKING DAYS OF PAIN LATER I DID IT!!!!
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
		inOrderDelete(value, tempPointer->leftPointer);
		inOrderDelete(value, tempPointer->rightPointer);
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
	
	void deepCopy(Node<T>*& current, Node<T>*& otherRoot){//current = root
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
