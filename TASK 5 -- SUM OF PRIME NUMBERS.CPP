#include<iostream>
using namespace std;
int Prime(int n)
{
    int i, Prime = 1;
    for(i=2;i<=n/2;i++)
    {
        if(n%2 == 0)
        {
            Prime = 0;
            break;
        }
    }
    return Prime;
}
int main()
{
    int i,x;
    cout << "Enter a Integer number:- " <<endl;
    cin >> x;
    for(i=2;i<=x/2;i++)
    {
        if(Prime(i) == 1)
        {


        if(Prime(x-i) == 1)
        {
            cout << x << " = " << i << " + " << (x-i) << endl;
        }
        }

    }
    return 0;
}
