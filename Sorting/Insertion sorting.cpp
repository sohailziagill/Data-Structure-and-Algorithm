#include<iostream>
#include<string.h>
using namespace std;
# define max 1000
int main()
{
	int mnky=0,arr[max],key,i,j;
	cout << "\n Enter the number of students \t";
	cin >> mnky;
	for ( i = 0; i < mnky ; i++)
	{
		cout << "\n Enter the number in " << i + 1 << " \t";
		cin >> arr[i];
	}
	for ( j = 1; j <= mnky; j++)
	{
		i = j - 1;
		key = arr[j];
		while (i != -1)
		{
			if (arr[i] > key)
			{
				arr[i + 1] = arr[i];
				arr[i] = key;
			}
			i--;
		}
	}
	cout << "\n \n\n After the sorting \t";
	for ( i = 0; i < mnky; i++)
		cout << "\n " << arr[i];
	cout << endl;
	system("pause");
	return 0;
}
