/*
//clock class
#include<iostream>
using namespace std;

class Clock{		//definite class clock
public:
	void setTime(int newH = 0, int newM = 0, int newS = 0);
	void showTime();
private:
	int hour, minute, second;
};

void Clock::setTime(int newH, int newM, int newS) {
	hour = newH;
	minute = newM;
	second = newS;
}

void Clock::showTime(){
	cout << hour << ":" << minute << ":" << second << endl;
}

int E4_1()
{
	Clock myClock;
	cout << "First time set and output:" << endl;
	myClock.setTime();	//set default time
	myClock.showTime();	//show time
	cout << "Second time set and output:" << endl;
	myClock.setTime(21, 33, 30);
	myClock.showTime();

	return 0;
}
*/

/*
//3 situation about use clone structural function 
#include<iostream>
using namespace std;

class Point {
public:
	Point(int xx = 0, int yy = 0){		//structural function
		x = xx;
		y = yy;
	}
	Point(Point &p);	//clone structural function
	int getX(){
		return x;
	}
	int getY(){
		return y;
	}
private:
	int x, y;
};

Point::Point(Point &p) {
	x = p.x;
	y = p.y;
	cout << "Calling the copy constructor" << endl;
}

void fun1(Point p){
	cout << p.getX() << endl;
}

Point fun2() {
	Point a(1, 2);
	return a;
}


int E4_2()
{
	Point a(4, 5);	//the first object
	Point b = a;	//situation 1:use a to initialise b,the first time to use clone constructor
	cout << b.getX() << endl;
	fun1(b);		//situation 2:use object b as actual parameter,the second time to use clone constructor
	b = fun2();		//situation 3:the function return class object,the third time to use clone constructor
	cout << b.getX() << endl;

	return 0;
}

*/


/*
//calculate the price of building poor
#include<iostream>
using namespace std;

const float PI = 3.141593;
const float Fence_Price = 35;	//fence 's unit price
const float Concrete_Price = 20;	//concrete's unit price


class Circle{		//declare a class
public:
	Circle(float r);	//constructor
	float circumference();		//calculate circle's circumference
	float area();		//calculate circle's area
private:
	float radius;		//circle's radius
};

//class's function
//constructor to initialise radius
Circle::Circle(float r) {
	radius = r;
}

//calculate circle's circemference
float Circle::circumference() {
	return 2 * PI*radius;
}

//calculate circle's area
float Circle::area() {
	return PI*radius*radius;
}

//the main function
int E4_3()
{
	float radius;
	cout << "Input the radius of the pool:";
	cin >> radius;
	Circle pool(radius);	//pool object
	Circle poolRim(radius + 3);	//fence object

	//calculate fence's price
	float fenceCost = poolRim.circumference()*Fence_Price;
	cout << "Fencing Cost is $ " << fenceCost << endl;

	//calculate road's price
	float roadCost = (poolRim.area() - pool.area())*Concrete_Price;
	cout << "Road's Cost is $ " << roadCost << endl;

	return 0;
}

*/


/*
//the combination of classes,Line class
#include<iostream>
#include<cmath>
using namespace std;
class Point{
public:
	Point(int xx = 0, int yy = 0) {
		x = xx;
		y = yy;
	}
	Point(Point &p);
	int getX(){ return x; }
	int getY() { return y; }
private:
	int x, y;
};

Point::Point(Point &p) {	//the copy constructor
	x = p.x;
	y = p.y;
	cout << "Calling the copy constructor of Point" << endl;
}

//the combination of classes
class Line{
public:
	Line(Point xp1, Point xp2);
	Line(Line &l);
	double getlen() { return len; }
private:
	Point p1, p2;
	double len;
};

//constructor of combination classes
Line::Line(Point xp1, Point xp2) :p1(xp1), p2(xp2) {
	cout << "Calling constructor of Line" << endl;
	double x = static_cast<double>(p1.getX() - p2.getX());
	double y = static_cast<double>(p1.getY() - p2.getY());
	len = sqrt(x*x + y*y);
}

//copy of constructor of combination classes
Line::Line(Line &l) :p1(l.p1), p2(l.p2) {
	cout << "Calling the copy constructor of Line" << endl;
	len = l.len;
}

//main function
int E4_4()
{
	Point myp1(1, 1), myp2(4, 5);	//build objects of Point class
	Line line(myp1, myp2);		//build object of Line class
	Line line2(line);		//use copy of constructor to build a new object
	cout << "The length of the line is:";
	cout << line.getlen() << endl;
	cout << "The length of the line2 is: ";
	cout << line2.getlen() << endl;
	return 0;
}
*/

/*
//use stucture to stores students' informations
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

struct Student {
	int num;
	string name;
	char sex;
	int age;
};

int E4_7()
{
	Student stu = { 97001, "Lin Lin", 'F', 19 };
	cout << "Num: " << stu.num << endl;
	cout << "Name: " << stu.name << endl;
	cout << "Sex: " << stu.sex << endl;
	cout << "Age: " << stu.age << endl;
	
	return 0;
}
*/


/*
//use union to stores grade
#include<iostream>
#include<iomanip>
using namespace std;
class ExamInfo{
public:
	ExamInfo(string name, char grade)
		:name(name), mode(GRADE), grade(grade) {}
	ExamInfo(string name, bool pass)
		:name(name), mode(PASS), grade(grade) {}
	ExamInfo(string name, int percent)
		:name(name), mode(PERCENTAGE), percent(percent) {}
	void show();

private:
	string name;
	enum{
		GRADE,
		PASS,
		PERCENTAGE,
	}mode;
	union {
		char grade;
		bool pass;
		int percent;
	};
};

void ExamInfo::show(){
	//cout << name << ":";
	switch (mode) {
	case GRADE:
		cout << grade;
		break;
	case PASS:
		cout << (pass ? "PASS" : "FAIL");
		break;
	case PERCENTAGE:
		cout << percent;
		break;
	}
	cout << endl;
}

int E4_8()
{
	ExamInfo course1("English", 'B');
	ExamInfo course2("Calculus", true);
	ExamInfo course3("C++Programming", 85);
	course1.show();
	course2.show();
	course3.show();

	return 0;
}
*/


/*
//personal bank account
#include<iostream>
#include<cmath>
using namespace std;
class SavingsAccount{
private:
	int id;	//account
	double balance;	//balance
	double rate;	//year rate
	int lastDate;	//the lastdate to change balance
	double accumulation;	//the sum of all days balance

	//record an account
	void record(int date, double amount);
	//gain the sum of all days balance
	double accumulate(int date) const{
		return accumulation + balance*(date - lastDate);
	}

public:
	SavingsAccount(int date, int id, double rate );
	int getId(){ return id; }
	double getBalance() {return balance;}
	double getRate() { return rate; }
	void deposit(int date, double amount);	//save cash
	void withdraw(int date, double amount);	//take out cash
	//clearing interest
	void settle(int date);
	//show account's information
	void show();
};

//functions of class SavingsAccount
SavingsAccount::SavingsAccount(int date, int id, double rate)
:id(id), balance(0), rate(rate), lastDate(date), accumulation(0) {
	cout << date << "\t#" << id << "is created" << endl;
}
void SavingsAccount::record(int date, double amount) {
	accumulation = accumulate(date);
	lastDate = date;
	amount = floor(amount * 100 + 0.5) / 100;	//compute to two decimal places
	balance += amount;
	cout << date << "\t#" << id << "\t" << amount << "\t" << balance << endl;
}
void SavingsAccount::deposit(int date, double amount){
	record(date, amount);
}
void SavingsAccount::withdraw(int date, double amount) {
	if (amount > getBalance()) {
		cout << "Error:not enough money" << endl;
	}
	else record(date, -amount);
}
void SavingsAccount::settle(int date) {
	double interest = accumulate(date)*rate / 365;
	if (interest != 0) {
		record(date, interest);
	}
	accumulation = 0;
}
void SavingsAccount::show(){
	cout << "#" << id << "\tBalance:" << balance;
}

int E4_9()
{
	//establish some accounts
	SavingsAccount sa0(1, 21325303, 0.015);
	SavingsAccount sa1(1, 58320212, 0.015);
	//some accounts
	sa0.deposit(5, 5000);
	sa1.deposit(25, 10000);
	sa0.deposit(45, 5500);
	sa1.withdraw(60, 4000);
	//settle all accounts' interest
	sa0.settle(90);
	sa1.settle(90);
	//display accounts' information
	sa0.show();
	cout << endl;
	sa1.show();
	cout << endl;

	return 0;
}
*/

/*
//define a structure to store students' grade information
#include<iostream>
using namespace std;

enum Level { FRESHMAN, SOPHOMORE, JUNIOR, SENIOR };
enum Grade {A,B,C,D};
class Student{
public:
	Student(unsigned number, Level level, Grade grade) :
		number(number), level(level), grade(grade) {}
	void show();
private:
	unsigned number : 27;
	Level level : 2;
	Grade grade : 2;
};

void Student::show()
{
	cout << "Number:" << number << endl;
	cout << "Level:\t";
	switch (level){
	case FRESHMAN:
		cout << "freshman";
		break;
	case SOPHOMORE:
		cout << "sophomore" << endl;
		break;
	case JUNIOR:
		cout << "junior" << endl;
		break;
	case SENIOR:
		cout << "senior" << endl;
		break;
	}
	cout << "Grade:\t";
	switch (grade){
	case A:
		cout << "A" << endl;
		break;
	case B:
		cout << "B" << endl;
		break;
	case C:
		cout << "C" << endl;
		break;
	case D:
		cout << "D" << endl;
		break;
	}
	cout << endl;
}
int E4_10()
{
	Student s(12345678, SOPHOMORE, B);
	cout << "Size of Student:" << sizeof(Student) << endl;
	s.show();

	return 0;
}
*/

/*
//define a class Dog
#include<iostream>
using namespace std;

class Dog{
private:
	int itsAge;
	int itsWeight;
public:
	Dog(int initialAge=0, int initialWeight=5);
	void setAge(int age) {
		itsAge = age;
	}
	void setWeight(int weight) {
		itsWeight = weight;
	}
	int getAge() {
		return itsAge;
	}
	int getWeight(){
		return itsWeight;
	}
};
Dog::Dog(int initialAge, int initialWeight)
{
	itsAge = initialAge;
	itsWeight = initialWeight;
}

int P4_8()
{
	Dog Jack;
	cout << "Jack's age is:" << Jack.getAge()<<endl;
	cout << "Jack's weight is:" << Jack.getWeight()<<endl;
	Jack.setAge(7);
	Jack.setWeight(30);
	cout << "Now,Jack's age is:" << Jack.getAge()<<endl;
	cout << "Jack's weight is:" << Jack.getWeight() << endl;
	Dog Tom(3, 20);
	cout << "Tom's age is:" << Tom.getAge() << endl;
	cout << "Tom's weight is:" << Tom.getWeight() << endl;

	return 0;
}
*/

/*
//define a  class Rectangle 
#include<iostream>
using namespace std;
class Rectangle{
private:
	double itstop;
	double itsbottom;
	double itsright;
	double itsleft;
public:
	Rectangle(double top, double bottom, double right, double left);
	void setTop(double top) { itstop = top; }
	void setBottom(double bottom) { itsbottom = bottom; }
	void setRight(double right) { itsright = right; }
	void setLeft(double left) { itsleft = left; }
	double getTop() { return itstop; }
	double getBoobom(){ return itsbottom; }
	double getRight(){ return itsright; }
	double getLeft(){ return itsleft; }
	double area();
};

Rectangle::Rectangle(double top, double bottom, double right, double left)
{
	itstop = top;
	itsbottom = bottom;
	itsright = right;
	itsleft = left;
}

double Rectangle::area()
{
	double height = itstop - itsbottom;
	double width = itsright - itsleft;
	return height*width;
}

int P4_9()
{
	Rectangle rectangle(100, 20, 80, 50);
	cout << "the area of rectangle(100,20,80,50) is:" << rectangle.area() << endl;
	rectangle.setBottom(50);
	cout << "the area of rectangle(100,50,50,80) is:" << rectangle.area() << endl;

	return 0;
}
*/

/*
//define a class Person
#include<iostream>
using namespace std;

//define a class Date
class Date{
private:
	int year, month, day;
public:
	Date(int inityear, int initmonth, int initday);
	Date(Date &date);
	int getY();
	int getM();
	int getD();
};

Date::Date(int inityear, int initmonth, int initday)
{
	year = inityear;
	month = initmonth;
	day = initday;
}

Date::Date(Date &date)
{
	year = date.year;
	month = date.month;
	day = date.day;
}

int Date::getY()
{
	return year;
}

int Date::getM()
{
	return month;
}

int Date::getD()
{
	return day;
}

//define a class Person
class Person{
private:
	Date date1;
	int num;
	char *sex;
	int id;
public:
	Person(Date xdate);
	void setNum(int xnum) { num = xnum; }
	void setID(int xid) { id = xid; }
	void setSex(char *xsex) { sex = xsex; }
	int getNum() { return num; }
	int getID(){ return id; }
	char setSex(){ return *sex; }
	void show();
};

Person::Person(Date xdate) :date1(xdate)  {}
void Person::show()
{
	cout << "number\tsex\tbirthday\tid\n";
	cout << num << "\t" << sex << "\t" << date1.getY() << '/' << date1.getM() << '/' << date1.getD() << "\t" << id << endl;
}

int P4_10()
{
	Date date(1995, 3, 27);
	Person person(date);
	person.setNum(184);
	person.setSex("Man");
	person.setID(440582);
	person.show();

	return 0;

}
*/


/*
//define a class Rectangle and calculate the area
#include<iostream>
using namespace std;
class Rectangle{
private:
	double length, width;
public:
	Rectangle(double len, double wid);
	void setLength(double len) { length = len; }
	void setWidth(double wid) { width = wid; }
	void area();
};

Rectangle::Rectangle(double len, double wid)
{
	length = len;
	width = wid;
}

void Rectangle::area()
{
	cout << "the length is:" << length << endl;
	cout << "the width is:" << width << endl;
	cout << "the rectangle's area is:" << length*width*1.0 << endl;
}

int P4_11()
{
	Rectangle rectangle(5, 4);
	rectangle.area();
	rectangle.setLength(8);
	rectangle.area();

	return 0;

}
*/

/*
//define a class DataType
#include<iostream>
using namespace std;
class DataType{
	enum{
		character, integer, floating
	}varytype;
	union{
		char c;
		int i;
		float f;
	};
public:
	DataType(char ch) {
		varytype = character;
		c = ch;
	}
	DataType(int ii) {
		varytype = integer;
		i = ii;
	}
	DataType(float ff) {
		varytype = floating;
		f = ff;
	}
	void print();
};

void DataType::print()
{
	switch (varytype){
	case character:
		cout << "char:" << c << endl;
		break;
	case integer:
		cout << "integer:" << i << endl;
		break;
	case floating:
		cout << "float:" << f << endl;
		break;
	}
}

int P4_12()
{
	DataType A('a');
	DataType B(21);
	DataType C(21.f);
	A.print();
	B.print();
	C.print();

	return 0;
}
*/


/*
//define a class Circle and calculate the area
#include<iostream>
using namespace std;
#define PI 3.141592657
class Circle{
private:
	double radius;
	double area;
public:
	Circle(double r) { radius = r; }
	void setRadiuse(double r) { radius = r; }
	double getArea();
	void show();
};

double Circle::getArea()
{
	area = PI*radius*radius;
	return area;
}
void Circle::show()
{
	cout << "the circle's radius is:" << radius << endl;
	cout << "the circle's area is:" << area << endl;
}

int P4_12()
{
	Circle circle(1);
	circle.getArea();
	circle.show();
	circle.setRadiuse(2);
	circle.getArea();
	circle.show();

	return 0;
}
*/

/*
//define a class Tree and output the age
#include<iostream>
using namespace std;
class Tree{
private:
	int ages;
public:
	Tree(int age) { ages = age; }
	void grow(int years) { ages = ages + years; }
	void age();
};

void Tree::age()
{
	cout << "the tree's age is:" << ages << endl;
}

int P4_14()
{
	Tree tree(10);
	tree.grow(100);
	tree.age();

	return 0;
}
*/