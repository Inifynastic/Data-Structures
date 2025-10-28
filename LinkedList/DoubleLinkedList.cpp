#include <iostream>
// Implemented Rule of 5 and Raw Pointers
template <typename T>
struct Node{
	
	T Data;
	Node<T>* NextNode{nullptr};
	Node<T>* PrevNode{nullptr};
};



template <typename T>
class LinkedList{
	Node<T>* HeadPointer{nullptr};
	size_t Size{0};
	
	public:
		void InsertAtTheHead(const T& Dat){
			Node<T>* TempPointer = HeadPointer;
			HeadPointer = new Node<T>;
			HeadPointer->Data = Dat;
			HeadPointer->NextNode = TempPointer;
		}
		
		void InsertAtTheTail(const T& Dat){
			if(HeadPointer == nullptr){
				HeadPointer = new Node<T>;
				HeadPointer->Data = Dat;
				HeadPointer->NextNode = nullptr;
				return;
			}
			Node<T>* TempPointer = HeadPointer;
			while(TempPointer->NextNode != nullptr){
				TempPointer = TempPointer->NextNode;
			}
			TempPointer->NextNode = new Node<T>;
			TempPointer = TempPointer->NextNode;
			TempPointer->Data = Dat;
			TempPointer->NextNode = nullptr;
		}
}

		// For my Future Self. Please complete this!!!!
