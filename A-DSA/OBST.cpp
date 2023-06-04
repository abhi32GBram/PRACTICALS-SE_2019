#include <iostream>
#include <climits>
using namespace std;

int sum(int freq[], int i, int j);
int optimalSearchTree(int keys[], int freq[], int n);

int main_obst()
{
	cout << "\t\t\t~~~ WELCOME TO THE OPTIMAL BINARY SEARCH TREE MAKER ~~~\n\n";

	int n;
	cout << "~~ ENTER THE NUMBER OF KEYS : ";
	cin >> n;

	int keys[100];
	int freq[100];

	cout << "ENTER THE KEYS :\n";
	for (int i = 0; i < n; i++)
	{
		cout << "\n--> KEY " << i + 1 << ":  ";
		cin >> keys[i];
	}

	cout << "\n~~ ENTER THE FREQUENCIES :\n";
	for (int i = 0; i < n; i++)
	{
		cout << "\n---> FREQUENCY " << i + 1 << ": ";
		cin >> freq[i];
	}

	int optimalCost = optimalSearchTree(keys, freq, n);
	cout << "\n\n COST OF THE OPTIMAL BINARY TREE IS :  " << optimalCost << endl;

	return 0;
}

int optimalSearchTree(int keys[], int freq[], int n)
{
	int cost[100][100];

	for (int i = 0; i < n; i++)
		cost[i][i] = freq[i];

	for (int L = 2; L <= n; L++)
	{
		for (int i = 0; i <= n - L + 1; i++)
		{
			int j = i + L - 1;
			cost[i][j] = INT_MAX;

			for (int r = i; r <= j; r++)
			{
				int c = ((r > i) ? cost[i][r - 1] : 0) +
					((r < j) ? cost[r + 1][j] : 0) +
					sum(freq, i, j);

				if (c < cost[i][j])
					cost[i][j] = c;
			}
		}
	}

	return cost[0][n - 1];
}

int sum(int freq[], int i, int j)
{
	int s = 0;
	for (int k = i; k <= j; k++)
		s += freq[k];
	return s;
}

