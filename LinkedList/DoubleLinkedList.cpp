#include <iostream>
// Implemented Rule of 5 and Raw Pointers
template <typename T>
struct Node{
	
	T data;
	Node<T>* nextNode{nullptr};
	Node<T>* prevNode{nullptr};
};



template <typename T>
class LinkedList{
	Node<T>* headPointer{nullptr};
	Node<T>* tailPointer{nullptr};
	
	public:
	
		LinkedList(){
			headPointer = nullptr;
		}
		
		void InsertAtTheHead(const T& value){
			Node<T>* tempPointer = headPointer;
			headPointer = new Node<T>;
			
			headPointer->data = value;
			tempPointer->prevNode = headPointer;
			headPointer->nextNode = tempPointer;
			
			if(!headPointer->nextNode){
				tailPointer = headPointer;
			} 
		}
		
		void InsertAtTheTail(const T& value){
			if(!headPointer){
				headPointer = new Node<T>;
				tailPointer = headPointer;
				headPointer->data = value;
				headPointer->nextNode = nullptr;
				headPointer->prevNode = nullptr;
				return;
			}
			Node<T>* tempPointer = new Node<T>;
			tempPointer->data =value;
			tempPointer->nextNode = nullptr;
			tempPointer->prevNode = tailPointer;
			tailPointer->nextNode = tempPointer;
			tailPointer =tempPointer;
		}
		
		void InsertAtAPoint(const T& value,size_t location){
			Node<T>* current = headPointer;
			for(size_t i{0}; i < location; i++){
				if(!current) return;
				if(i == location){
					Node <T>* tempPointer= new Node<T>;
					tempPointer->data = value;
					tempPointer->prevNode = current->prevNode;
					tempPointer->nextNode = current;
					
					current->nextNode->prevNode = tempPointer;
					current = tempPointer;
					return;
				}
				current = current ->nextNode;
				
			}
		}
		
		void DeleteValue(const T& value){
			Node<T>* current = headPointer;
			
			while(!current){
				if(current->data == value){
					current->prevNode->nextNode = current->nextNode;
					current->nextNode->prevNode = current ->prevNode;
					
					delete current;
					
					return;
				}
				current = current->nextNode;
			}
			
		}
		
		void DisplatList(){
			if(!headPointer) return;
			Node<T>* tempPointer = headPointer;
			while(tempPointer != nullptr){
				std::cout<<tempPointer->data << " ";
				tempPointer = tempPointer->nextNode;
			}
			std::cout<<std::endl;
		}
		
		~LinkedList(){ //Destructor
			Node<T>* tempPointer{nullptr};
			while(headPointer != nullptr){
				tempPointer = headPointer;
				headPointer = headPointer->nextNode;
				delete tempPointer;
			}
		}
		
		LinkedList(const LinkedList& oldList){ //Copy Constructor
			Node<T>* tempPointer{oldList.headPointer};
			while(!tempPointer){
				
				InsertAtTheTail(tempPointer->data);
				
				tempPointer = tempPointer->nextNode;
			}
		}
		
		LinkedList& operator=(const LinkedList& oldList){ //Copy Assignemnt Opeator
			Node<T>* tempPointer{nullptr};
			if(this == &oldList){
				return *this;
			}
			while(!headPointer){
				tempPointer = headPointer;
				headPointer = headPointer->nextNode;
				delete tempPointer;
			}
			
			tempPointer = oldList.headPointer;
			while(tempPointer != nullptr){
				
				InsertAtTheTail(tempPointer->data);
				
				tempPointer = tempPointer->nextNode;
			}
			return *this;
		}
		
		LinkedList( LinkedList&& oldList) noexcept{ //Move Operator
			headPointer = oldList.headPointer;
			oldList.headPointer = nullptr;
		}
		
		LinkedList& operator=( LinkedList&& oldList) noexcept{ //Move Assignemnt Opeator
			Node<T>* tempPointer{nullptr};
			tempPointer = headPointer;
			headPointer = oldList.headPointer;
			oldList.headPointer = tempPointer;
			return *this;
		}
};

int main(){
	LinkedList<int> p1;
	
	p1.InsertAtTheTail(1);
	p1.InsertAtTheTail(2);
	p1.InsertAtTheTail(3);
	p1.InsertAtTheTail(4);
	p1.InsertAtTheTail(5);
	p1.InsertAtTheTail(6);

	
	p1.DisplatList();
}
