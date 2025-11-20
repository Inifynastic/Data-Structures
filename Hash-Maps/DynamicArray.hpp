#include <iostream> 

template <typename T>
class DynamicArray{
	private:
		T* data{nullptr};
		size_t size{0};
		size_t maxSize{8};
		
		void ResizeArray(){
			T* newData = new T[ maxSize * 2];
			for(size_t i{0}; i < size; i++){
				newData[i] = data[i];
			}
			delete[] data;
			data = newData;
			maxSize *= 2;
		}
		
	public:
		explicit DynamicArray(){
			data = new T[8];
		}
		
		void addAtBack(const T& value){
			if(!(size < maxSize)){
				ResizeArray();
			}
			*(data + size) = value;
			size++;
		}
		
		
		void DeleteLast(){
			data[size] = 0;
			size--;
		}
		
		void DisplayArray(){
			for(size_t i{0}; i < size; i++){
			std::cout<< *(data + i) <<" ";
			}
			std::cout<<std::endl;
		}
		void DispalyTop(){
			std::cout<<data[size];
		}
		
		size_t length(){
			return size;
		}
		size_t capacity(){
			return maxSize;
		}
		
		T getIndex(size_t index){
			if(index >= maxSize){
				throw std::runtime_error("Invalid Arguement");
			}
			return data[index];
		}
		
		  ~DynamicArray() { //Custom Destructor [Rule of 3 Part One]
			delete[] data;
		}
		
		DynamicArray(const DynamicArray& oldArray){ //Copy Constructor [Rule of 3 Part 2]
			size = oldArray.size;
			maxSize = oldArray.maxSize;
			data = new T[maxSize];
			
			for(size_t i{0}; i < size; i++){
				data[i] = oldArray.data[i];
			}
		}
		DynamicArray& operator =(const DynamicArray& oldArray){ //Copy Assignment Operator. [Rule of 3 Part 3]
			if(this == &oldArray){
				return *this;
			}
			delete[] this->data;
			this->data = new T[oldArray.maxSize];
			this->size = oldArray.size;
			this->maxSize = oldArray.maxSize;
			
			for(size_t i{0}; i < size; i++){
				this->data[i] = oldArray.data[i];
			}
			return *this;
		}
		
		DynamicArray(DynamicArray&& other) noexcept{
			size = other.size;
			maxSize = other.maxSize;
			data = other.data;
			
			other.size = 0;
			other.maxSize = 0;
			other.data = nullptr;
		}
		
		DynamicArray& operator =(DynamicArray&& other) noexcept{
			if(this == &other){
				return *this;
			}
			delete[] data;
			
			size = other.size;
			maxSize = other.maxSize;
			data = other.data;
			
			other.data = nullptr;
			other.size = 0;
			other.maxSize = 0;
			
			return *this;
		}
};
