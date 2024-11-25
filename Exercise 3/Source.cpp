#include<iostream>
using namespace std;

class Node
{
public:
	int data;
	Node* next;
};

class Queue {
private:
	Node* rear;
	Node* front;

public:
	Queue()
	{
		rear = NULL;
		front = NULL;
	}

	bool is_empty()
	{
		if (front == NULL && rear == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void Enqueue(int Value)
	{
		Node* temp = new Node;
		temp->data = Value;
		temp->next = NULL;

		if (is_empty())
		{
			front = rear = temp;
		}
		else
		{
			rear->next = temp;
			rear = temp;
		}
	}

	void Dequeue()
	{
		Node* temp = front;
		if (is_empty())
		{
			cout << "Queue is empty!" << endl;
		}
		else
		{
			front = front->next;
			cout << temp->data << " Dequeued!" << endl;
			delete temp;
		}
	}

	void Display()
	{
		Node* current = front;
		cout << "Queue is: " << endl;
		while (current != NULL)
		{
			cout << current->data << " ";
			current = current->next;
		}
		cout << endl;
	}
};

int main()
{
	Queue q;
	q.Enqueue(10);
	q.Enqueue(20);
	q.Enqueue(30);
	q.Enqueue(40);
	q.Enqueue(50);
	q.Display();
	q.Dequeue();
	q.Display();
	q.Dequeue();
	q.Display();
}