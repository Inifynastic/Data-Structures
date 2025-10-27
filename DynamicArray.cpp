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
		
		void DisplayArray(){
			for(size_t i{0}; i < Size; i++){
			std::cout<< *(Data + i) <<" ";
			}
			std::cout<<std::endl;
		}
		
		void SearchArray(){
			// Fk this for now
		}
		
		  ~DynamicArray() {
			delete[] Data;
		}
		
		DynamicArray(const DynamicArray& OldArray){
			Size = OldArray.Size;
			MaxSize = OldArray.MaxSize;
			Data = new Tipe[MaxSize];
			
			for(size_t i{0}; i < Size; i++){
				Data[i] = OldArray.Data[i];
			}
		}
		DynamicArray& operator =(const DynamicArray& OldArray){ //Copy Assignment Operator.
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
		
	
};

int main(){
	DynamicArray<int> Joe;
	Joe.AddData(10);
	Joe.DisplayArray();
	Joe.AddData(20);
	Joe.AddData(40);
	Joe.AddData(50);
	Joe.AddData(60);
	Joe.AddData(70);
	Joe.AddData(80);
	Joe.AddData(90);
	Joe.AddData(100);

	Joe.DisplayArray();
	
	DynamicArray<int> JoeMama(Joe);
	
	std::cout<<std::endl;
	
	JoeMama.DisplayArray();
	
	DynamicArray Phil = Joe;
	
	
}
