/*
Name: Jake Deeks (JakeDeeks@my.unt.edu)
Instructor: Joseph Helsing
Description: This project is all about grabbing an input file from the user, and doing manipulation with the file that will create
a menu for a kitchen using a class of objects and a bit-vector representation for the dishes' ingredients. Then, manipulating the bitvectors 
of the dishes to find out extra information about it. 
*/
#include <vector>
#include <iostream>
#include <fstream>
#include <istream>
#include <cstdlib>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

void Welcome();			//Welcome Function initializing
void LoadFile();		//LoadFile Function initializing

int main()
{
	system("clear");			//Clearing terminal previously used
  Welcome();						//Welcoming user
  
	cout << "\t      WELCOME TO KITCHEN IMPOSSIBLE" << endl;
	
	LoadFile();			//Calling Load file and doing Manipulations with file
	
	return 0;
}
