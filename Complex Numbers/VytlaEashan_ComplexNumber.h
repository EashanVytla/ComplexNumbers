// Eashan Vytla
// Grade: 9
// 5/14/2020
// Honors Computer Programming 3
// Project: Checkbook
// File: circle.h
// More Projects on Github: https://github.com/EashanVytla
// The purpose of this program is to introduce object oriented programming to calculate the circumfrence of a circle

#pragma once

#include <iostream>
#include <sstream>
#include <string.h>
#include <Math.h>

using namespace std;

class ComplexNumber {
private:
	//Private Member Data
	float mya;
	float myb;
	string* split(char charr[]);
	ComplexNumber parse(string complexnumber);
	bool contains(string complexnumber, char value);
	bool positiveb = true;
	const double PI = 3.14159265358797;
	bool switched = false;

public:
	//Public Member Data
	ComplexNumber();
	ComplexNumber(float real, float imaginary);
	ComplexNumber(string complexnumber);
	ComplexNumber(const ComplexNumber& complexnumber);
	ComplexNumber operator+(const ComplexNumber& complexnumber);
	ComplexNumber operator*(const ComplexNumber& complexnumber);
	ComplexNumber operator/(const ComplexNumber& complexnumber);
	ComplexNumber operator-(const ComplexNumber& complexnumber);
	void operator=(const ComplexNumber& complexnumber);
	ComplexNumber operator^(int power);
	ComplexNumber RotateByDegrees(float degrees);
	ComplexNumber RotateByRadians(float radians);
	ComplexNumber Conjugate(ComplexNumber complexnumber);
	ComplexNumber* Root(int n);
	float magnitude();
	void Graph(ComplexNumber complexnumber);
	string ToString();
	ComplexNumber multiply(const ComplexNumber& complexnumber, const ComplexNumber& complexnumber2);
	ComplexNumber Conjugate();
	float geta();
	float getb();
	
};

ComplexNumber::ComplexNumber() { //Default Constructor
	mya = 0; 
	myb = 0;
}

ComplexNumber::ComplexNumber(float real, float imaginary) { //Regular Input Fill Constructor
	mya = real;
	myb = imaginary;
}

ComplexNumber::ComplexNumber(string complexnumber) { //String Input Fill Contructor
	ComplexNumber newcn = parse(complexnumber);
	mya = newcn.mya;
	myb = newcn.myb;
}

ComplexNumber::ComplexNumber(const ComplexNumber& complexnumber) { //Copy Contructor
	mya = complexnumber.mya;
	myb = complexnumber.myb;
}

//Get function for private member data 
float ComplexNumber::geta() { 
	return mya;
}

float ComplexNumber::getb() {
	return myb;
}

//Magnitude or distance away from the origin, of the complex number
float ComplexNumber::magnitude() {
	return sqrtf((mya * mya) + (myb * myb));
}

//Rotate the Complex Number by degrees
ComplexNumber ComplexNumber::RotateByDegrees(float degrees) {
	ComplexNumber cn;
	cn.mya = magnitude() * cosf(atan2(myb, mya) + (degrees * (PI / 180)));
	cn.myb = magnitude() * sinf(atan2(myb, mya) + (degrees * (PI / 180)));

	return cn;
}

//Return the conjugate of the complex number
ComplexNumber ComplexNumber::Conjugate() {
	return ComplexNumber(mya, -myb);
}

//Rotate the Complex Number by Radians
ComplexNumber ComplexNumber::RotateByRadians(float radians) {
	ComplexNumber cn;
	cn.mya = magnitude() * cosf(atan2(myb, mya) + radians);
	cn.myb = magnitude() * sinf(atan2(myb, mya) + radians);

	return cn;
}

//Find the nth root of the complex number
ComplexNumber* ComplexNumber::Root(int n) {
	ComplexNumber* cn = new ComplexNumber[n];
	for (int k = 0; k < n; k++) {
		cn[k].mya = pow(magnitude(), (1.0 / n)) * (cosf((atan2(myb, mya) + ((2 * PI) * k)) / n));
		cn[k].myb = pow(magnitude(), (1.0 / n)) * (sinf((atan2(myb, mya) + ((2 * PI) * k)) / n));
	}
	return cn;
}

//Parse the string input complex number (Also used in the string input constructor).
ComplexNumber ComplexNumber::parse(string complexnumber) {
	int length = complexnumber.length() + 1;
	char* cnchararr = new char[length];
	strcpy_s(cnchararr, length, complexnumber.c_str());
	string* target = new string[2];

	target = split(cnchararr);

	float a = 0;
	float b = 0;

	a = strtof(target[0].c_str(), NULL);
	b = strtof(target[1].c_str(), NULL);
	if (!positiveb) {
		if (switched) {
			a = -a;
		}
		else {
			b = -b;
		}
	}
	delete[] cnchararr;
	return ComplexNumber(a, b);
}

//Converts the complex number into a readable format for the user.
string ComplexNumber::ToString() {
	std::ostringstream strout;
	strout << mya << showpos << myb << "i";
	return strout.str();
}

//Splits the complex number into REAL portion (mya) and IMAGINARY portion (myb)
string* ComplexNumber::split(char charr[]) {
	int leftoff = 0;
	string* target = new string[2];
	for (int j = 0; j < sizeof(charr); j++) {
		if (charr[j] == '+' || charr[j] == ' ' && j != 0) {
			leftoff = j;
			positiveb = true;
			break;
		}
		else if (charr[j] == '-' && j != 0 || charr[j] == ' ' && j != 0) {
			leftoff = j;
			positiveb = false;
			break;
		}
		else {
			target[0] += charr[j];
		}
	}
	for (int c = leftoff + 1; c <= sizeof(charr); c++) {
		target[1] += charr[c];
	}

	if (contains(target[0], 'i')) {
		string temp;
		temp = target[1];
		target[1] = target[0];
		target[0] = temp;
		switched = true;
	}

	if (target[1].compare(string("i")) == 1) {
		target[1] = "1";
	}

	return target;
}

//Overloaded operator functions:
ComplexNumber ComplexNumber::operator+(const ComplexNumber& complexnumber) { //+ - Add
	return ComplexNumber(mya + complexnumber.mya, myb + complexnumber.myb);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber& complexnumber) { //(-) - Subtract
	return ComplexNumber(mya - complexnumber.mya, myb - complexnumber.myb);
}

void ComplexNumber::operator=(const ComplexNumber& complexnumber) {          //= - Equals
	mya = complexnumber.mya;
	myb = complexnumber.myb;
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber& complexnumber) { //* - Multiply
	return multiply(ComplexNumber(mya, myb), complexnumber);
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber& complexnumber) { //(/) - Divide
	float newDenom = multiply(complexnumber, ComplexNumber(complexnumber.mya, -complexnumber.myb)).mya;
	ComplexNumber newTop = multiply(ComplexNumber(mya, myb), ComplexNumber(complexnumber.mya, -complexnumber.myb));
	return ComplexNumber(newTop.mya / newDenom, newTop.myb / newDenom);
}

ComplexNumber ComplexNumber::operator^(int power) {                          //^ - Exponent
	ComplexNumber finalnum = ComplexNumber(mya, myb);
	for (int i = 1; i < power; i++) {
		finalnum = multiply(finalnum, ComplexNumber(mya, myb));
	}
	return finalnum;
}

ComplexNumber ComplexNumber::multiply(const ComplexNumber& complexnumber, const ComplexNumber& complexnumber2) {
	float newa = (complexnumber.mya * complexnumber2.mya) - (complexnumber.myb * complexnumber2.myb);
	float newb = (complexnumber.mya * complexnumber2.myb) + (complexnumber.myb * complexnumber2.mya);
	return ComplexNumber(newa, newb);
}

//Contains function
bool ComplexNumber::contains(string complexnumber, char value) {
	int length = complexnumber.length() + 1;
	char* cnchararr = new char[length];
	strcpy_s(cnchararr, length, complexnumber.c_str());

	for (int i = 0; i < length - 1; i++) {
		if (cnchararr[i] == value) {
			return true;
			break;
		}
	}

	return false;
}