#include <iostream>
#include "DynamicArray.hpp"
//This thing is Abstrated as hell check DynamicArray.hpp for core logic!

tempate <typename T>
class Stack{
	DynamicArray<T> Array;
	
	public:
	
	void push(T Vaue){
		Array.AddData(Value);
	}
	
	void pop(){
		Array.DeleteLast();
	}
	void DisplayTop(){
		Array.DispalyTop();
	}
}

int main(){

}
