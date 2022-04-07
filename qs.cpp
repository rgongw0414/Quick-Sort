#include <iostream>
#include <string>
#include <vector>

using namespace std;

void QuickSort(vector<int> &x, int f, int l);

int main()
{
	int num = 0;
	cin >> num;
	string s;
	getline(cin, s);

	int input[20];
	int index = 0;
	char Xi;
	while ((Xi = getchar()) != '\n')
	{
		if (Xi != ' ')
		{
			ungetc(Xi, stdin);
			cin >> input[index++];
		}
	}
	vector<int> x;
	for (int i = 0; i < num; i++)
	{
		x.push_back(input[i]);
	}
	
	QuickSort(x, 0, num - 1);
	cout << "The sorted sequence: ";
	for (int i = 0; i < num; i++)
	{
		cout << x[i] << " ";
	}
	cout << endl;
	system("PAUSE");
}

void QuickSort(vector<int> &x, int f, int l)
{
	if (f > l) return;	
	int X = x[f];
	int i = f;
	int j = l;
	
	while (i < j)
	{
		while (x[j] >= X && i != j)
		{
			j--;			
		}
		swap(x[i], x[j]);
		while (x[i] <= X && i != j)
		{
			i++;			
		}
		swap(x[i], x[j]);
	}
	QuickSort(x, f, j - 1);
	QuickSort(x, j + 1, l);
}