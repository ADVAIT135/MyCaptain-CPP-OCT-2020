#include<iostream>
#include<string>
using namespace std;
class totaltime{
private:
	int seconds;
	int minutes;
	int hours;
public:
	calculatetime(){
		int sec,s1,s2;
		cout << "Enter hours: " << endl;
		cin >> hours;
		s1 = hours * 3600;
		cout << "Enter  minutes: " << endl;
		cin >> minutes;
		s2 = minutes * 60;
		cout << "Enter seconds " << endl;
		cin >> sec;
		cout << "The entered time details in HH:MM:SS are :-" << endl;
		string n = "0";
		if(hours < 10 && minutes>10 && sec>10){
                string x = to_string(hours);
                cout << n + x << ":" << minutes << ":" << sec << endl;
		}
        else if( minutes<10 && sec>10 && hours > 10){
            string y = to_string(minutes);
            cout << hours << ":" << n + y << ":" << sec << endl;
        }
        else if( sec<10 && minutes>10 && hours >10){
            string z = to_string(sec);
            cout << hours << ":" << minutes << ":" << n + z << endl;
        }
        else if( sec<10 && hours<10 && minutes>10){
            string z = to_string(sec);
            string f = to_string(hours);
            cout << n+f << ":" << minutes << ":" << n + z << endl;
        }
        else if( sec<10 && minutes<10 && hours > 10){
            string z = to_string(sec);
            string g = to_string(minutes);
            cout << hours << ":" << n+g << ":" << n + z << endl;
        }
        else if( hours<10 && minutes<10 && sec>10){
            string h = to_string(hours);
            string i = to_string(minutes);
            cout << n+h << ":" << n+i << ":" << sec << endl;
        }
        else if( hours<10 && minutes<10 && sec<10){
            string j = to_string(hours);
            string k = to_string(minutes);
            string l = to_string(sec);
            cout << n+j << ":" << n+k << ":" << n+l << endl;
        }
        else
            cout << hours << ":" << minutes << ":" << sec << endl;



		//cout << hours << ":" << minutes << ":" << sec << endl;
		seconds = s1 + s2 + sec;
		return seconds;
		//cout << "The entered time details in total seconds is :" << s << endl;


	}
	displayresult();

};
totaltime :: displayresult(){
	cout << "The entered time details in total seconds is :" << seconds << endl;
}
main()
{
	totaltime t1;
	t1.calculatetime();
	t1.displayresult();
}
