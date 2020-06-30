#include<iostream>
using namespace std;
struct node
{
	int val;
	node* left=NULL;
	node* right=NULL;
};
node* front = NULL, * rear = NULL, *curr, *newnode;
void front_insert()
{
	newnode = new node;
	cout << "\n Enter the value in queue \t";
	cin >> newnode->val;
	if (front == NULL)
	{
		front = newnode;
		rear = newnode;
	}
	else
	{
		newnode->right = front;
		front->left = newnode;
		front = newnode;
	}
}
void rear_insert()
{
	newnode = new node;
	cout << "\n Enter the value in queue \t";
	cin >> newnode->val;
	newnode->left = rear;
	rear->right = newnode;
	rear = newnode;
}
void front_deletion()
{
	if (front == NULL)
		cout << "\n Queue is empty \t";
	else
	{
		if (front == rear)
		{
			curr = front;
			front = NULL;
			rear = NULL;
			delete(curr);
			cout << "\n Deleted \t";
		}
		else
		{
			curr = front;
			front = front->right;
			front->left = NULL;
			delete(curr);
			cout << "\n Deleted \t";
		}
	}
}
void rear_deletion()
{
	if (front == NULL)
		cout << "\n Queue is empty \t";
	else
	{
		if (front == rear)
		{
			curr = front;
			front = NULL;
			rear = NULL;
			delete(curr);
			cout << "\n Deleted \t";
		}
		else
		{
			curr = rear;
			rear=rear->left;
			rear->right = NULL;
			delete(curr);
			cout << "\n Deleted \t";
		}
	}
}
void display()
{
	if (front == NULL)
		cout << "\n Queue is empty \t";
	else
	{
		curr = front;
		while (curr)
		{
			cout << "\n " << curr->val;
			curr = curr->right;
		}
	}
}
void menu(int& x)
{
	do
	{
		cout << "\n Enter 1 for insertion  at front in Double ended Queue by linked list\t";
		cout << "\n Enter 2 for insertion  at end in Double ended Queue by linked list\t";
		cout << "\n Enter 3 for Deletion at front in Double ended Queue by linked list\t";
		cout << "\n Enter 4 for Deletion at end in Double ended Queue by linked list\t";
		cout << "\n Enter 5 for Display of Double ended Queue by linked list\t";
		cout << "\n Enter 6 to exit from the Double ended Queue by linked lsit\t\t";
		cin >> x;
		if (x < 1 || x>6)
			cout << "\n An invalid input\t";
	} while (x < 1 || x>6);
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
			front_insert();
			break;
		case 2:
			rear_insert();
			break;
		case 3:
			front_deletion();
			break;
		case 4:
			rear_deletion();
			break;
		case 5:
			display();
			break;
		case 6:
			exit(-1);
		}

	} while (x != 6);
	cout << endl;
	system("pause");
	return 0;
}
