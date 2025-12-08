#include <iostream>

template <typename T>
class dynamicCBuffer{
	size_t size{0};
	size_t maxSize{5};
	size_t headPointer{0};
	size_t tailPointer{0};
	T* buffer{nullptr};
	
	void resizeBuffer(){
		T* newBuffer = new T[maxSize * 2];
		for(size_t i{0}; i < size; i++){
			newBuffer[i] = buffer[i];
		}
		delete[] buffer;
		buffer = newBuffer;
		maxSize *= 2;
	}
	
	public:
	explicit dynamicCBuffer(){
		buffer = new T[maxSize];
	}
	
	void enqeue(T value){
		if(size == maxSize){
			resizeBuffer();
		}
		buffer[tailPointer] = value;
		tailPointer = (tailPointer + 1)% maxSize;
		size++;
	}
	
	T dequeue(){
		if(size == 0){
			throw std::runtime_error("Buffer is empty. Cannot dequeue."); //Exception is here 
		}
		T tempStorage = buffer[headPointer];
		headPointer = (headPointer + 1) % maxSize;
		size--;
		
		return tempStorage;
	}
	
	void display(){
		size_t tempPointer{headPointer};
			for(size_t i{0}; i < size;i++){
				std::cout<<buffer[tempPointer]<<" ";
				tempPointer = (tempPointer + 1 )% maxSize;
			}
			std::cout<<std::endl;
		}
	
	~dynamicCBuffer(){ //Destructor
		delete[] buffer;
	}
	dynamicCBuffer(const dynamicCBuffer& other){ //Copy Constructor
		size = other.size;
		maxSize = other.maxSize;
		headPointer = other.headPointer;
		tailPointer = other.tailPointer;
		buffer = new T[other.maxSize];
			for(size_t i{0};i < other.size;i++){
				buffer[i] = other.buffer[i];
			}
	}
	dynamicCBuffer& operator =(const dynamicCBuffer& other){
		delete[] buffer;
		
		size = other.size;
		maxSize = other.maxSize;
		headPointer = other.headPointer;
		tailPointer = other.tailPointer;
		buffer = new T[other.maxSize];
		
		for(size_t i{0};i < other.size;i++){
			buffer[i] = other.buffer[i];
		}
	}
	
	dynamicCBuffer(dynamicCBuffer& other) noexcept{
		size = other.size;
		maxSize = other.maxSize;
		headPointer = other.headPointer;
		tailPointer = other.tailPointer;
		buffer = other.buffer;
		other.buffer = nullptr;
	}
	
	dynamicCBuffer& operator =(dynamicCBuffer& other) noexcept{
		delete[] buffer;
		
		size = other.size;
		maxSize = other.maxSize;
		headPointer = other.headPointer;
		tailPointer = other.tailPointer;
		buffer = other.buffer;
		other.buffer = nullptr;
		return *this;
	}
};

int main(){
	dynamicCBuffer<int> p1;
	
	p1.enqeue(10);
	p1.enqeue(20);
	p1.enqeue(30);
	p1.enqeue(40);
	
	p1.display();
	
	std::cout<<std::endl;
	p1.dequeue();
	p1.display();
	
	p1.enqeue(60);
	p1.enqeue(70);
	std::cout<<std::endl;
	p1.display();
	
	p1.dequeue();
	p1.enqeue(80);
	p1.enqeue(90);
	p1.display();
}
