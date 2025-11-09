#include <iostream>
// Implemented Rule of 5 and Raw Pointers
template <typename T>
struct Node{
	
	T data;
	Node<T>* nextNode{nullptr};
};


template <typename T>
class LinkedList{
	Node<T>* headPointer{nullptr};
	
	public:
		LinkedList(){
			headPointer = nullptr;
		}
		
		void InsertAtTheHead(const T& dat){
			Node<T>* tempPointer = headPointer;
			headPointer = new Node<T>;
			headPointer->data = dat;
			headPointer->nextNode = tempPointer;
		}
		
		void InsertAtTheTail(const T& dat){
			if(headPointer == nullptr){
				headPointer = new Node<T>;
				headPointer->data = dat;
				headPointer->nextNode = nullptr;
				return;
			}
			Node<T>* tempPointer = headPointer;
			while(tempPointer->nextNode != nullptr){
				tempPointer = tempPointer->nextNode;
			}
			tempPointer->nextNode = new Node<T>;
			tempPointer = tempPointer->nextNode;
			tempPointer->data = dat;
			tempPointer->nextNode = nullptr;
		}
		
		void InsertAtAIndex(const size_t& index, const T& dat){
			if(headPointer == nullptr){
				headPointer = new Node<T>;
				headPointer->data = dat;
				headPointer->nextNode = nullptr;
				return;
			}
			if(index == 0){
				InsertAtTheHead(dat);
				return;
			}
			Node<T>* tempPointer = headPointer;
			Node<T>* CurPointer{nullptr};
			Node<T>* PrevPointer{nullptr};
			int i{0};
			do{
				if(tempPointer == nullptr){
					std::cout<<"Out of Bound!"<<std::endl;
					return;
				}
				PrevPointer = tempPointer;
				tempPointer = tempPointer->nextNode;
				i++;
			}while(i != index - 1);
					
			CurPointer = new Node<T>;
			CurPointer->data = dat;
			CurPointer->nextNode = tempPointer;
			
			PrevPointer->nextNode = CurPointer;
		}
		
		void DeleteAtAIndex(const size_t& index){
			if(headPointer == nullptr){
				std::cout<<"The LinkedList is empty."<<std::endl;
				return;
			}
			if(index == 0){
				std::cout<<"I will do this in future when I build a DeleteAtFront"<<std::endl;
				return;
			}
			Node<T>* tempPointer = headPointer;
			Node<T>* PrevPointer{nullptr};
			for(size_t i{0}; i< index - 1 ;i++){
				if(tempPointer == nullptr){
					std::cout<<"Out of Bound!"<<std::endl;
					return;
				}
				PrevPointer = tempPointer;
				tempPointer = tempPointer->nextNode;
			}
			PrevPointer->nextNode = tempPointer->nextNode;
			delete tempPointer;
		}
		
		void DisplatList(){
			if(headPointer == nullptr){
				std::cout<<"List is Empty!"<<std::endl;
				return;
			}
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
			while(tempPointer != nullptr){
				
				InsertAtTheTail(tempPointer->data);
				
				tempPointer = tempPointer->nextNode;
			}
		}
		
		LinkedList& operator=(const LinkedList& oldList){ //Copy Assignemnt Opeator
			Node<T>* tempPointer{nullptr};
			if(this == &oldList){
				return *this;
			}
			while(headPointer != nullptr){
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

template <typename T>
struct DNode{
	
	T data;
	T key;
	Node<T>* nextNode{nullptr};
};

template <typename T>
class DLinkedList{
	Node<T>* headPointer{nullptr};
	
	public:
		DLinkedList(){
			headPointer = nullptr;
		}
		
		void InsertAtTheHead(const T& dat){
			DNode<T>* tempPointer = headPointer;
			headPointer = new DNode<T>;
			headPointer->data = dat;
			headPointer->nextNode = tempPointer;
		}
		
		void InsertAtTheTail(const T& dat){
			if(headPointer == nullptr){
				headPointer = new DNode<T>;
				headPointer->data = dat;
				headPointer->nextNode = nullptr;
				return;
			}
			DNode<T>* tempPointer = headPointer;
			while(tempPointer->nextNode != nullptr){
				tempPointer = tempPointer->nextNode;
			}
			tempPointer->nextNode = new DNode<T>;
			tempPointer = tempPointer->nextNode;
			tempPointer->data = dat;
			tempPointer->nextNode = nullptr;
		}
		
		void InsertAtAIndex(const size_t& index, const T& dat){
			if(headPointer == nullptr){
				headPointer = new DNode<T>;
				headPointer->data = dat;
				headPointer->nextNode = nullptr;
				return;
			}
			if(index == 0){
				InsertAtTheHead(dat);
				return;
			}
			DNode<T>* tempPointer = headPointer;
			DNode<T>* CurPointer{nullptr};
			DNode<T>* PrevPointer{nullptr};
			int i{0};
			do{
				if(tempPointer == nullptr){
					std::cout<<"Out of Bound!"<<std::endl;
					return;
				}
				PrevPointer = tempPointer;
				tempPointer = tempPointer->nextNode;
				i++;
			}while(i != index - 1);
					
			CurPointer = new DNode<T>;
			CurPointer->data = dat;
			CurPointer->nextNode = tempPointer;
			
			PrevPointer->nextNode = CurPointer;
		}
		
		void DeleteAtAIndex(const size_t& index){
			if(headPointer == nullptr){
				std::cout<<"The LinkedList is empty."<<std::endl;
				return;
			}
			if(index == 0){
				std::cout<<"I will do this in future when I build a DeleteAtFront"<<std::endl;
				return;
			}
			DNode<T>* tempPointer = headPointer;
			DNode<T>* PrevPointer{nullptr};
			for(size_t i{0}; i< index - 1 ;i++){
				if(tempPointer == nullptr){
					std::cout<<"Out of Bound!"<<std::endl;
					return;
				}
				PrevPointer = tempPointer;
				tempPointer = tempPointer->nextNode;
			}
			PrevPointer->nextNode = tempPointer->nextNode;
			delete tempPointer;
		}
		
		void DisplatList(){
			if(headPointer == nullptr){
				std::cout<<"List is Empty!"<<std::endl;
				return;
			}
			DNode<T>* tempPointer = headPointer;
			while(tempPointer != nullptr){
				std::cout<<tempPointer->data << " ";
				tempPointer = tempPointer->nextNode;
			}
			std::cout<<std::endl;
		}
		
		~DLinkedList(){ //Destructor
			Node<T>* tempPointer{nullptr};
			while(headPointer != nullptr){
				tempPointer = headPointer;
				headPointer = headPointer->nextNode;
				delete tempPointer;
			}
		}
		
		DLinkedList(const DLinkedList& oldList){ //Copy Constructor
			Node<T>* tempPointer{oldList.headPointer};
			while(tempPointer != nullptr){
				
				InsertAtTheTail(tempPointer->data);
				
				tempPointer = tempPointer->nextNode;
			}
		}
		
		DLinkedList& operator=(const DLinkedList& oldList){ //Copy Assignemnt Opeator
			Node<T>* tempPointer{nullptr};
			if(this == &oldList){
				return *this;
			}
			while(headPointer != nullptr){
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
		
		DLinkedList(DLinkedList&& oldList) noexcept{ //Move Operator
			headPointer = oldList.headPointer;
			oldList.headPointer = nullptr;
		}
		
		DLinkedList& operator=(DLinkedList&& oldList) noexcept{ //Move Assignemnt Opeator
			Node<T>* tempPointer{nullptr};
			tempPointer = headPointer;
			headPointer = oldList.headPointer;
			oldList.headPointer = tempPointer;
			return *this;
		}
};
