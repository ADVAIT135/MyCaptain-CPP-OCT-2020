#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
using namespace std;
int main()
{
    FILE *fp, *ft;
    char another,choice;
    struct student
    {
        char first_name[50],fathers_name[50],last_name[50];
        char course[100];
        int section , roll_number;
    };
    struct student e;
    char xfirst_name[50], xfathers_name[50] , xlast_name[50];
    long int recsize;

    fp = fopen("users.txt","rb+");

    if(fp == NULL)
    {
        fp = fopen("users.txt","wb+");

        if(fp == NULL)
        {
            puts("Cannot open file");
            return 0;
        }
    }
    recsize = sizeof(e);

    while(1)
    {
        system("cls");

        cout << "******** STUDENT DATABASE MANAGEMENT SYSTEM ********" << endl;
        cout << "1. ADD Records" << endl;
        cout << "2. LIST Records" << endl;
        cout << "3. MODIFY Records" << endl;
        cout << "4. DELETE Records" << endl;
        cout << "5. EXIT program" << endl;
        cout << "Select Your Choice :-" << endl;
        fflush(stdin);
        choice = getche();
        switch(choice)
        {
        case '1':
            fseek(fp,0,SEEK_END);
            another = 'Y';
            while(another == 'Y' || another == 'y')
            {
                system("cls");
                cout << "Enter the First Name : ";
                cin >> e.first_name;
                cout << "Enter the Father's Name : ";
                cin >> e.fathers_name;
                cout << "Enter the Last Name : ";
                cin >> e.last_name;
                cout << "Enter the Course : ";
                cin >> e.course;
                cout << "Enter the Section : ";
                cin >> e.section;
                fwrite(&e,recsize,1,fp);
                cout << "\n Add Another Record(Y/N) :";
                fflush(stdin);
                another = getchar();

            }
            break;
        case '2':
            system("cls");
            rewind (fp);
            cout << "=== View the Records in the Database ===" << endl;
            while(fread(&e,recsize,1,fp)==1)
            {
                cout << "\n";
                cout << "\n" << e.first_name << setw(10) << e.fathers_name << setw(10) << e.last_name;
                cout << "\n";
                cout << "\n" << e.course << setw(8) << e.section;
            }
            cout << "\n\n";
            system("pause");
            break;

        case '3':
            system("cls");
            another = 'Y';
            while(another == 'Y' || another == 'y')
            {
                cout << "\n Enter the Last Name of the student : ";
                cin >> xlast_name;

                rewind(fp);
                while(fread(&e,recsize,1,fp)==1)
                {
                    if (strcmp(e.last_name,xlast_name) == 0)
                    {
                        cout << "Enter the new First Name : " ;
                        cin >> e.first_name;
                        cout << "Enter the new Father's Name : ";
                        cin >> e.fathers_name;
                        cout << "Enter the new Last Name : ";
                        cin >> e.last_name;
                        cout << "Enter the new Course : ";
                        cin >> e.course;
                        cout << "Enter the new Section : ";
                        cin >> e.section;
                        fseek(fp,~ recsize,SEEK_CUR);
                        fwrite(&e,recsize,1,fp);
                        break;
                    }
                    else
                        cout << "Record Not Found";
                }
                cout << "\n Modify Another Record (Y/N) ";
                fflush(stdin);
                another = getchar();
            }
            break;

        case '4':
            system("cls");
            another = 'Y';
            while(another == 'Y' || another == 'y')
            {
                cout << "\n Enter the Last Name of the student to delete : ";
                cin >> xlast_name;

                ft=fopen("temp.dat","wb");
                rewind(fp);
                while(fread (&e,recsize,1,fp)==1)
                {
                    if(strcmp(e.last_name,xlast_name) != 0)
                    {
                        fwrite(&e,recsize,1,ft);
                    }
                    fclose(fp);
                    fclose(ft);
                    remove("users.txt");
                    rename("temp.dat","users.txt");
                    fp=fopen("users.txt","rb+");
                    cout << "\n Delete Another Record (Y/N) ";
                    fflush(stdin);
                    another=getchar();
                }
                break;

        case '5':
            fclose(fp);
            cout << "\n\n";
            cout << "\t\t       THANKYOU FOR USING THIS SOFTWARE";
            cout << "\n\n";
            exit(0);
            }

        }

    }
    system("pause");
    return 0;
}
