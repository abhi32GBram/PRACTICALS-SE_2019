#include<iostream>

using namespace std;

class tree
{

	int a[20][20], l, u, w, i, j, vertices, edges, visited[20];
public:
	void input();
	void display();
	void prims_minCost();
};

void tree::input()
{
	cout << "ENTER THE NUMBER OF BRANCHES :  ";
	cin >> vertices;
	for (i = 0; i < vertices; i++)
	{
		visited[i] = 0;
		for (j = 0; j < vertices; j++)
		{
			a[i][j] = 999;
		}
	}
	cout << "\n---->ENTER THE NUMBER OF CONNECTIONS : ";
	cin >> edges;
	for (i = 0; i < edges; i++)
	{
		cout << "\n====>ENTER THE END BRANCHES OF CONNECTION :  ";
		cin >> l >> u;

		cout << "===>ENTER THE CHARGES OF PHONE COMPANY FOR THIS BRACH  : ";
		cin >> w;

		a[l - 1][u - 1] = a[u - 1][l - 1] = w;
	}
}

void tree::display()
{
	cout << "\nTHE RESULTING ADJACENCY MATRIX IS  : ";
	for (i = 0; i < vertices; i++)
	{
		cout << endl;
		for (j = 0; j < vertices; j++)
		{
			cout << a[i][j] << "   ";
		}
		cout << endl;
	}
}

void tree::prims_minCost()
{
	int p = 0, q = 0, total = 0, min;
	visited[0] = 1;
	for (int count = 0; count < (vertices - 1); count++)
	{
		min = 999;
		for (i = 0; i < vertices; i++)
		{
			if (visited[i] == 1)
			{
				for (j = 0; j < vertices; j++)
				{
					if (visited[j] != 1)
					{
						if (min > a[i][j])
						{
							min = a[i][j];
							p = i;
							q = j;
						}
					}
				}
			}
		}
		visited[p] = 1;
		visited[q] = 1;
		total = total + min;
		cout << "CONNECTION WITH LEAST COST " << (p + 1) << " --> " << (q + 1) << "  WITH CHARGES OF  : " << min;
	}
	cout << "THE MINIMUM COST TOTAL COST OF CONNECTIONS OF ALL BRANCHES IS : : " << total;
}

int main()
{
	int ch;
	tree t;
	do
	{
		cout << " \n\t\t\t~~~H6 TELEPHONE WORKS ~~~" << endl;

		cout << "\nI.   INPUT THE LINE ROUTES";
		cout << "\nII.  DISPLAY ALL LINES";
		cout << "\nIII. DISPLAY MINIMUM CHARGE LINE";


		cout << "\n\n\t ENTER YOU'RE CHOICE :";
		cin >> ch;
		switch (ch)
		{
		case 1:
			cout << "\n~~~ ENTER YOU'RE VALUES ~~~ " << endl;
			t.input();
			break;
		case 2:
			cout << "\n~~~ DISPLAY THE CONTENT ~~~ " << endl;
			t.display();
			break;
		case 3:
			cout << "\n~~~ prims_minCost COST ~~~" << endl;
			t.prims_minCost();
			break;
		}
	} while (ch != 4);


	return 0;
}










//
//ENTER THE NUMBER OF BRANCHES : 4
//ENTER THE NUMBER OF CONNECTIONS : 5
//
//ENTER THE END BRANCHES OF CONNECTION :
//1 2
//ENTER THE CHARGES OF PHONE COMPANY FOR THIS BRANCH : 3
//
//ENTER THE END BRANCHES OF CONNECTION :
//2 3
//ENTER THE CHARGES OF PHONE COMPANY FOR THIS BRANCH : 2
//
//ENTER THE END BRANCHES OF CONNECTION :
//3 4
//ENTER THE CHARGES OF PHONE COMPANY FOR THIS BRANCH : 5
//
//ENTER THE END BRANCHES OF CONNECTION :
//4 1
//ENTER THE CHARGES OF PHONE COMPANY FOR THIS BRANCH : 4
//
//ENTER THE END BRANCHES OF CONNECTION :
//2 4
//ENTER THE CHARGES OF PHONE COMPANY FOR THIS BRANCH : 1
