/*********************************************************

program name: Date Validation
programmer: manuva

Narrative: This program will check for a valid date when given the month, day, and year (mm/dd/yyyy) format


Input: User will enter a date in mm/dd/yyyy format (getDate function)





Constants: none

Constraints?:
	Months will be validated that it is proper and 1-12
	Days will be validated and make sure it is 1-28(feb), 1-29(leap year in feb), 1-30, and 1-31, respectively
	Year will be validated to make sure it is between 999 and 10000


Function prototypes:

	getDate - takes user input and stores it
	ckDate - validates the user input for each month/day/year
	displayMsg - Display the proper message indicating a good or bad date



Level 0 - main:


	1) call to functions to prompt and get date
	2) call to function to validate date
	3) call to function to display date and error message if any
	4) while loop to prompt again until user ends file

level 1 operation - getDate(month, day, year)
	a)prompt user for input
	b) store input

level 1 operation - ckDate (month, day, year)
	a)if year is greaterthan or equal to 999 and less than or equal to 10000
	b)if month is 1-12
	c)switch for determining the amount of days in each month
		1)cases 1,3,5,7,8,10,12 are 31 days long
			a)if statement to determine if days is between 1-31
			b) else bad day
		2) case 2 is 28 days long and 29 days if a leap year
			a) determine if year given is leap year, if so see if range is 1-29
			b) else given year is not leap year and is 1-28

		3) cases 4,6,9,11 are 30 days long
			a)determine if days is between 1-30 for months 4,6,9,11
			b) else bad day

		4)set message number to display proper messages for the above

	5)return messagenumber

level 1 operation - displaymsg(messagenumber)
a) switch statement to determine the messageNumber based on input
b)  case 0: Good date
	case 1: bad year
	case 2: bad month
	case 3: bad day not 1-31
	case 4: bad day not 1-30
	case 5: bad day not 1-29 (leap year)
	case 6: bad day not 1-28

***********************************************************/
/************************************************************





******************************************************************/


#include <iostream> // for cin and cout
#include <conio.h> //for getch

using namespace std;


//declare variables
int month;
int day;
int year;
int messageNumber;
void getDate( int&, int&, int&);
int ckDate( int, int, int);
void displayMsg( int);

int main()
{

getDate(month, day, year); //call to get date func
ckDate (month, day, year); //call to check date func
displayMsg (messageNumber); // call to display message func

//loop to ask user for more input
while(cin)
{
	getDate(month, day, year);
	ckDate (month, day, year);
	displayMsg (messageNumber);
	if(cin.eof()) // indicates end of file by user ctrl+z
	{
	cout << "Ending Program" << endl;
	cout << "Good Bye" << endl;
	//system("pause");
	_getch();
	return 0;
	}
}






}

void getDate( int& month, int& day, int& year)
{
	char ch; // for the "/" character from user
	cout << "Enter a date (mm/dd/yyyy): "; //output to enter date
	cin >> month >> ch >> day >> ch >> year; //storing user input
}

int ckDate(int month, int day, int year)
{


	if (year >= 999 && year <= 10000){ //check if year is in valid range
		if(month >= 1 && month <= 12){ //check if month is in valid range
			messageNumber = 0; //display good date

			switch(month){ //switch for determining the amount of days for the given month
			case 1: //january
				if(day >= 1 && day <= 31){
					messageNumber = 0; //display good date
				}
				else{
					messageNumber = 3; //bad day 1-31
				}
			case 2: //feb
				if(year % 4 == 0 && year % 100 > 0){ //check if year is aleap year
					if(day >= 1 && day <= 29){ //check if amount of days is correct for leap year, year
						messageNumber = 0; //good date
				}
					else{
						messageNumber = 5; //bad day not 1-29
					}
				}
				else if(day >= 1 && day <= 28){
					messageNumber = 0; //good date
				}
				else{
					messageNumber = 6; // bad day not 1-28
				}
				break;
			case 3: //march
				if(day >= 1 && day <= 31){
					messageNumber = 0; //good date
				}
				else{
					messageNumber = 3; //bad day not 1-31
				}

			case 5: //may
				if(day >= 1 && day <= 31){
					messageNumber = 0; //good date
				}
				else{
					messageNumber = 3; //bad day not 1-31
				}

			case 7: //july
				if(day >= 1 && day <= 31){
					messageNumber = 0; //good date
				}
				else{
					messageNumber = 3; //bad day not 1-31
				}
			case 8:  //august
				if(day >= 1 && day <= 31){
					messageNumber = 0; //good ddate
				}
				else{
					messageNumber = 3; // bad day not 1-31
				}

			case 10: //october
				if(day >= 1 && day <= 31){
					messageNumber = 0;
				}
				else{
					messageNumber = 3; // bad day not 1-31
				}

			case 12: //december
				if(day >= 1 && day <= 31){
					messageNumber = 0;
				}
				else{
					messageNumber = 3; // bad day not 1-31
				}
			}
			switch(month){ //added another switch because it was not validating correctly when using these cases with
							//the last switch
			case 4: //april
				if(day >= 1 && day <= 30){
					messageNumber = 0; //good day
				}
				else{
					messageNumber = 4; // bad day not 1-30
				}
			case 6: //june
				if(day >= 1 && day <= 30){
					messageNumber = 0;
				}
				else{
					messageNumber = 4; // bad day not 1-30
				}
			case 9: //september
				if(day >= 1 && day <= 30){
					messageNumber = 0;
				}
				else{
					messageNumber = 4;// bad day not 1-30
				}
			case 11: //november
				if(day >= 1 && day <= 30){
					messageNumber = 0;
				}
				else{
					messageNumber = 4;// bad day not 1-30
				}
			}
		}
		else{
			messageNumber = 2; //bad month (not in 1-12 range)
		}
	}
	else{
		messageNumber = 1; //bad year (not in 999-10000 range)
	}




	return messageNumber;

}

void displayMsg(int messageNumber)
{
	switch (messageNumber) //display message from validation
	{
	case 0:
		cout << month << '/' << day << '/' << year << " - good date " << endl;
		break;
	case 1:
		cout << month << '/' << day << '/' << year << " - Bad Year" << endl;
		break;
	case 2:
		cout << month << '/' << day << '/' << year << " - Bad Month" << endl;
		break;
	case 3:
		cout << month << '/' << day << '/' << year << " - Bad Day not 1-31" << endl;
		break;
	case 4:
		cout << month << '/' << day << '/' << year << "- Bad Day not 1-30" << endl;
		break;
	case 5:
		cout << month << '/' << day << '/' << year << "- bad Day noy 1-29" << endl;
		break;
	case 6:
		cout << month << '/' << day << '/' << year << "- bad Day not 1-28" << endl;
		break;
	}
}
