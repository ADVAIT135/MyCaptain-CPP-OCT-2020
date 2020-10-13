#include<conio.h>
#include<cstdio>
#include<iostream>
#include<string.h>
#include<cstdlib>
using namespace std;
static int p = 0;
class a
{
//private:
    char busn[5], driver[10] , arrival[5] , depart[5] , from [10] , to [10] , seat[8][4][10] , phnumber[10];
public:
    void install();
    void allotment();
    void empty();
    void show();
    void avail();
    void position (int i);
}
bus[10];
void vline(char ch)
{
    for(int i=80;i>0;i--)
        cout << ch;
}
void a :: install()
{
    cout << "Enter bus number: " << endl;
    cin >> bus[p].busn;
    cout << "Enter Driver's name: " << endl;
    cin >> bus[p].driver;
    cout << "Arrival time : " << endl;
    cin >> bus[p].arrival;
    cout << "Departure : " << endl;
    cin >> bus[p].depart;
    cout << "From : " << endl;
    cin >> bus[p].from;
    cout << "To : " << endl;
    cin >> bus[p].to;
    cout << "Contact number of Driver : " << endl;
    cin >> bus[p].phnumber;
    bus[p].empty();
    p++;
}

void a :: allotment()
{
    int seat;
    char number[5];
    top:
        cout << "Bus number : " << endl;
        cin >> number;
        int n;
        for(n=0;n<=p;n++)
        {
            if(strcmp(bus[n].busn ,number) == 0)
            break;
        }
        while(n<=p)
        {
            cout << "Seat number : " << endl;
            cin >> seat;
            if(seat>32)
            {
                cout << "There are only 32 seats available in this bus." << endl;
            }
            else
            {
                if (strcmp(bus[n].seat[seat/4][(seat%4)-1], "Empty") == 0)
                {
                   cout << "Enter Passenger's Name : " << endl;
                   cin >> bus[n].seat[seat/4][(seat%4)-1];
                   break;
                }
                else
                    cout << "This seat number is already reserved." << endl;
            }
        }
        if(n>p)
        {
            cout << "Enter correct bus number : " << endl;
            goto top;
        }


}
void a :: empty()
{
    for (int i=0;i<8;i++)
    {
        for (int j=0;j<4;j++)
        {
            strcpy(bus[p].seat[i][j],"Empty");
        }
    }
}
void a :: show()
{
    int n;
    char number[5];
    cout << "Enter Bus Number : " << endl;
    cin >> number;
    for(n=0;n<=p;n++)
    {
        if(strcmp(bus[n].busn,number)==0)
            break;

    }
    while(n<=p)
    {
        vline('*');
        cout << "Bus number : " << bus[n].busn << endl;
        cout << "Driver : " << bus[n].driver << endl;
        cout << "Arrival Time : " << bus[n].arrival  << "\t" << endl;
        cout << "Departure Time : "  << bus[n].depart << "\t" << endl;
        cout << "From : " << bus[n].from << endl;
        cout << "To : " << bus[n].to << endl;
        cout << "Driver's Contact Number : " <<bus[n].phnumber ;
        vline('*');
        bus[0].position(n);
        int a=1;
        for (int i=0;i<8;i++)
        {
            for(int j=0;j<4;j++)
            {
                a++;
                if(strcmp(bus[n].seat[i][j],"Empty")!=0)
                    cout << "\nThe Seat Number " << (a-1) << " is reserved for " << bus[n].seat[i][j] << "." << endl;
            }
        }
        break;
    }
    if(n>p)
    {
        cout << "Enter correct Number : " << endl;
    }
}

void a :: position(int l)
{
    int s=0,p=0;
    for(int i=0;i<8;i++)
    {
        cout << "\n";
        for(int j=0;j<4;j++)
        {
            s++;
            if (strcmp(bus[l].seat[i][j],"Empty")==0)
            {
                cout.width(5);
                cout.fill(' ');
                cout << s << ".";
                cout.width(10);
                cout.fill(' ');
                cout << bus[l].seat[i][j];
                p++;
            }
            else
            {
                cout.width(5);
                cout.fill(' ');
                cout << s << "." << endl;
                cout.width(10);
                cout.fill(' ');
                cout << bus[1].seat[i][j];
            }
        }
    }
    cout << "\nThere are " << p << " seats empty in bus number " << bus[l].busn;
}

void a :: avail()
{
    for (int n=0;n<p;n++)
    {
        vline('*');
        cout << "\nBus number : " << bus[n].busn << endl;
        cout << "Driver : " << bus[n].driver  << endl;
        cout << "Arrival Time : " << bus[n].arrival << "\t" << endl;
        cout << "Departure Time : " <<  bus[n].depart << "\t" << endl;
        cout << "From : " << bus[n].from  << endl;
        cout << "To : " << bus[n].to << endl;
        cout << "Driver's Contact Number : " <<bus[n].phnumber ;
        vline('*');
        vline('_');

    }
}
int main()
{
    system("cls");
    int w;
    while(1)
    {
        cout << "\n\n\n\n\n";
        cout << "\t\t\t1.Install\n\t\t\t"
        << "2.Reservation\n\t\t\t"
        << "3.Show\n\t\t\t"
        << "4.Buses Available. \n\t\t\t"
        << "5.Exit";
        cout << "\n\t\t\t Enter your choice -> ";
        cin >> w;
        switch(w)
        {
            case 1 : bus[p].install();
            break;
            case 2: bus[p].allotment();
            break;
            case 3: bus[0].show();
            break;
            case 4: bus[0].avail();
            break;
            case 5: exit(0);

        }
    }
    return 0;
}
