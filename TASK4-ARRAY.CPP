#include<iostream>
using namespace std;


int main()
{
    //array a[b];
    int *i;
    int a,b,c,j,k;
    int arr[] = {};
    i = arr;

    cout << "Enter the number of elements you want in the array:-" << endl;
    cin >> b;
    c = b -1;

    for(j=0;j<=c;j++)
    {
        cout << "Enter the value of the " << j << " element: " << endl;
        cin >> i[j];
        i++;


    }
    cout << "The entered elements are:-" << endl;
    for(k=0;k< *i;k++)
    {

        cout << k <<" element is :" << *i << endl;
        i++;
    }
    return 0;

}
