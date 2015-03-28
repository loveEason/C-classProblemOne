//prompt for a digit,then display the digit
#include<iostream>
using namespace std;
int P2_16()
{
	double digit;

	cout << "Enter a digit:";
	cin >> digit;
	cout << digit << endl;

	return 0;
}


//ask user "is it raining now?",then output "it is raining now." if the user input "Y" ,or output "it is not raining now." if the user input "N",or output "is it raining now?"
#include<iostream>
using namespace std;
int P2_26()
{
	char answer;

	do{
		cout << "is it raining now?";
		cout << "please enter Y of N:";
		cin >> answer;
		if (answer == 'Y' || answer == 'y') cout << "it is raining now.";
		else if (answer == 'N' || answer == 'n') cout << "it is not raining now.";
	} while (answer != 'Y' && answer != 'y' && answer != 'N' && answer != 'n');

	return 0;
}


//ask user "what's your score of the exam(0~100)?", then rank the score
#include<iostream>
using namespace std;
int P2_27()
{
	int score;

	cout << "Input your score:";
	cin >> score;
	if (score >= 90 && score <= 100){
		cout << "Better";
	}
	else if (score >= 80) {
		cout << "Good";
	}
	else if (score >= 60) {
		cout << "Middle";
	}
	else cout << "Bad";

	return 0;
}


//an easy Menu program
#include<iostream>
#include<stdlib.h>
using namespace std;
int P2_28()
{
	char choice;

	cout << "Menu:A(dd) D(elete) S(ort) Q(uit),Select one:";
	cin >> choice;
	switch (toupper(choice)){
	case 'A':
		cout << "the data have been added.";
		break;
	case 'D':
		cout << "the data have been deleted.";
		break;
	case 'S':
		cout << "the data have been sorted";
		break;
	case 'Q':
		exit(0);
	default:
		break;
	}

	return 0;
}


//find out prime numbers between 1 and 100
#include<iostream>
using namespace std;
int P2_29()
{
	int i, j;

	for (i = 2; i <= 100; i++) {
		for (j = 2; j <= i / 2; j++) {
			if (i%j == 0) break;
		}
		if (j>i / 2) cout << i << " ";
	}

	return 0;
}


//precisely display time that user input 
#include<iostream>
using namespace std;
int P2_31()
{
	int year, month, day, hour, minute, second;
	
	cout << "please enter year,month,day,hour,minute,second:";
	cin >> year >> month >> day >> hour >> minute >> second;
	cout << "the time is " << year << ":" << month << ":" << day << ":" << hour << ":" << minute << ":" << second << endl;

	return 0;
}


//there are many red/yellow/blue/white/black balls in pocket.how many the counts if every time take out 3 different colors balls from the pocket
#include<iostream>
#include<iomanip>
using namespace std;
int P2_34()
{
	enum color{ red, yellow, blue, white, black };	//declare enum type;
	color pri;	//definite enum variable "pri";
	int i, j, k, loop, n = 0;	//"n" stores counts of combination

	for (i = red; i <= black; i++) {	//when "i" is one kind of color
		for (j = red; j <= black; j++) {	//	when "j" is one kind of color
			if (i != j) {	//continue only when "i" and "j" are different colors
				for (k = red; k <= black; k++) {	//when "k" is one kind of color
					if (k != i && k != j) {
						n++;
						cout << setw(3) << n;	//output counts
						for (loop = 1; loop <= 3; loop++){	//process on the three ball in turn
							switch (loop) {
							case 1:pri = color(i); break;	//compulsory type conversion£¬change "pri" to "i"
							case 2:pri = color(j); break;
							case 3:pri = color(k); break;
							dafault:break;
							}
							switch (pri) {	//display the color judged by the "pri"
							case red:cout << setw(8) << "red"; break;
							case yellow:cout << setw(8) << "yellow"; break;
							case blue:cout << setw(8) << "blue"; break;
							case white:cout << setw(8) << "white"; break;
							case black:cout << setw(8) << "black"; break;
							default:break;
							}
						}
						cout << endl;
					}
				}

			}
		}
	}

	return 0;
}

