#include<iostream>
using namespace std;
struct node
{
	int marks;
	node* next;
};
void menu(int& x)
{
	do
	{

		cout << "\n Enter 1 for creating the list            \t";
		cout << "\n Enter 2 for inserting  new list          \t";
		cout << "\n Enter 3 for display  list                \t";
		cout << "\n Enter 4 for deleting a number from list  \t";
		cout << "\n Enter 5 for searching a number from list \t";
		cout << "\n Enter 6 to exit                          \t";
		cin >> x;
		if (x < 1 && x>6)
			cout << "\n Invalid input ";
	} while (x < 1 && x>6);

}
int main()
{
	int choice;
	node* first = NULL;
	node* curr = NULL;
	node* prev = NULL;
	int x;
	do
	{
		menu(x);

		switch (x)
		{

		case 1:
		{
			//          To create the new linked list
			do
			{
				curr = new node;
				cout << "Enter the marks \t";
				cin >> curr->marks;
				curr->next = NULL;
				if (first == NULL)
					first = prev = curr;
				else
				{
					prev->next = curr;
					prev = curr;
				}

				do
				{
					cout << "\n Enter the choice 1 for new data and 0 for stop entering data \t";
					cin >> choice;
					if (choice != 1 && choice != 0)
						cout << "\n Invalid Data";
				} while (choice != 1 && choice != 0);

			} while (choice == 1);
			break;
		}
		case 2:
		{
			//    To insert new item in link list 
			node* newitem;
			bool isinsert = false;
			newitem = new node;
			newitem->next = NULL;
			cout << "\n Enter the new marks ";
			cin >> newitem->marks;
			//Insertion at the beginnig 

			if (newitem->marks <= first->marks)
			{
				newitem->next = first;
				first = newitem;
				isinsert = true;
			}
			else
			{
				curr = prev = first;
				while (curr != NULL)
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

				}

			}
			if (!isinsert)
				prev->next = newitem;
			cout << "\n Insertion succesfully completed ";
			break;
		}
		case 3:
		{
			//                    To display the link list
			curr = first;
			while (curr != NULL)
			{
				cout << "\n The marks are " << curr->marks;
				curr = curr->next;
			}
			break;
		}
		case 4:
		{
			//                 To delete number from the link list
			int dmark;
			bool isdelete = false;
			cout << "\n Enter the number that you want to delete \t";
			cin >> dmark;
			curr = prev = first;
			// Deletion at start
			if (dmark == first->marks)
			{
				first = first->next;
				delete curr;
				isdelete = true;
			}
			//Deletion at Midlle and end
			else
			{
				while (curr != NULL)
				{
					if (curr->marks == dmark)
					{
						prev->next = curr->next;
						delete curr;
						isdelete = true;
						break;
					}
					else
					{
						prev = curr;
						curr = curr->next;
					}
				}
			}
			if (isdelete)
			{
				cout << "\n The deletion is performed successfully ";
				curr = first;
				while (curr != NULL)
				{
					cout << "\n The marks are " << curr->marks;
					curr = curr->next;
				}

			}
			else
				cout << "\n The givven number is not exist in this list ";
			break;
		}
		case 5:
		{

			//                    To search in link list
			int smark;
			bool isfound = false;
			cout << "\n Enter the mark that you want to search \t";
			cin >> smark;
			curr = first;
			while (curr != NULL)
			{
				if (curr->marks == smark)
				{
					isfound = true;
					break;
				}
				else
					curr = curr->next;

			}
			if (isfound)
				cout << "\n The givven number is found ";
			else
				cout << "\n The givven number is not exist in this list";
			break;
		}

		case 6:
		{
			exit(-1);
		}
		default:
			break;
		}
	} while (true);





	cout << endl;
	system("pause");
	return 0;
}

