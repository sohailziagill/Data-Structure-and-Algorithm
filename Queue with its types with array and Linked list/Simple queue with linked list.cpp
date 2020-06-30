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
	curr = new node;
	cout << "\n Enter the value for Queue \t";
	cin >> curr->val;
	if (rear == NULL)
		front = rear = curr;
	else
	{
		rear->next = curr;
		rear = curr;
	}
}
void deletion()
{
	if (front == NULL)
		cout << "\n Under flow\t";
	else
	{
		curr = front;
		front = front->next;
		cout << "\n Deleted \t"<<curr->val<<endl;
		if (front == NULL)
			rear = NULL;
		delete(curr);
	}
}
void display()
{
	curr = front;
	while (curr != NULL)
	{
		cout << "\n " << curr->val;
		curr = curr->next;
	}
}
void menu(int& x)
{
	do
	{
		cout << "\n Enter 1 for insertion  in Queue by linked list\t";
		cout << "\n Enter 2 for Deletion in Queue by linked list\t";
		cout << "\n Enter 3 for Display of Queue by linked list\t";
		cout << "\n Enter 4 to exit from the Queue by linked lsit\t\t";
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
