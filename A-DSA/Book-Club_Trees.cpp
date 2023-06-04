#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

struct node
{
    char name[20];
    node* next;
    node* down;
    int flag;
};
class Book_Club
{
    char ch[20];    int n, i;
    node* head = NULL, * temp = NULL, * t1 = NULL, * t2 = NULL;
public:
    node* create();
    void insert_book();
    void insert_chapter ();
    void insert_section();
    void insert_subSection();
    void display_books();

};

node* Book_Club::create()
{
    node* p = new(struct node);
    p->next = NULL; 
    p->down = NULL;
    p->flag = 0;
    cout << "\n ENTER THE NAME : ";
    cin >> p->name;
    return p;
}

void Book_Club::insert_book()
{

    if (head == NULL)
    {
        t1 = create();
        head = t1;
    }
    else
    {
        cout << "\n BOOK ALREADY EXISTS ! ENTER FURTHER CONTENT ";
    }
}
void Book_Club::insert_chapter ()
{
    if (head == NULL)
    {
        cout << "\n OOPS ! THE BOOK DOSEN'T EXIST";
    }
    else
    {
        cout << "\n HOW MANY CHAPTERS ARE IN THE BOOK ? : ";
        cin >> n;
        for (i = 0; i < n; i++)
        {
            t1 = create();
            if (head->flag == 0)
            {
                head->down = t1;   head->flag = 1;
            }
            else
            {
                temp = head;
                temp = temp->down;
                while (temp->next != NULL)
                    temp = temp->next;
                temp->next = t1;
            }
        }
    }
}   
void Book_Club::insert_section()
{

    if (head == NULL)
    {
        cout << "\n OOPS ! THE BOOK DOSEN'T EXIST";
    }
    else
    {
        cout << "\n ENTER NAME OF CHAPTER WHERE YOU WANT THE SECTION : ";
        cin >> ch;

        temp = head;
        if (temp->flag == 0)
        {
            cout << "\n THE ARE NO CHAPTERS ON IN BOOK";
        }
        else
        {
            temp = temp->down;
            while (temp != NULL)
            {
                if (!strcmp(ch, temp->name))
                {
                    cout << "\n HOW MANY SECTIONS ARE IN THE BOOK ?  : ";
                    cin >> n;
                    for (i = 0; i < n; i++)
                    {

                        t1 = create();
                        if (temp->flag == 0)
                        {
                            temp->down = t1;

                            temp->flag = 1;  cout << "\n------------------------";
                            t2 = temp->down;

                        }
                        else
                        {
                            cout << "\n=============================";
                            while (t2->next != NULL)
                            {
                                t2 = t2->next;
                            }
                            t2->next = t1;
                        }
                    }
                    break;
                }
                temp = temp->next;
            }
        }
    }
}
void Book_Club::insert_subSection()
{

    if (head == NULL)
    {
        cout << "\n OOPS ! THE BOOK DOSEN'T EXIST";
    }
    else
    {
        cout << "\n ENTER THE NAME OF CHAPTER ON WHICH YOU WANT TO ENTER THE SECTION";
        cin >> ch;

        temp = head;
        if (temp->flag == 0)
        {
            cout << "\n THERE ARE NO CHAPTERS ON IN BOOK";
        }
        else
        {
            temp = temp->down;
            while (temp != NULL)
            {
                if (!strcmp(ch, temp->name))
                {
                    cout << "\n ENTER NAME OF SECTION IN WHICH YOU WANT TO ENTER THE SUB SECTION : ";
                    cin >> ch;

                    if (temp->flag == 0)
                    {
                        cout << "\n SORRY ! THERE ARE NO SECTIONS  ";
                    }
                    else
                    {
                        temp = temp->down;
                        while (temp != NULL)
                        {
                            if (!strcmp(ch, temp->name))
                            {
                                cout << "\n HOW MANY SUBSECTIONS DO YOU WANT : ";
                                cin >> n;
                                for (i = 0; i < n; i++)
                                {

                                    t1 = create();
                                    if (temp->flag == 0)
                                    {
                                        temp->down = t1;

                                        temp->flag = 1;  cout << "\n******";
                                        t2 = temp->down;

                                    }
                                    else
                                    {
                                        cout << "\n#####";
                                        while (t2->next != NULL)
                                        {
                                            t2 = t2->next;
                                        }
                                        t2->next = t1;
                                    }
                                }
                                break;
                            }      temp = temp->next;
                        }
                    }
                }

                temp = temp->next;
            }
        }
    }
}
void Book_Club::display_books()
{

    if (head == NULL)
    {
        cout << "\n OOPS ! THE BOOK DOSEN'T EXIST";
    }
    else
    {
        temp = head;

        cout << "\n TITLE OF THE BOOK :  " << temp->name;
        if (temp->flag == 1)
        {
            temp = temp->down;

            while (temp != NULL)
            {
                cout << "\n\t\tNAME OF CHAPTER:  " << temp->name;
                t1 = temp;
                if (t1->flag == 1)
                {
                    t1 = t1->down;
                    while (t1 != NULL)
                    {
                        cout << "\n\t\t\t\tNAME OF SECTION:  " << t1->name;
                        t2 = t1;
                        if (t2->flag == 1)
                        {
                            t2 = t2->down;
                            while (t2 != NULL)
                            {
                                cout << "\n\t\t\t\t\t\tNAME OF SUBSECTION:  " << t2->name;
                                t2 = t2->next;
                            }
                        }
                        t1 = t1->next;
                    }
                }
                temp = temp->next;
            }

        }
    }



}
int main_books()
{
    Book_Club club;   int choice_operation;
    while (1)
    {
        cout << " \n\n\t\t~~~ WELCOME TO THE PVPIT BOOK CLUB ~~~\n";

        cout << "\n I.)   INSERT BOOK";
        cout << "\n II.)  INSERT CHAPTER";
        cout << "\n III.) INSERT SECTION";
        cout << "\n IV.)  INSERT SUBSECTION";
        cout << "\n V.)   DISPLAY BOOK";
        cout << "\n VI.)  EXIT";

        cout << "\n\n\t ENTER YOUR CHOICE : ";
        cin >> choice_operation;
        switch (choice_operation)
        {
        case 1:          club.insert_book();
            break;
        case 2:          club.insert_chapter ();
            break;
        case 3:          club.insert_section();
            break;
        case 4:          club.insert_subSection();
            break;
        case 5:          club.display_books();
            break;
        case 6:  exit(0);
        }
    }
    return 0;
}
