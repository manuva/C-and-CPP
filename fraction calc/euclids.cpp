/************************************************************************

Program Name: Fraction Calculator

Programmer: manuva

Description: Adds, Subtracts, Multiplies and Divides two given Fractions.
			 Displays the result in simplest form using euclid's algorithm.
			 (http://www.jimloy.com/number/euclids.htm)

**************************************************************************/

#include <iostream>
#include <conio.h>

using namespace std;

class CFrac
{
private:
	int numerator, denominator;
	//void simplify();
	void defaultFrac();
public:
	CFrac(int = 0, int = 1);
	~CFrac();
	CFrac add(const CFrac&) const; //adds the current object with the parameter object.
									//parameter object is passed by const reference, so it cannot be modified.
									//the current object also cannot be modified either due to the const at the end.
	void showFrac() const; //Accessor, current objects data remains the same by this function
	CFrac subtract(const CFrac&) const;
	CFrac multiply(const CFrac&) const;
	CFrac divide(const CFrac&) const;
	//void getChoice() const;
	void simplify();
	void setFrac();  //mutator, the current object's data will be changed with this function
	//void setChoice() const;
};
//end of class def

//start member function definitions
void CFrac::simplify() //euclids algorithm
{
	int a,b;
	a = numerator;
	b = denominator;
	while(a!=b)
	{
	if(a>b)
		a -= b;
	else
		b -= a;
	}
	numerator/=a;
	denominator/=a;
}

CFrac::CFrac(int n, int d)
{
	numerator = n;
	denominator = d;
}

CFrac::~CFrac() {}

void CFrac::showFrac() const
{
	if (denominator > numerator) //is denominator greater than numerator?
	cout << numerator << "/" << denominator; //if so display normal fraction
	else //otherwise, we display the whole number and its fractional part
		if(numerator % denominator != 0)
			cout << numerator/denominator << " " //divide and display a space
				<< numerator % denominator << "/" << denominator;
}

CFrac CFrac::add(const CFrac& otherFrac) const
{
	CFrac sumFrac;
	sumFrac.numerator = numerator*otherFrac.denominator+otherFrac.numerator*denominator;
	sumFrac.denominator = denominator*otherFrac.denominator;
	return sumFrac;
}

CFrac CFrac::subtract(const CFrac& otherFrac) const
{
	CFrac subFrac;
	subFrac.numerator = numerator * otherFrac.denominator - otherFrac.numerator * denominator;
	subFrac.denominator = denominator * otherFrac.denominator;
	return subFrac;
}

CFrac CFrac::multiply(const CFrac& otherFrac) const
{
	CFrac multFrac;
	multFrac.numerator = numerator * otherFrac.numerator;
	multFrac.denominator = denominator * otherFrac.denominator;
	return multFrac;
}

CFrac CFrac::divide(const CFrac& otherFrac) const
{
	CFrac divFrac;
	divFrac.numerator = numerator * otherFrac.denominator;
	divFrac.denominator = denominator * otherFrac.numerator;
	return divFrac;
}

void CFrac::setFrac()
{
	char slash;
	cin >> numerator >> slash >> denominator;
}

void CFrac::defaultFrac()
{
	numerator = 0;
	denominator = 1;
}

//start of client code

int main()
{
	bool exit=false;

	//do
	//{
		int num;
		int den;
		CFrac num1, num2;
		//CFrac num1(1,2), num2(3,5); //this was for testing
		CFrac result;
		int choice;
		bool error;
		//char slash
		cout << endl;
		cout << "********Fraction Calculator********" << endl << endl;
		do{
			error=false;

			cout << "Enter a number from 1 to 5\n"
				<< "1 -- Add 2 Fractions\n"
				<< "2 -- Subtract 2 fractions" << endl
				<< "3 -- Multiply 2 Fractions" << endl
				<< "4 -- Divide 2 Fractions" << endl
				<< "5 -- Exit Application\n"
				<< "\nEnter a choice --> ";
				cin >> choice;
				cout << endl;
		}while((choice !=1)&&(choice !=2)&&(choice !=3)&&(choice !=4)&&(choice !=5)
				&& cout << "\n********Invalid Choice --- Try Again!********\n" << endl );

		switch (choice)
		{
		case 1: //addition
			cout << endl;
			cout << "Enter a fraction (e.g. 1/2) ";
			num1.setFrac(); //prompt for frac1
			cout << endl;
			cout << "Enter a fraction (e.g. 1/2) ";
			num2.setFrac(); //prompt for frac2
			cout << endl;
			num1.showFrac(); //display user's frac1
			cout << " + ";
			num2.showFrac(); //display user's frac2
			cout << " = ";
			result = num1.add(num2);
			result.simplify();
			result.showFrac();
			cout << endl;
			break;
		case 2: //subtract
			cout << endl;
			cout << "Enter a fraction (e.g. 1/2) ";
			num1.setFrac();
			cout << endl;
			cout << "Enter a fraction (e.g. 1/2) ";
			num2.setFrac();
			cout << endl;
			num1.showFrac();
			cout << " - ";
			num2.showFrac();
			cout << " = ";
			result = num1.subtract(num2);
			result.simplify();
			result.showFrac();
			cout << endl;
			break;
		case 3: //multiply
			cout << endl;
			cout << "Enter a fraction (e.g. 1/2) ";
			num1.setFrac();
			cout << endl;
			cout << "Enter a fraction (e.g. 1/2) ";
			num2.setFrac();
			cout << endl;
			num1.showFrac();
			cout << " * ";
			num2.showFrac();
			cout << " = ";
			result = num1.multiply(num2);
			result.simplify();
			result.showFrac();
			cout << endl;
			break;
		case 4: //divide
			cout << endl;
			cout << "Enter a fraction (e.g. 1/2) ";
			num1.setFrac();
			cout << endl;
			cout << "Enter a fraction (e.g. 1/2) ";
			num2.setFrac();
			cout << endl;
			num1.showFrac();
			cout << " / ";
			num2.showFrac();
			cout << " = ";
			result = num1.divide(num2);
			result.simplify();
			result.showFrac();
			cout << endl;
			break;
		case 5: //exit app
			exit;
			break;
		default: cout << "Input is not between 1 and 5!\n";
			break;
		}
	//}while(exit);

	cout << endl;
	system("pause");
	return 0;
}
