// The implementation file for the MyTime class
#include "MyTime.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

// Constructors

MyTime::MyTime(int h, int m){
	hours = h;
	minutes = m;
}

// Member and friend functions
void MyTime::Reset(int h, int m){
	hours = h;
	minutes = m;
}

void MyTime::simplify(){
    hours += minutes/60;
	minutes = minutes%60;
}

MyTime MyTime::operator + (const MyTime& t) const {
	MyTime tmp;
    tmp.hours = hours + t.hours;
	tmp.minutes = minutes + t.minutes;
	tmp.simplify();
	return tmp;
}

MyTime MyTime::operator - (const MyTime& t) const {
	MyTime tmp;
	tmp.minutes = abs((hours * 60 + minutes) - (t.hours * 60 + t.minutes));
	tmp.simplify();
	return tmp;
}

MyTime MyTime::operator / (int num) const {
	MyTime tmp;
	tmp.minutes = hours * 60 + minutes;
	tmp.minutes /= num;
	tmp.simplify();
	return tmp;
}

MyTime MyTime::operator * (int num) const {
	MyTime tmp;
	tmp.minutes = hours * 60 + minutes;
	tmp.minutes *= num;
	tmp.simplify();
	return tmp;
}

bool MyTime::operator == (const MyTime& t) const {
	return hours == t.hours && minutes == t.minutes;
}

bool MyTime::operator < (const MyTime& t) const {
	return (hours*60 + minutes) < (t.hours*60 + t.minutes);
}

bool MyTime::operator <=(const MyTime& t) const {
	return (hours*60 + minutes) <= (t.hours*60 + t.minutes);
}

void MyTime::input(istream&ins){
	char junk;
	ins >> hours;
  	ins.get(junk);
	ins >> minutes;
	simplify();
}

void MyTime::output(ostream& outs) const {
	outs << hours << ':' << setw(2) << setfill('0') << minutes;
}


ostream& operator <<(ostream& outs, const MyTime& t){
    t.output(outs);
	return outs;
}

istream& operator >> (istream& ins, MyTime& t){
	t.input(ins);
	return ins;
}