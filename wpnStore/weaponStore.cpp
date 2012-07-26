/* 
 * File:   main.cpp
 * Author: Brocolli
 *
 * Created on February 23, 2012, 9:49 AM
 */

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

/*
 * 
 */
int main(void) {
    
    using std::cout;
    using std::cin;
    using std::string;
    string name;
    cout << "Welcome to the weapon store, noble knight."
            << " Come to equip the army again?\n"
            << "What is your name? ";
    cin >> name;
    cout << "Well then, Sir " << name.c_str()
            << ", let's get shopping\n";
    double gold = 50.0;
    int silver = 8;
    const double SILVERPERGOLD = 6.7;
    const double BROADSWORDCOST = 3.6;
    unsigned short broadswords;
    cout << "You have " << gold << " gold pieces and "
            << silver << " silver.\n";
    gold += silver / SILVERPERGOLD;
    cout<< "How many broadswords would you like to buy?"
            << " (3.6 gold each) ";
    cin >> broadswords;
    gold = gold - broadswords * BROADSWORDCOST;
    cout << "\nThank you. You have " << gold << " left.\n";
    silver = (int)((gold - (int)gold) * SILVERPERGOLD);
    gold = (double)((int)(gold));
    cout << "That is equal to " << gold << " gold and "
            << silver << " silver. \n"
            << "Thank you for shopping at the Weapon Store. "
            << "Have a nice day, Sir " << name.c_str() << ".\n";
    return 0;
    
}

