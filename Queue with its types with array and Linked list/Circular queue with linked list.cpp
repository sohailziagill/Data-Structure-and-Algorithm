#include<iostream>
using namespace std;
struct node
{
	int val;
	node* next=NULL;
};
node* front = NULL, * rear = NULL,*curr;
void insert()
{
	curr = new  node;
	cout << "\n Enter the value in Circular Queue \t";
	cin >> curr->val;
	if (front == NULL)
		front = curr;
	else
		rear->next = curr;
	rear = curr;
	rear->next = front;
}
void deletion()
{
	if (front == NULL)
		cout << "\n Under flow \t";
	else
	{
		if (front == rear)
		{
			curr = front;
			front = NULL;
			rear = NULL;
			delete(curr);
			cout << "\nDeleted \t";
		}
		else
		{
			curr = front;
			front = front->next;
			delete(curr);
			cout << "\n Deleted \t";
			rear->next = front;
		}
	}
}
void display()
{
	if (front == NULL)
		cout << "\n The queue is empty \t";
	else
	{
		curr = front;
		do
		{
			cout << "\n " << curr->val;
			curr = curr->next;
		} while (curr != front);
	}
}
void menu(int& x)
{
	do
	{
		cout << "\n Enter 1 for insertion  in circular Queue by linked list\t";
		cout << "\n Enter 2 for Deletion in circular Queue by linked list\t";
		cout << "\n Enter 3 for Display of circular Queue by linked list\t";
		cout << "\n Enter 4 to exit from the circular Queue by linked lsit\t\t";
		cin >> x;
		if (x < 1 || x>4)
			cout << "\n An invalid input\t";
	} while (x < 1 || x>4);
}
int main()
{
	int x;
	do
	{
		menu(x);
		switch (x)
		{
		case 1:
			insert();
			break;
		case 2:
			deletion();
			break;
		case 3:
			display();
			break;
		case 4:
			exit(-1);
		}

	} while (x != 4);
	cout << endl;
	system("pause");
	return 0;
}
