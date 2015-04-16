
//input a year,then display the whole year calendar

#include<iostream>
using namespace std;
int leap(int year)	//determine whether the year is leap year
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {	//if the year is leap year
		return 1;
	}
	else return 0;
}

int calendar()
{
	int year, i, j, k, sum, initial, count, temp1, temp2;

	cout << "Input year:";
	cin >> year;

	sum = 0;
	for (i = 1; i <= year - 1; i++) {	//calculate the total days from 1year to "year-1"
		if (leap(i)) sum += 366;
		else sum += 365;
	}

	//calculate what's the first day of "year"
	initial = sum % 7 + 1;
	if (initial == 7)  initial = 0;

	int eachMonth[2][13] = {
		{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },	//not leap year
		{ 1, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }	//leap year
	};	//definite array,sort two different years' all year days

	//display the calendar


	for (i = 1; i <= 12; i++) {
		temp1 = temp2 = initial;
		count = 0;
		cout << "\t\t\t" << i << " month" << endl;
		cout << "---------------------------------------------------" << endl;
		cout << "Sun\tMon\tTue\tWed\tThur\tFri\tSat\n";
		cout << "---------------------------------------------------" << endl;
		for (j = 1; j <= eachMonth[leap(year)][i]; j++) {
			for (k = 1; k <= initial; k++) {
				cout << "\t";
			}
			cout << j << "\t";
			count++;
			initial = 0;
			if (count + temp1 == 7) {
				cout << endl;
				count = 0;
				temp1 = 0;
			}
		}
		initial = (eachMonth[leap(year)][i] - (7 - temp2)) % 7;
		cout << endl << endl;
	}

	return 0;
}