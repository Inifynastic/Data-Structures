#include <iostream> 

template <typename Tipe>
class DynamicArray{
	private:
		Tipe* Data{nullptr};
		size_t Size{0};
		size_t MaxSize{5};
	
	public:
		explicit DynamicArray(){
			Data = new Tipe[5];
		}
		
		void AddData(const Tipe& Value){
			if(!(Size < MaxSize)){
				ResizeArray();
			}
			*(Data + Size) = Value;
			Size++;
		}
		
		void ResizeArray(){
			Tipe* NewData = new Tipe[ MaxSize * 2];
			for(size_t i{0}; i < MaxSize; i++){
				NewData[i] = Data[i];
			}
			delete[] Data;
			Data = NewData;
			MaxSize *= 2;
		}
		void DeleteLast(){
			Data[Size] = 0;
			Size--;
		}
		
		void DisplayArray(){
			for(size_t i{0}; i < Size; i++){
			std::cout<< *(Data + i) <<" ";
			}
			std::cout<<std::endl;
		}
		void DispalyTop(){
			std::cout<<Data[Size];
		}
		
		  ~DynamicArray() { //Custom Destructor [Rule of 3 Part One]
			delete[] Data;
		}
		
		DynamicArray(const DynamicArray& OldArray){ //Copy Constructor [Rule of 3 Part 2]
			Size = OldArray.Size;
			MaxSize = OldArray.MaxSize;
			Data = new Tipe[MaxSize];
			
			for(size_t i{0}; i < Size; i++){
				Data[i] = OldArray.Data[i];
			}
		}
		DynamicArray& operator =(const DynamicArray& OldArray){ //Copy Assignment Operator. [Rule of 3 Part 3]
			if(this == &OldArray){
				return *this;
			}
			delete[] this->Data;
			this->Data = new Tipe[OldArray.MaxSize];
			this->Size = OldArray.Size;
			this->MaxSize = OldArray.MaxSize;
			
			for(size_t i{0}; i < Size; i++){
				this->Data[i] = OldArray.Data[i];
			}
			return *this;
		}
		
		DynamicArray(DynamicArray&& Other) noexcept{
			Size = Other.Size;
			MaxSize = Other.MaxSize;
			Data = Other.Data;
			
			Other.Size = 0;
			Other.MaxSize = 0;
			Other.Data = nullptr;
		}
		
		DynamicArray& operator =(DynamicArray&& Other) noexcept{
			if(this == &Other){
				return *this;
			}
			delete[] Data;
			
			Size = Other.Size;
			MaxSize = Other.MaxSize;
			Data = Other.Data;
			
			Other.Data = nullptr;
			Other.Size = 0;
			Other.MaxSize = 0;
			
			return *this;
		}
};
