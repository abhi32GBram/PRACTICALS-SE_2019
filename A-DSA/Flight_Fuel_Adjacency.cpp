#include<iostream>
#include<climits>
using namespace std;

class Graph_flights
{
	int adjaceny_mat[30][30];
public:
	void populate_flights();
	void connected();

	int row_size = 0;
	int coloumn_size = 0;
	string cities[40];
};

void Graph_flights::populate_flights()
{
	cout << "\n\nENTER THE NUMBER OF CITIES IN THE SCHEDULE  : ";
	cin >> row_size;

	cout << "ENTER THE NAME OF THE CITIES: ";
	for (int i = 0; i < row_size; i++)
	{
		cin >> cities[i];
	}
	char cho[20];

	cout << "\n--> ENTER NUMBER OF SOURCE CITIES : ";
	cin >> row_size;

	cout << "\n-->ENTER NUMBER OF DESTINATION CITIES :";
	cin >> coloumn_size;

	cout << "~~~ENTER THE AMOUNT OF FUEL TO TRAVEL BETWEEN THE CITIES (IN Kg ) :  ";

	for (int i = 0; i < row_size; i++)
	{
		for (int j = 0; j < coloumn_size; j++)
		{
			if (cities[i] != cities[j])
			{
				cout << "\n\nFUEL REQUIRED BETWEEN " << cities[i] << " TO " << cities[j] << " IS : ";
				cin >> adjaceny_mat[i][j];
			}
		}
	}
}

void Graph_flights::connected()
{
	cout << "\n\n ~~~AMOUNT OF FUEL REQUIRED FOR THE ONGOING FLIGHTS  : ";

	for (int i = 0; i < row_size; i++)
	{
		for (int j = 0; j < coloumn_size; j++)
		{
			if (adjaceny_mat[i][j] != 0 && cities[i] != cities[j])
			{
				cout << "\n" << cities[i] << " ===> " << cities[j] << " WITH THE AMOUNT OF FUEL REQUIRED :  ";
				cout << adjaceny_mat[i][j] << " Kg";
			}
		}
	}
	return;
}

int main_flights()
{
	cout << " \n\t\t\t ~~~ H6 AIRLINES ~~~";
	cout << "\n\t-------------------------------------------------------";
	cout << "\n\t\t~~ WELCOME TO FLIGHT DATA DASHBOARD ~~";

	cout << "\n\nI.)   DISPLAY FUEL AND LOGISTICS DATA ";
	cout << "\nII.)  EXIT THE CONTROL PANEL  ";

	cout << "\n\n\t\t ENTER YOU'RE CHOICE : ";
	int ch_operation = 0;
	do {
		cin >> ch_operation;

		Graph_flights domestic;

		switch (ch_operation)
		{
		case 1:
			cout << "\n~DISPLAYING DOMESTIC DATA --->  ";
			domestic.populate_flights();
			domestic.connected();
			break;
		}
	} while (ch_operation != 2);
	return 0;
}















