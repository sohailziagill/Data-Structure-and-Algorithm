//Must Dry Run It!
#include<iostream>
using namespace std;
int cqueue[5], n = 5, front = -1, rear = -1;
void insert()
{
	int val;
	// Dry run this condition to understand.
	if (front==0 && rear == n - 1||front==rear+1)
		cout << "\n over flow You cannot add more elements in queue\t";
	else
	{
		cout << "\n Enter the value in queue\t";
		cin >> val;
		if (front == -1)
		{
			front = 0;
			rear = 0;
		}
		else if (rear == n - 1)
			rear = 0;
		else
			rear = rear + 1;
		cqueue[rear] = val;
	}
}
void deletion()
{
	int item;
	if (front == -1 || front > rear)
		cout << " Under flow you cannot delete the element\t";
	else
	{
		if (front == rear)
		{
			item = cqueue[front];
			front = -1;
			rear = -1;
		}
		else if (front == n - 1)
		{
			item = cqueue[front];
			front = 0;
		}
		else
		{
			front = front + 1;
			item = cqueue[front];
		}
		cout << "\n Deleted successfully " << item << "\t";
	}
}
void display()
{
	int size;
	if (front == -1)
		cout << "\n The queue is empty\t";
	else
	{
		int f, r;
		f = front;
		r = rear;
		if (f <= r)
		{
			while (f <= r)
			{
				cout << "\n" << cqueue[f];
				f++;
			}
		}
		else
		{
			while (f <= n - 1)
			{
				cout << "\n" << cqueue[f];
				f++;
			}
			f = 0;
			while (f <= r)
			{
				cout << "\n" << cqueue[f];
				f++;
			}
		}
	}
}
void menu(int& x)
{
	do
	{
		cout << "\n Enter 1 for insertion in circular Queue\t";
		cout << "\n Enter 2 for Deletion in circular Queue\t";
		cout << "\n Enter 3 for Display of circular Queue\t";
		cout << "\n Enter 4 to exit from the circular Queue\t\t";
		cin >> x;
		if (x < 1 || x>4)
			cout << "\n An invalid input\t";
	}
	while (x< 1 || x>4);
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
