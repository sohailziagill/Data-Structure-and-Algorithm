#include<iostream>
using namespace std;
struct node
{
	int marks;
	node* next;
};
void menu(int& x)
{
	cout << "\n Enter 1 to enter data in list      \t";
	cout << "\n Enter 2 to search data in list\t     ";
	cout << "\n Enter 3 to insert new data in list \t";
	cout << "\n Enter 4 to delete data in list     \t";
	cout << "\n Enter 5 to display data from list  \t";
	cout << "\n Enter 6 to exit from the list      \t";
	cin >> x;
}
int main()
{
	int x;
	node* first = NULL;
	node* curr = NULL;
	node* prev = NULL;
	do
	{
		menu(x);
	  switch (x)
		{
		case 1:
		{
			// To take input from the user in circular linked list.
			do
			{
				curr = new node;
				cout << "\n Enter the marks \t";
				cin >> curr->marks;
				if (first == NULL)
				{
					prev = curr;
					first = curr;
					curr->next = first;
				}
				else
				{
					prev->next = curr;
					curr->next = first;
					prev = curr;
				}
				do
				{
					cout << "\n Enter 1 to enter data and 0 to stop entering data \t";
					cin >> x;
					if (x != 0 && x != 1)
						cout << "\n An invalid input ";
				} while (x != 1 && x != 0);

			} while (x == 1);
			cout << endl << endl;
			break;

		}
		case 2:
		{
			// To search in circular linked list.
			int count = 0, snum;
			bool isfound = false;
			if (first == NULL)
				cout << "\n The list is empty";
			else
			{
				cout << "\n Enter the number that you want to search \t";
				cin >> snum;
				curr = first;
				do
				{
					if (curr->marks == snum)
					{
						isfound = true;
						break;
					}
					else
					{
						curr = curr->next;
						count++;
					}
				} while (curr != first);
				if (isfound)
					cout << "\n The number " << snum << " is found at position  " << count;
				else
					cout << "\n The number " << snum << "  is not found in this list ";
			}
			cout << endl << endl;
			break;

		}
		case 3:
		{
			// For insertion in the circular linked list.
			node* newitem;
			bool isinsert = false;
			newitem = new node;
			cout << "\n Enter the marks \t";
			cin >> newitem->marks;
			// If list is empty!
			if (first == NULL)
			{
				cout << "\n Please create the list first.";
			}
			else
			{
				curr = prev = first;
				//At beginnning insertion.
				if (newitem->marks <= first->marks)
				{
					newitem->next = first;
					while (curr->next != first)//Important  concept.
					{
						curr = curr->next;
					}
					curr->next = newitem;//To change the last node.
					first = newitem;
					isinsert = true;
				}
				//Insertion at middle or any position.
				else
				{
					curr = prev = first;
					do
					{
						if (newitem->marks >= curr->marks)
						{
							prev = curr;
							curr = curr->next;
						}
						else
						{
							prev->next = newitem;
							newitem->next = curr;
							isinsert = true;
							break;
						}
					} while (curr != first);
				}

				//insertion at last.
				if (!isinsert)
				{
					prev->next = newitem;
					newitem->next = first;
				}
			}
			cout << endl << endl;
			break;
		}
		case 4:
		{
			// Deletion in circular linked list.
			int dmark;
			bool isdelete = false;
			cout << "\n Enter the number that you want to delete it \t";
			cin >> dmark;
			curr = first;
			// Deletion at start.
			if (dmark == first->marks)
			{
				while (curr->next != first)// Important concept.
					curr = curr->next;
				curr->next = first->next;
				curr = first;
				first = curr->next;
				delete curr;
				isdelete = true;
				cout << "\n The number is deleted successfully ";
			}
			// Deletion at middle.
			else if (!isdelete)
			{
				do
				{
					if (curr->marks == dmark)
					{
						prev->next = curr->next;
						delete curr;
						isdelete = true;
						cout << "\n Deletion is performed successfullt ";
						break;
					}
					else
					{
						prev = curr;
						curr = curr->next;
					}
				} while (curr != first);

			}
			// Deletion at end.
			else if (!isdelete)
			{
				do
				{
					if (curr->marks == dmark)
					{
						prev->next = first;
						delete curr;
						isdelete = true;
						cout << "\n The deletion is performed successfully ";
						break;
					}
					else
					{
						prev = curr;
						curr = curr->next;
					}
				} while (curr != first);

			}
			if (!isdelete)
				cout << "\n The givven number is not existed in this list ";
			cout << endl << endl;
			break;

		}
		case 5:
		{
			//To display the marks from circular linked list .


			curr = first;
			do
			{
				cout << "\n The  marks are " << curr->marks;
				curr = curr->next;
			} while (curr != first);
			cout << endl << endl;
			break;

		}
		case 6:
		{
			exit(-1);
		}
		default:
			break;
		}
	}while (1);
	cout << endl;
	system("pause");
	return 0;
}
