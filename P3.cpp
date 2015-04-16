//input two integers,then return the first one integer divide the second integer if the second integer is not 0
#include<iostream>
using namespace std;
int P3_7()
{
	int P3_7sec(unsigned short int first, unsigned short int second);

	unsigned short int first, second;
	cout << "Input two integers:";
	cin >> first >> second;
	cout<<P3_7sec(first, second);

	return 0;
}

int P3_7sec(unsigned short int first, unsigned short int second)
{
	if (second != 0) return 1.0*first / second;
	else return -1;
}

//converting fahrenheit to celsius
int P3_8()
{
	double F, C;

	cout << "Input a fahrenheit:";
	cin >> F;
	C = 1.0 * 5 * (F - 32) / 9;
	cout << "the celsius is:" << C << endl;

	return 0;
}


//determine a number whether is a prime number or not
int P3_9()
{
	int num;
	int i;

	cout << "Input a number:";
	cin >> num;
	for (i = 2; i < num / 2; i++) {
		if (num%i == 0) break;
	}
	if (i >= num / 2 && num!=1) cout << "the number is prime number." << endl;
	else cout << "the number is not prime number." << endl;

	return 0;
}

//seek the gratest common divisor and the least common multiple
int P3_10()
{
	int x1,x2, div, mul;

	cout << "Input two integers:";
	cin >> x1 >> x2;
	if (x1 < 0) x1 = -x1;
	if (x2 < 0) x2 = -x2;
	mul = x1;
	while (mul%x2 != 0) mul += x1;
	div = x1*x2 / mul;
	cout << "the gratest common divisor is:" << div << endl;
	cout << "the least common multiple is:" << mul << endl;

	return 0;
}


//input n,then calculate 1+2+...+n
int P3_12()
{
	int sum(int n);	//declare the function
	int n;

	cout << "Input n:";
	cin >> n;
	cout << "1+2+3+...+n=" << sum(n);

	return 0;

}

int sum(int n)
{
	int total;
	if (n == 1) total = 1;
	else total = n + sum(n - 1);

	return total;
}

//calculate N order Legendre polynomial
int P3_14()
{
	int pn(double x, int n);	//declare the function
	double x;
	int n;

	cout << "Input x and n:";
	cin >> x >> n;
	cout << "the result is:" << pn(x, n);
	
	return 0;
}
int pn(double x, int n)
{
	double sum;
	if (n == 0) return 1;
	else if (n == 1) return x;
	else sum = 1.0*((2 * n - 1)*x*pn(x,n - 1) - (n - 1)*pn(x, n - 2)) / n;

}

//calculate x y square
int P3_15()
{
	int getPower(int x, int y);
	double getPower(double x, int y);
	int a, m;
	double b;
	
	cout << "Input integer 'a' :";
	cin >> a;
	cout << "Input real 'b' :";
	cin >> b;
	cout << "Input integer 'm' :";
	cin >> m;

	cout << a << " square " << m << "=" << getPower(a, m) << endl;
	cout << b << " square " << m << "=" << getPower(b, m) << endl;

	return 0;
}

int getPower(int x, int y)
{
	int i;
	int sum=1;

	if (y < 0) return 0;
	else {
		for (i = 1; i <= y; i++) {
			sum = sum *x;
		}
		return sum;
	}
}

double getPower(double x, int y)
{
	int i;
	double sum = 1.0;

	for (i = 1; i <= y; i++) {
		sum = 1.0*sum*x;
	}
	return sum;
}