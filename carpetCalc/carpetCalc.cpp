/***********************************************************************************************
         Programmer: manuva

         Narrative: a program that will allow the sales staff to correctly
					estimate the total cost of carpet, padding and installation for a
					room and a final total indicating all rooms.

         Inputs:     Rooms, i(counter), area, padding select - integers
					 Total, carpetCost, totalCarpetPrice, length, width, price, totalroom - doubles // set prices to 0
					 paddingCost, totalPAddingCost, installcost, totalarea, TotalInstall, cost as doubles

         Outputs:   Padding Choices, Price of Yards, Installation, Padding, Carpet, Total for Room and Grand Total for all rooms


         Operations:
		 1. prompt for number of rooms
		 2. Read in number of rooms
		 3. Use for loop to prompt and get cost of each room
		 4. prompt for length of room
		 5. read in length of room
		 6. prompt for width of room
		 7. read in length of room
		 8. Display padding choices
		 9. Prompt for padding choice (1-4 only)
		 10. use case switch to determine price of padding choice
		 11. Prompt for price of carpeting per sq yd for room #
		 12. read in price of carpeting
		 13. Calc and display area (l * w / 9 ) and add to total
		 14. Calc and display installation fees and add to total
		 15. calc and display padding fees and add to total
		 16. calc and display carpet cost and add to total
		 17. calc and display room # total
		 18. calc and display area, installation, padding, and carpet, grand total for all rooms
		 19. exit program upon key press

/*****************************************************************************************/



#include <iostream>
#include <string>
#include <math.h>
#include <conio.h> // for getch

using namespace std;

int main()
{
	int rooms,i,area,pad;
	double total=0,carpetcost,totalcarpetprice=0,l,w,price,prices,totalroom=0;
	double padcost,totalpadcost=0,installcost,totalarea=0,totalinstall=0,cost;

	cout<<"Enter the Number of Rooms: ";
	cin>>rooms;


	for(i=0;i<rooms;i++)
   {
		totalroom=0;
		cout << "Enter Length of Room " <<i+1 << ": ";
		cin >> l;

		cout << "Enter Width of Room " << i+1 << ": ";
		cin >> w;

		cout << "\n";

		cout<<"Padding Choices\n";
		cout << "   1. Good - $3 per square yard- [1-3yr Warranty]" << endl;
		cout << "   2. Better - $4 per square yard- [3-5yr Warranty]" << endl;
		cout << "   3. Best - $5 per square yard- [5-10yr Warranty]" << endl;
		cout << "   4. Excellent - $7 per square yard -[10-20yr Warranty]" << endl;
		cout << "\n";
		cout << "Enter Number of Padding choice (1-4): ";
		cin>>pad;

		switch(pad)
		{
			case 1:cost=3;
				break;
			case 2:cost=4;
				break;
			case 3:cost=5;
				break;
			case 4:cost=7;
				break;
			default: cout<<"Invalid padding choice! \n program aborting!\n";
//				system("pause");
				return 0;
        }

		cout <<"Enter price of Carpeting per sq yd of Room " << i+1 << ": ";
		cin>>price;

		cout << "\n";

		area=ceil(l*w/9.);
		totalarea+=area;

		carpetcost=price*area;

		totalroom+=carpetcost;
		totalcarpetprice+=carpetcost;




		padcost=cost*area;
		totalroom+=padcost;
		totalpadcost+=padcost;
		totalcarpetprice+=padcost;
		installcost=area*5;
		totalinstall+=installcost;
		totalroom+=installcost;
		totalcarpetprice+=installcost;
		total+=carpetcost;

		cout << "Room " << i+1 << " Yards Required = " << area << " sq yds\n";
		cout << "Room " << i+1 << " Installation = $" << installcost << endl;
		cout << "Room " << i+1 << " Padding Cost = $" << padcost << endl;
		cout << "Room " << i+1 << " Carpet Cost = $" << carpetcost << endl;
		cout << "Room " << i+1 << " Total Cost = $" << totalroom << endl << endl;

       }
       cout << "\nFor " << i << " Room(s):" << endl;
       cout << "Total Square Yards required = " << totalarea << endl;
       cout << "Total Installation = $" << totalinstall << endl;
       cout << "Total Padding = $" << totalpadcost << endl;
       cout << "Total Carpet = $" << total << endl << endl;
       cout << "Grand Total = $" << totalcarpetprice << endl;
//	   system("pause");

	getch();
    return 0;
}
