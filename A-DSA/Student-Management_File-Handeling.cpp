
#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

class student
{
	typedef struct stud
	{
		int roll;
		char name[10];
		char div;
		char add[10];
	}stud;
	stud rec;
public:
	void create();
	void display();
	int search();
	void Delete();
};

void student::create()
{
	char ans;
	ofstream fout;
	fout.open("stud.dat", ios::out | ios::binary);
	do
	{
		cout << "\n\tENTER THE ROLL NO OF STUDENT    : ";
		cin >> rec.roll;
		cout << "\n\tENTER THE NAME OF STUDENT     : ";
		cin >> rec.name;
		cout << "\n\tENTER THE DIVISION OF STUDENT : ";
		cin >> rec.div;
		cout << "\n\tENTER THE ADDRESS OF STUDENT  : ";
		cin >> rec.add;

		fout.write((char*)&rec, sizeof(stud)) << flush;

		cout << "\n\t\tDO YOU WANT TO ADD MORE RECORDS (Y/N) : ";
		cin >> ans;
	} while (ans == 'y' || ans == 'Y');
	fout.close();
}

void student::display()
{
	ifstream fin;
	fin.open("stud.dat", ios::in | ios::binary);
	fin.seekg(0, ios::beg);
	cout << "\n\tTHE CONTENT OF FILE ARE : \n";
	cout << "\n\tROLLNO\tNAME\tDIV\tADDRESS";
	while (fin.read((char*)&rec, sizeof(stud)))
	{
		if (rec.roll != -1)
			cout << "\n\t" << rec.roll << "\t" << rec.name << "\t" << rec.div << "\t" << rec.add;
	}
	fin.close();
}

int student::search()
{
	int r, i = 0;
	ifstream fin;
	fin.open("stud.dat", ios::in | ios::binary);
	fin.seekg(0, ios::beg);
	cout << "\n\tENTER A ROLL NO: ";
	cin >> r;
	while (fin.read((char*)&rec, sizeof(stud)))
	{
		if (rec.roll == r)
		{
			cout << "\n\tRECORD FOUND !!! \n";
			cout << "\n\tROLLNO\tNAME\tDIV\tADDRESS";
			cout << "\n\t" << rec.roll << "\t" << rec.name << "\t" << rec.div << "\t" << rec.add;
			return i + 1;
		}
		else
			i++;
	}
	return 0;
	fin.close();
	return 0;
}

void student::Delete()
{
	int pos;
	pos = search();
	if (pos == 0)
	{
		cout << "\n\t SORRY !! RECORD NOT FOUND";
		return;
	}
	pos = pos - 1;
	fstream f;
	f.open("stud.dat", ios::in | ios::out | ios::binary);
	f.seekg(0, ios::beg);

	int offset = pos * sizeof(stud);
	f.seekp(offset);
	rec.roll = -1;
	strcpy_s(rec.name, "NULL");
	rec.div = 'N';
	strcpy_s(rec.add, "NULL");
	f.write((char*)&rec, sizeof(stud));
	f.seekg(0);
	f.close();
	cout << "\n\tRecord Deleted";
}

int main_FILES()
{
	student obj;
	int ch, key;
	char ans;
	do
	{
		cout << "\n\n\t ~~~ SE COMPUTER SCIENCE STUDENT MANAGEMENT SYSTEM ~~~ ";
		cout << "\n\n1. CREATE STUDENT PROFILE\n2. DISPLAY ALL RECORDS\n3. DELETE A RECORD\n4. SEARCH FOR A RECORD\n5. EXIT THE DASHBOARD";
		cout << "\n\n\t ENTER YOUR CHOICE : ";
		cin >> ch;
		switch (ch)
		{
		case 1:
			obj.create();
			break;
		case 2:
			obj.display();
			break;
		case 3:
			obj.Delete();
			break;
		case 4:
			key = obj.search();
			if (key == 0)
				cout << "\n\t SORRY !!RECORD NOT FOUND\n";
			else
				cout << "\n\tRECORD FOUND !!\n";
			break;
		case 5:
			break;
		}
	} while (ch != 5);
	return 1;
}
