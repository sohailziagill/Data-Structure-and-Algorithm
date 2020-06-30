#include<iostream>
using namespace std;
int queue[100], n = 100, front = -1, rear = -1;
void insert()
{
	int val;
	if (rear == n - 1)
		cout << "\n over flow You cannot add more elements in queue\t";
	else
	{
		cout << "\n Enter the value in queue\t";
		cin >> val;
		queue[++rear] = val;
		if (front == -1)
			front = 0;
	}
}
void deletion()
{
	int item;
	if (front == -1 || front > rear)
		cout << " Under flow you cannot delete the element\t";
	else
	{
		item = queue[front];
		front = front + 1;
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
		for (int i = front; i <= rear; i++)
			cout << "\n" << queue[i];
	}
	size = rear - front + 1;
	cout << "\nThe size of queue is " << size << endl << endl;
}
void menu(int& x)
{
	do
	{
		cout << "\n Enter 1 for insertion in Queue\t";
		cout << "\n Enter 2 for Deletion in Queue\t";
		cout << "\n Enter 3 for Display of Queue\t";
		cout << "\n Enter 4 to exit from the Queue\t\t";
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
