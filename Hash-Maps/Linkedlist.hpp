template <typename K, typename V>
struct DNode{
	
	V data;
	K key;
	DNode<K, V>* nextNode{nullptr};
};

template <typename K, typename V>
class DLinkedList{
	DNode<K, V>* headPointer{nullptr};
		
	public:
		explicit DLinkedList(){
			headPointer = nullptr;
		}
		
		void InsertAtTheHead(const V& value, const K& ke){
			DNode<K, V>* tempPointer = headPointer;
			headPointer = new DNode<K, V>;
			
			headPointer->data = value;
			headPointer->key= ke;
			headPointer->nextNode = tempPointer;
		}
		
		void InsertAtTheTail(const V& value, const K& ke){
			if(!headPointer){
				headPointer = new DNode<K, V>;
				headPointer->data = value;
				headPointer->key = ke;
				headPointer->nextNode = nullptr;
				return;
			}
			DNode<K, V>* tempPointer = headPointer;
			while(!tempPointer->nextNode){
				tempPointer = tempPointer->nextNode;
			}
			tempPointer->nextNode = new DNode<K, V>;
			tempPointer = tempPointer->nextNode;
			tempPointer->data = value;
			tempPointer->key = ke;
			tempPointer->nextNode = nullptr;
		}
		
		void InsertAtAIndex(const size_t& index, const V& value, const K& ke){
			if(!headPointer){
				headPointer = new DNode<K, V>;
				headPointer->data = value;
				headPointer->key = ke;
				headPointer->nextNode = nullptr;
				return;
			}
			if(index == 0){
				InsertAtTheHead(value);
				return;
			}
			DNode<K, V>* tempPointer = headPointer;
			DNode<K, V>* curPointer{nullptr};
			DNode<K, V>* prevPointer{nullptr};
			int i{0};
			do{
				if(tempPointer == nullptr){
					std::cout<<"Out of Bound!"<<std::endl;
					return;
				}
				prevPointer = tempPointer;
				tempPointer = tempPointer->nextNode;
				i++;
			}while(i != index - 1);
					
			curPointer = new DNode<K, V>;
			curPointer->data = value;
			curPointer->key = ke;
			curPointer->nextNode = tempPointer;
			
			prevPointer->nextNode = curPointer;
		}
		
		void DeleteAtAIndex(const size_t& index){
			if(!headPointer){
				std::cout<<"The LinkedList is empty."<<std::endl;
				return;
			}
			if(index == 0){
				std::cout<<"I will do this in future when I build a DeleteAtFront"<<std::endl;
				return;
			}
			DNode<K, V>* tempPointer = headPointer;
			DNode<K, V>* prevPointer{nullptr};
			for(size_t i{0}; i< index - 1 ;i++){
				if(!tempPointer){
					std::cout<<"Out of Bound!"<<std::endl;
					return;
				}
				prevPointer = tempPointer;
				tempPointer = tempPointer->nextNode;
			}
			prevPointer->nextNode = tempPointer->nextNode;
			delete tempPointer;
		}
		
		void DisplatList(){
			if(headPointer == nullptr){
				std::cout<<"List is Empty!"<<std::endl;
				return;
			}
			DNode<K, V>* tempPointer = headPointer;
			while(tempPointer){
				std::cout<<tempPointer->key << " : "<< tempPointer->data << std::endl;
				tempPointer = tempPointer->nextNode;
			}
			std::cout<<std::endl;
		}
		
		V getIndex(const K& ke){
			if(headPointer->key == ke){
				return headPointer->data;
			}
			
			size_t i{0};
			DNode<K, V>* tempPointer{headPointer};
			while(tempPointer){
				if(ke == tempPointer->key){
					return tempPointer->data;
				}
				tempPointer = tempPointer->nextNode;
			}
			throw std::runtime_error("Key not Found!");
		}
		
		~DLinkedList(){ //Destructor
			DNode<K, V>* tempPointer{nullptr};
			while(headPointer){
				tempPointer = headPointer;
				headPointer = headPointer->nextNode;
				delete tempPointer;
			}
		}
		
		DLinkedList(const DLinkedList& oldList){ //Copy Constructor
			DNode<K, V>* tempPointer{oldList.headPointer};
			while(tempPointer){
				
				InsertAtTheTail(tempPointer->data);
				
				tempPointer = tempPointer->nextNode;
			}
		}
		
		DLinkedList& operator=(const DLinkedList& oldList){ //Copy Assignemnt Opeator
			DNode<K, V>* tempPointer{nullptr};
			if(this == &oldList){
				return *this;
			}
			while(headPointer){
				tempPointer = headPointer;
				headPointer = headPointer->nextNode;
				delete tempPointer;
			}
			
			tempPointer = oldList.headPointer;
			while(tempPointer){
				
				InsertAtTheTail(tempPointer->data);
				
				tempPointer = tempPointer->nextNode;
			}
			return *this;
		}
		
		DLinkedList(DLinkedList&& oldList) noexcept{ //Move Operator
			headPointer = oldList.headPointer;
			oldList.headPointer = nullptr;
		}
		
		DLinkedList& operator=(DLinkedList&& oldList) noexcept{ //Move Assignemnt Opeator
			DNode<K, V>* tempPointer{nullptr};
			tempPointer = headPointer;
			headPointer = oldList.headPointer;
			oldList.headPointer = tempPointer;
			return *this;
		}
};
