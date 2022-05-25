#include<iostream>

using namespace std;

int main()
{
	cout << "Hello world!" << endl;
	
	int n = 10;
	int arr[10] = {4,2,5,7,1,6,3,9,8,10};
	int i = 0;
	int j = 0;
	for ( i = 0; i < n-1; i++)
	{
		for ( j = 0; j < n-1-i; j++)
		{
			if (arr[j]>arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j + 1] = temp;
			}
		}
	}

	for ( j = 0; j < n; j++)
	{
		cout << arr[j] << endl;
	}
	system("pause");
	return 0;
}