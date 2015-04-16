

//the three numbers from big to small order
#include<iostream>
#include<iomanip>
using namespace std;
int classP_1()
{
	int A, B, C;
	cout << "Enter three digits:";
	cin >> A >> B >> C;
	if (A < B) {	//sort A and B
		A = A + B;
		B = A - B;
		A = A - B;
	}
	if (A < C) {	//sort A and C
		A = A + C;
		C = A - C;
		A = A - C;
	}
	if (B < C) {	//sort B and C
		B = B + C;
		C = B - C;
		B = B - C;
	}
	cout << "After changed:";
	cout << A << setw(5) << B << setw(5) << C << endl;

	return 0;
}



//display 10 lines of the inverted Pyramid
#include<iostream>
using namespace std;
int classP_2()
{
	int i, j, k;

	for (i = 10; i > 0; i--) {
		for (j = 10 - i; j > 0; j--) {		//display spaces in every lines
			cout << " ";
		}
		for (k = 2 * i - 1; k > 0; k--) {	//display stars in every lines
			cout << "*";
		}
		cout << endl;
	}

	return 0;
}

//bubble sort algorithm,figures from big to small order
#include<iostream>
using namespace std;
int classP_3()
{
	int a[150];		//definite an array 
	int n, i,j,temp;
	cout << "Enter n(n<=150):";
	cin >> n;
	cout << "Enter " << n << " digits:";
	//for array assignment
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	//use loop statement,sort digits from big to small
	for (i = 1; i < n - 1; i++) {
		for (j = n-1; j >0; j--) {
			if (a[j] > a[j - 1]) {		//if the latter is bigger than the former
				temp = a[j];			//exchange them
				a[j] = a[j - 1];
				a[j - 1] = temp;
			}
		}
	}

	//display the array after sorted
	for (i = 0; i < n; i++) {
		cout << a[i] << " ";
	}

	return 0;
}

//calculate 1+2+3...+n
#include<iostream>
using namespace std;
int homework_1()
{
	int sum = 0;
	int n;

	cout << "Enter n:";
	cin >> n;
	for (int i = 1; i <= n; i++) {
		sum += i;
	}
	cout << "1+2+...+" << n << "=" << sum<<endl;

	return 0;
}

//calculate 1 - 1/2 + 1/3 - 1/4 + 1/5 - 1/6 …… 1/n
#include<iostream>
using namespace std;
int homework_2()
{
	int n, flag, i;
	double sum = 0;

	flag = 1;
	cout << "Enter n:";
	cin >> n;
	for (i = 1; i <= n; i++) {
		sum += 1.0*flag / i;
		flag = -flag;
	}
	cout << "The sum is:" << sum<<endl;

	return 0;
}

//calculate 1! + 2! + 3! + 4! +……+ n!
#include<iostream>
using namespace std;
int homework_3()
{
	int factorial(int x);	//declare function for factorial
	int n, i;
	long int sum = 0;

	cout << "Enter n:";
	cin >> n;
	for (i = 1; i <= n; i++) {
		sum += factorial(i);
	}
	cout << "1! + 2! + 3! + 4! +……+ n!=" << sum << endl;

	return 0;
}
//function for factorial
int factorial(int x)
{
	int i, part;

	part = 1;
	for (i = 1; i <= x; i++) {
		part *= i;
	}
	
	return part;
}

//calculate 1! + 3! - 5! + 7! - 9! ……(2*n+1)! 
#include<iostream>
using namespace std;
int homework_4()
{
	int factorial(int x);	//declare function for factorial
	int n, flag,i;
	long int sum = 1;

	flag = 1;
	cout << "Enter n:";
	cin >> n;
	for (i = 3; i <= 2 * n + 1; i = i + 2) {
		sum += 1.0*flag*factorial(i);
		flag = -flag;
	}
	cout << "1! + 3! - 5! + 7! - 9! ……(2*n+1)!= " << sum << endl;

	return 0;
}

//calculate sin(x)=x/1! - pow(x,3)/3! + pow(x,5)/5! -pow(x,7)/7! +…,finally,the accuracy not less than 0.000001 
#include<iostream>
#include<cmath>
using namespace std;
int homework_5()
{
	double x, sum, part;	//"part" stores every item，"sum" stores the finally result
	int i, flag = 1;

	sum = 0;
	cout << "Enter x:";
	cin >> x;
	i = 1;
	do{
		part = 1.0*pow(x, i) / factorial(i);
		sum += 1.0*flag*part;
		flag = -flag;
		i = i + 2;
	} while (part >= 1e-6);
	cout << "sin(" << x << ")=" << sum << endl;

	return 0;
}

//take n numbers from m numbers,calculate counts of combination
#include<iostream>
using namespace std;
int homework_6()
{
	int factorial(int x);	//declare function for factorial
	int count, m,n;
	
	cout << "Enter m and n:";
	cin >> m >> n;
	count = factorial(m) / (factorial(n)*factorial(m - n));
	cout << "counts of combination：" << count << endl;

	return 0;
}

//calculate 2*3/4*5*6 + 3*4/5*6*7 - 4*5/6*7*8 + 5*6/7*8*9 -.....finally,the accuracy not less than 0.000001
#include<iostream>
using namespace std;
int homework_7()
{
	int i;
	double part, sum;	//"part" stores every item

	sum = 0;
	i = 2;
	do {
		part = 1.0*i*(i + 1) / ((i + 2)*(i + 3)*(i + 4));
		sum += part;
		i++;
	} while (part >= 1e-6);
	cout << "2*3/4*5*6 + 3*4/5*6*7 - 4*5/6*7*8 + 5*6/7*8*9 -.....(最后一项精度不低于0.000001)=" << sum << endl;

	return 0;

}

//calculate 1/2 + 2/3 + 3/5 + 5/8 + 8/13 + 13/21，…(200 items) 
#include<iostream>
using namespace std;
int homework_8()
{	
	int x, y,i,temp;	// "x" stores ,molecular，"y" stores denominator
	double sum, part;

	sum = 0;
	x = 1;
	y = 2;
	for (i = 1; i <= 200; i++) {
		part = 1.0*x / y;
		sum += part;
		temp = y;	//the former denominator is used as the latter molecular，the former "molecular + denominator" is used as the latter denominator
		y = x + temp;
		x = temp;
	}
	cout << "1/2+2/3+3/5+5/8+...(200项）=" << sum << endl;

	return 0;
}


//calculate PI : PI / 4 = 1 - 1 / 3+ 1 / 5 - 1 / 7 + .....
#include<iostream>
using namespace std;
int homework_9()
{
	double PI, sum, part;
	int flag, i;

	sum = 0;
	flag = 1;
	i = 1;
	do {
		part = 1.0 * 1 / i;
		sum += flag*part;
		i = i + 2;
		flag = -flag;
	} while (part >= 1e-6);
	PI = 4 * sum;
	cout << "PI=" << PI << endl;

	return 0;
}

//display n lines Pyramid
#include<iostream>
using namespace std;
int homework_10()
{
	int n, i,k;

	cout << "Enter n:";
	cin >> n;
	for (i = 1; i <= n; i++) {		//display the former half of stars
		for (k = 1; k <= i; k++) {
			cout << "*";
		}
		cout << endl;
	}
	for (i = n+1; i <= 2*n-1; i++) {		//display the latter half of stars
		for (k = 1; k <= 2 * n - i; k++) {
			cout << "*";
		}
		cout << endl;
	}

	return 0;
}


//display positive and negative nine*nine multiplication table
#include<iostream>
#include<iomanip>
using namespace std;
int homework_11()
{
	int i, j, k;

	for (i = 1; i <= 9; i++) {		//display positive nine*nine multiplication table
		for (k = 1; k <= i; k++) {
			cout << k << "*" << i << "=" << k*i<<" ";
			if (k*i < 10) cout << ' ';
		}
		cout << endl;
	}
	cout << endl << endl;

	for (i = 9; i > 0; i--) {	//display negative nine*nine multiplication table
		for (k = 1; k <= 9 - i; k++) {		//display spaces in every lines
			cout <<"       ";
		}
		k = 10 - i;
		for (j = k; j <= 9; j++) {
			cout << k << "*" << j << "=" << k*j <<" ";
			if (j*k < 10) cout << ' ';
		}
		cout << endl;		
	}

	return 0;
}


//definite a constant (between 1 and 200)，let user guess the constant，compare two digits，then show the result to user until the user guess the right constant.
#include<iostream>
using namespace std;
int homework_12()
{
	int truth = 66;		//the constant is 66
	int guess;
	
	do{
		cout << "Enter your guess:";
		cin >> guess;
		if (guess > truth) {
			cout << "Sorry,your guess is bigger than the truth,please try again.";	
		}
		else if(guess<truth) {
			cout << "Sorry,your guess is smaller than the truth,please try again." ;
		}
	} while (guess != truth);
	cout << "Yes,you're right." << endl;

	return 0;
}

//select sort algorithm,figures from big to small order
#include<iostream>
using namespace std;
int homework_13()
{
	int a[100];
	int n, i,k,max;

	cout << "Enter n:";
	cin >> n;
	cout << "Enter " << n << " integers:";
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (i = 0; i < n - 1; i++) {
		for (k = i + 1; k < n; k++) {
			if (a[i] < a[k]) {
				max = a[k];
				a[k] = a[i];
				a[i] = max;
			}
		}
	}
	//display the array after sorted
	for (i = 0; i < n; i++) {
		cout << a[i]<<" ";

	}

	return 0;
}

