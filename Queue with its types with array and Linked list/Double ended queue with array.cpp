#include<iostream>
using namespace std;
int dequeue[5], n = 5, front = -1, rear = -1;
void insert_front()
{
	int val;
	cout << "\n Enter the value for Double ended Queue \t";
	cin >> val;
	if (front == 0)
		cout << "\n Before 0 in queue insertion is not possible\t";
	else if (front == -1)
	{
		front = 0;
		rear = 0;
		dequeue[front] = val;
	}
	else 
	{
		front = front - 1;
		dequeue[front] = val;
	}
}
void insert_rear()
{
	int val;
	if (rear >= n - 1)
		cout << "\n The queue is full or overflow\t";
	else
	{
		cout << "\n Enter the value for insertion \t";
		cin >> val;
		if (front == -1)
		{
			front = 0;
			rear = 0;
			dequeue[rear] = val;
		}
		else
		{
			rear = rear + 1;
			dequeue[rear] = val;
		}
	}
}
void display()
{
	if (front == -1)
		cout << "\n The list is empty! \t";
	else
	{
		for (int i = front; i <= rear; i++)
			cout << "\n " << dequeue[i];
	}
}
void deletion_front()
{
	if (front == -1)
		cout << "\n Under flow \t";
	else
	{
		cout << "\n Deleted successfully ";
		if (front == rear)
		{
			front = -1;
			rear = -1;
		}
		else 
			front = front + 1;
	}
}
void deletion_rear()
{
	if (front == -1)
		cout << "\n Under flow \t";
	else
	{
		cout << "\n Deleted successfully ";
		if (front == rear)
		{
			front = -1;
			rear = -1;
		}
		else
			rear = rear - 1;
	}
}
void menu(int& x)
{
	do
	{
		cout << "\n Enter 1 for insertion at front in Double ended Queue\t";
		cout << "\n Enter 2 for insertion at Rear in Double ended Queue\t";
		cout << "\n Enter 3 for Deletion at front in Double ended Queue\t";
		cout << "\n Enter 4 for Deletion at rear in Double ended Queue\t";
		cout << "\n Enter 5 for Display of Double ended Queue\t";
		cout << "\n Enter 6 to exit from the Double ended Queue\t\t";
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
			insert_front();
			break;
		case 2:
			insert_rear();
			break;
		case 3:
			deletion_front();
			break;
		case 4:
			deletion_rear();
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
