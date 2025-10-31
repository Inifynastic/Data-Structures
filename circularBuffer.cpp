// I could have build my own exception handling system but for now I am learning data structures and I care about my sanity.

#include <iostream>

template <typename T>
class circularBuffer{
	size_t size{0};
	size_t capacity{0};
	size_t headPointer{0};
	size_t tailPointer{0};
	T* buffer{0};
	
	public:
		circularBuffer(const size_t& Size){
			buffer = new T[Size];
			capacity = Size;
		}
		
		void enqueue(T value){
			if(size == capacity){
				std::cout<<"Buffer is full!"<<std::endl;
				return;
			}
			buffer[tailPointer] = value;
			tailPointer = (tailPointer + 1)%capacity;
			size++;
		}
		
		T dequeue(){
			if(size == 0){
				throw std::runtime_error("Buffer is empty. Cannot dequeue."); //Exception is here 
			}
			T tempStorage = buffer[headPointer];
			headPointer = (headPointer + 1)%capacity;
			size--;
			
			return tempStorage;
		}
		
		void display(){
		size_t tempPointer{headPointer};
			for(size_t i{0}; i < size;i++){
				std::cout<<buffer[tempPointer]<<" ";
				tempPointer = (tempPointer + 1 )% capacity;
			}
			std::cout<<std::endl;
		}
		
		T peak(){
			if(size == 0){
				throw std::runtime_error("Buffer is empty. Cannot Peak!");
			}
			return buffer[headPointer];
		}
		
		~circularBuffer(){
			delete[] buffer;
		}
		
		circularBuffer(const circularBuffer& other){
			buffer = new T[other.capacity];
			for(size_t i{0};i < other.capacity;i++){
				buffer[i] = other.buffer[i];
			}
			size = other.size;
			capacity = other.capacity;
			headPointer = other.headPointer;
			tailPointer = other.tailPointer;
		}
		circularBuffer& operator =(const circularBuffer& other){
			if(this == &other){
				return* this;
			}
			for(size_t i{0};i < other.capacity;i++){
				buffer[i] = other.buffer[i];
			}
			size = other.size;
			capacity = other.capacity;
			headPointer = other.headPointer;
			tailPointer = other.tailPointer;
			return* this;
		}
		circularBuffer(circularBuffer&& other) noexcept{
			delete[] buffer;
			buffer = other.buffer;
			
			size = other.size;
			capacity = other.capacity;
			headPointer = other.headPointer;
			tailPointer = other.tailPointer;
			
			other.buffer = nullptr;
			other.size = 0;
			other.headPointer = 0;
			other.tailPointer = 0;
			other.capacity = 0;
		}
		circularBuffer& operator =(circularBuffer&& other) noexcept{
			if(this == &other){
				return* this;
			}
			delete[] buffer;
			buffer = other.buffer;
			
			capacity = other.capacity;
			headPointer = other.headPointer;
			tailPointer = other.tailPointer;
			
			other.buffer = nullptr;
			other.size = 0;
			other.headPointer = 0;
			other.tailPointer = 0;
			other.capacity = 0;
			return* this;
		}
};

int main(){
	circularBuffer<int> p1(5);
	
	p1.enqueue(10);
	p1.enqueue(20);
	p1.enqueue(30);
	p1.enqueue(40);
	
	p1.display();
	
	std::cout<<std::endl;
	p1.dequeue();
	p1.display();
	
	p1.enqueue(60);
	p1.enqueue(70);
	std::cout<<std::endl;
	p1.display();
	
	p1.dequeue();
	p1.enqueue(80);
	p1.enqueue(90);
	p1.display();
	
	circularBuffer<int> p1(5);
}
