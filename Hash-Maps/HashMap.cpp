#include <iostream>
#include "Linkedlist.hpp"
#include "DynamicArray.hpp"


template <typename K, typename V>
class HashMap{
	DynamicArray<DLinkedList<K, V>*>* BucketArray;
	size_t capacity{0};
	
	size_t HashFunction(const K& ke){
		return 0;
	}
	
	public:
		HashMap(){
			BucketArray = new DynamicArray<DLinkedList<K, V>*>;
			capacity = BucketArray->capacity();
			for(size_t i{0}; i < capacity -1; i++){
				BucketArray->addAtBack(new DLinkedList<K, V>);
			}
		}
	
	void InsertValue(const V& value ,const K& ke){
		size_t index;
		index = HashFunction(ke);
		DLinkedList<K, V>* bucket{BucketArray->getIndex(index)};
		bucket->InsertAtTheHead(value, ke);
		bucket->DisplatList();
		
	}
	void GetValue(const K& ke){
		size_t index = HashFunction(ke);
		DLinkedList<K, V>* bucket{BucketArray->getIndex(index)};
		std::cout<<bucket->getIndex(ke)<<std::endl;
		
	}
	
};

int main(){
	HashMap<int, int> p1;
	p1.InsertValue(0,3);
	p1.InsertValue(1,2);
	p1.InsertValue(2,1);
	p1.InsertValue(3,0);
	p1.GetValue(0);
}
