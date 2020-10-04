//C++ Program if the user is eligible for voting or not by his/her age/
#include <iostream.h>
#include<conio.h>
int main()
{
	int age;
	clrscr();
	cout << "Enter the age of the user: " << endl;
	cin >> age;
	if (age >= 18)
	{
	 cout << "The user is eligible to vote." << endl;
	}
	else
	 cout << "The user is not eligible to vote."  << endl;

	getch();

	return 0;

}