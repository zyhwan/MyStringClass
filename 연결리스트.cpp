#include<iostream>

struct Node
{
	int data;
	Node* next;

	Node(int value) : data(value), next(nullptr) { }
};

class LinkedList
{
private:
	Node* Head;
public:
	LinkedList() : Head(nullptr)
	{

	}
	~LinkedList()
	{
		Node* current = Head;
		while (current != nullptr)
		{
			Node* next = current->next;
			delete current;
			current = next;
		}
	}
	void AddNode(int value)
	{
		Node* newNode = new Node(value);
		newNode->next = Head;
		Head = newNode;
	}
	void Display()
	{
		Node* temp = Head;
		while (temp != nullptr)
		{
			std::cout << temp->data << std::endl;
			temp = temp->next;
		}
	}
};


int main()
{
	LinkedList L;

	L.AddNode(3);
	L.AddNode(2);
	L.AddNode(1);

	L.Display();

}