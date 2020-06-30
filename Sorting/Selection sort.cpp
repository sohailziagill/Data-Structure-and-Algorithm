#include<iostream>
using namespace std;
# define max 1000
int main()
{
	int mnky=0,arr[max];
	bool isswap = false;
	cout << "\n Enter the number of students \t";
	cin >> mnky;
	for (int i = 0; i <= mnky - 1; i++)
	{
		cout << "\n Enter the number in " << i + 1 << " \t";
		cin >> arr[i];
	}
	for (int i = 0; i < mnky; i++)
	{
		for (int j = i+1; j < mnky; j++)
			if (arr[i] > arr[j])
			{
				swap(arr[i], arr[j]);
			}
	}

	cout << "\n \n\n After the sorting \t";
	for (int i = 0; i <= mnky - 1; i++)
		cout << "\n " << arr[i];
	cout << endl;
	system("pause");
	return 0;
}
