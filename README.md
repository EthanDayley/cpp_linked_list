# This is a basic implementation of the LinkedList in c++

## BASIC USAGE:
```c++
	void display(LinkedList<int> list) {
		std::cout << "size: " << list.size() << std::endl;
		for (int i = 0; i < list.size(); i++) {
			std::cout << list[i] << ' ';
		}   
		std::cout << std::endl;
	}
	  int main() {
		//Node test
		Node<int> * n = new Node<int>;
		Node<int> * n2 = new Node<int>;
		n->value = 5;
		n->next = n2;
		LinkedList<int> list;
		list.push_forward(2);
		list.push_forward(1);
		list.push_back(3);
		list.push_back(4);
		display(list);
		list.erase(0);
		display(list);
		list.erase(1, list.size()-1);
		display(list);
		list.push_back(4);
		list.insert(3, 1);
		list.push_forward(0);
		list.setIndex(1, 0);
		display(list);
	}
```
## this will display the following:
size: 4

1 2 3 4 

size: 3

2 3 4 

size: 1

2 

size: 4

1 2 3 4 
