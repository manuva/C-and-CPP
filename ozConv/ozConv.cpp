// exercise.cpp : Defines the entry point for the console application.
//

#include <conio.h>
//#include <iomanip>
#include <iostream>

using namespace std;

class CWeight
{
private:
	int pounds, ounces;
public:
	CWeight(int lb = 0, int oz = 0);	//combined default and argument constructor
	void setWt();		//prompt for and get input for pounds and ounces
	void setWt(int lb, int oz);	//sets current object with parameter lb and oz
	void showWt() const;	//display the current object's pounds and ounces
	int getPounds();		//returns pounds
	int getOunces();	//returns ounces
	CWeight addWt (const CWeight& wt) const;
	//add current object and parameter wt and return the total
	//to add: add pounds to pounds and ounces to ounces without adjusting
	CWeight subtractWt (const CWeight& wt) const;
	//subtract parameter wt from current object and return the difference
	//to subtract: subtract pounds from pounds and ounces from ounces without adjusting
};

CWeight CWeight::addWt(const CWeight& wt) const
{
	CWeight objWt;
	objWt.ounces = ounces + wt.ounces;
	objWt.pounds = wt.pounds + pounds;

	return objWt;
}

int addWt(int&, int&);

CWeight CWeight::subtractWt(const CWeight& wt) const
{
	CWeight objWt;
	objWt.pounds = pounds - wt.pounds;
	objWt.ounces = ounces - wt.ounces;

	return objWt;
}

void CWeight::showWt() const
{
	cout << "Pounds: " << pounds << " Ounces: " << ounces << endl;
	//cout << "Ounces: " << ounces << endl;
}

CWeight::CWeight(int lb, int oz)
{
	pounds = lb;
	ounces = oz;
}

void CWeight::setWt(int lb, int oz)
{
	pounds = lb;
	ounces = oz;
}

void CWeight::setWt()
{
	cout << "Enter a weight in pounds and ounces: ";
	cin >> pounds >> ounces;
}

int CWeight::getOunces()
{
	return ounces;
}

int CWeight::getPounds()
{
	return pounds;
}

//start of client code
int main()
{
	CWeight w1(5, 8);
	//CWeight w2(5, 5); //for calc function testing/debugging
	CWeight w2;
	CWeight w3;

	//CWeight wt = w1; //assign w1 to wt

	//w3 = w2; //assign object w2 to object w3

	/****************PROMPT AND GET WEIGHT************/
	//cout << "\n\nEnter Weight1: ";
	//w1.setWt();

	//cout << "\nWeight2 - ";
	//w2.setWt();

	//cout << "\nEnter Weight3: ";
	//w3.setWt();

	/***************display weight values************/
	cout << "w1: ";
	w1.showWt();
	cout << endl;

	cout << "w2: ";
	w2.showWt();
	cout << endl;

	cout << "w3: ";
	w3.showWt();
	cout << endl;

	/***************CALCULATIONS**************/

	cout << "With w1 and w2 added, w3 = ";
	w3 = w2.addWt(w1);
	w3.showWt();

	cout << "With w2 subtracted from w1, w3 = ";
	w3 = w1.subtractWt(w2);
	w3.showWt();

	_getch();
	return 0;
}