#include <iostream>

template <typename T>
struct Node{
	
	T Data;
	Node<T>* NextNode{nullptr};
};


template <typename T>
class LinkedList{
	Node<T>* HeadPointer{nullptr};
	size_t Size{0};
	
	public:
		explicit LinkedList(){
			Size = 0;
		}
		
		void InsertAtTheHead(T Dat){
			Node<T>* TempPointer = HeadPointer;
			HeadPointer = new Node<T>;
			HeadPointer->Data = Dat;
			HeadPointer->NextNode = TempPointer;
		}
		
		void InsertAtTheTail(T Dat){
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
		
		void InsertAtAIndex(size_t Index, T Dat){
			
		}
		
		void DisplatList(){
			if(HeadPointer == nullptr){
				std::cout<<"List is Empty!"<<std::endl;
				return;
			}
			Node<T>* TempPointer = HeadPointer;
			while(TempPointer != nullptr){
				std::cout<<TempPointer->Data << " ";
				TempPointer = TempPointer->NextNode;
			}
			std::cout<<std::endl;
		}
};

int main(){
	LinkedList<int> p1;
	
	p1.AddNodeAtAss(1);
	p1.AddNodeAtAss(2);
	p1.AddNodeAtAss(3);
	p1.AddNodeAtAss(4);
	p1.AddNodeAtAss(5);
	p1.AddNodeAtAss(6);

	
	p1.DisplatList();
	
	p1.InsertAtTheFront(7);
	
	p1.DisplatList();

}
