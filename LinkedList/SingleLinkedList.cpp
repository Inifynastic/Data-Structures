#include <iostream>
// Implemented Rule of 5 and Raw Pointers
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
		
		void InsertAtAIndex(const size_t& Index, const T& Dat){
			if(HeadPointer == nullptr){
				HeadPointer = new Node<T>;
				HeadPointer->Data = Dat;
				HeadPointer->NextNode = nullptr;
				return;
			}
			if(Index == 0){
				InsertAtTheHead(Dat);
				return;
			}
			Node<T>* TempPointer = HeadPointer;
			Node<T>* CurPointer{nullptr};
			Node<T>* PrevPointer{nullptr};
			int i{0};
			do{
				if(TempPointer == nullptr){
					std::cout<<"Out of Bound!"<<std::endl;
					return;
				}
				PrevPointer = TempPointer;
				TempPointer = TempPointer->NextNode;
				i++;
			}while(i != Index - 1);
					
			CurPointer = new Node<T>;
			CurPointer->Data = Dat;
			CurPointer->NextNode = TempPointer;
			
			PrevPointer->NextNode = CurPointer;
		}
		
		void DeleteAtAIndex(const size_t& Index){
			
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
		
		// Rule of 5
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
	
	p1.InsertAtTheHead(7);
	
	p1.DisplatList();
	
	
	p1.InsertAtAIndex(0, 60);
	p1.DisplatList();

}
