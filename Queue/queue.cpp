//This does hog memory
//For my Futureself make sure to fix this!!!
//For now I am too lazy and some parts are something I cant do right now!
//You need to make it so that the data return back to start of the array when resizing
//From your pastself, enjoy hell!!!!
// Also if its someone else you can still use this for logic but make sure to use a a shifting algorythem
// Or you can simply check my Circular Buffer which is Queue but better and used in real world programming!

#include <iostream>
#include "dynamicArray.cpp"

template <typename T>
class Queue{
	DynamicArray<T> array;
	size_t headPointer;
	size_t tailPointer;
	size_t size;
	
	public:
		void enqueue(T value){
			array.AddData(value);
		}
		void dequeue(){
			array.DeleteLast();
		}
		void display(){
			array.DisplayArray();
		}
}
int main(){

}
