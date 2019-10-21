#include <vector>
#include <iostream>
#include <fstream>
#include <istream>
#include <cstdlib>
#include <sstream>
#include <string>
#include "Menu.h"
#include <iomanip> 

void Welcome();			//Welcome Function initializing
void LoadFile();		//LoadFile Function initializing
vector<string> Split(string str, char delimiter);	//Split Function initializing
Menu Union(Menu A,Menu B);
Menu Intersection(Menu A, Menu B);
Menu Difference(Menu A, Menu B);
Menu SymDif(Menu A,Menu B);
Menu Complement(Menu C);


void Welcome()                          //Function definition of Welcome
        {
        cout << "\t------------------------------------------\n";
        cout << "\t    Computer Science And Engineering\n";
        cout << "\t   CSCE 2110 - Computer Foundations 2\n";
        cout << "\t Jake Deeks Jad0420 JakeDeeks@my.unt.edu\n";
        cout << "\t------------------------------------------\n\n";
	
        }


void LoadFile()				//Loading Input file and Proceeding to Do Manipulation with data
{
	Menu Universal,Dish,More1,Least1,Exactly1,NotUsed;	//Class Variables for each function
  int size;								//Size of the Universal Ingredients
	string str,temp2,name;	//String temp variable placeholders for read in
	char Input_file[20];		//Char array for input file name
  char Delimiter = ',';		//setting the delimiter for the comma spliting function
	ifstream inf;						//opening stream to read file
	
	vector<string> Ingredients;	//vector of strings to store each dishes' ingredients
	vector<Menu> Temp;			//Vector of class menu for the dishes
	vector<string> UniversalS;	//local universal ingredient string vector
	
	bool GoodDish = true;	//Boolean variable to check if a dish has unavaible ingredient
  
	cout << "Please Input the File you would like to read from: ";	//Asking for input file
	cin >> Input_file;		//reading in input file

  
	inf.open(Input_file);	//Opening Input File
	if (inf.fail())				//If Loop to test if file works
	{
		cout << "File \"" << Input_file << "\" failed to open." << endl;
		exit(EXIT_FAILURE);
		return;
	}
 cout <<endl;
	
 getline(inf, str, '\n'); //grabbing whole line for universal ingredients
 Universal.SetIngredient(Split(str,Delimiter));//Splitting the comma demilited string to get universal set
 
 
 UniversalS = Universal.GetIngredient();	//Getting Local string vector holding the universal ingredients to use for inserting bitvector
	
 size = Universal.GetSize();		//Getting a local integer of the universal Ingredients
 vector<bool> TempBool(size);		//Creating a bitvector with the size of the Universal Ingredients
 Least1.SetMember(TempBool);		//Creating an Class object variable bitvector Least1 with size of Universal set for manipulations		
 More1.SetMember(TempBool); 		//Creating an Class object variable bitvector More1 with size of Universal set for manipulations
 Exactly1.SetMember(TempBool); 	//Creating an Class object variable bitvector Exactly1 with size of Universal set for manipulations
 NotUsed.SetMember(TempBool);		//Creating an Class object variable bitvector NotUsed with size of Universal set for manipulations
  
 
  
 while(getline(inf,name,':'))		//Reading File till it can no longer grab a new line
 {
	GoodDish = true;							//Initializing the the dish is good
  getline(inf,temp2,'\n');		//getting the full Dish line with Name + Ingredient
  Dish.SetName(name);					//Setting the Dish name to object class
	Ingredients = Split(temp2,Delimiter); 	//Getting the ingredients of the dish to store and split in vector of strings 
	Dish.SetIngredient(UniversalS);		//Setting the Universal Ingredients to compare to in Dish variable
	Dish.SetMember(TempBool);					//Setting Member size to size of Universal Ingredients
	
	for(int i =0;i<Ingredients.size();i++)		//For loop to check if dish ingredients are apart of of the universal ingredients
	{
		if(!Dish.Insert(Ingredients.at(i)))	//If ingredient is not apart, signal that is bad dish and print out to user
		{
			cout << "The dish " << name << " contains " << Ingredients.at(i)<< " which is not something we have." <<endl;
		GoodDish = false;	
		}
	}
	
	 if(GoodDish == true)	//If statement to check if the dish pass previous check
	{
	 Temp.push_back(Dish);			//Creates Dish
	}
 }
	
	cout << setw(16) << "Dish Name:";		//Printing out Dish Name
	Universal.PrintUniversal();													//Prints out the Universal Ingredients

	/*for(int t =0;t<UniversalS.size();t++)					//Making it look good border
  {
      cout << "-------------";
  }
  cout << endl;*/
 
  for(int t=0;t<Temp.size();++t)			//For loop to print out the Name of a dish and the bitvector for that dish
  {
    cout << setw(15) << Temp.at(t).GetName() << ":" ;
    Temp.at(t).PrintBit();
  }
	
cout << "--------------";	
for(int t =0;t<UniversalS.size();t++)				//Making it look good border
  {
      cout << "------------";
  }
  cout << endl;
 
	for(int j=0;j<Temp.size();j++)			//For loop to union every dish together to get at a set where the ingredients appear at least once 
	{
		Least1 = Union(Least1,Temp.at(j));				//Calling Union with empty boolean vector and each dish repetitively 
	}
	
	for(int y=0;y<Temp.size()-1;++y)						//Double For loop to get a set when the ingredients appear more than once for the dishes 
	{
		for(int t = y+1; t < Temp.size();++t)
		{
		NotUsed = Intersection(Temp.at(y),Temp.at(t));				//Intersecting all the 2 dishes together to get the repeated ingredients  
		More1 = Union(More1,NotUsed);													//Unioning the answer of previous intersection with an initially empty set which will than continue to be used to union with next answer
		}
	}
	Exactly1 = Difference(Least1,More1);	//using Difference to get Extacly1 by taking the occurence of it appearing at least once and differencing it against when it appears more than once to get those that appear at least once but not more than 1
	NotUsed = Complement(Least1);					//Complementing Least1, due to Least1 having all possible ingredients used to get the ingredients not used at all
	

	
	
  cout << setw(16) << "At Least One:";			//Printing Out What Type of Manipulation We are checking for			
  Least1.PrintBit();												//Printing out Results of previous line manipulation
  cout << setw(16) << "More Than One:";			//Printing Out What Type of Manipulation We are checking for
  More1.PrintBit();												//Printing out Results of previous line manipulation
  cout << setw(16) << "Exactly One:";			//Printing Out What Type of Manipulation We are checking for
  Exactly1.PrintBit();												//Printing out Results of previous line manipulation
  cout << setw(16) << "Not Used:";			//Printing Out What Type of Manipulation We are checking for
  NotUsed.PrintBit();												//Printing out Results of previous line manipulation
  
	TempBool.clear();									//Clearing Data in Vectors
	Temp.clear();
	Ingredients.clear();
	inf.close();
}



vector<string> Split(string str, char delimiter)			//Function to Split up a string of a comma delimited list
{
  vector<string> Ingredients;		//Vector of Strings to store each split of the string
  stringstream ss(str);					//Initializing Sstream
  string tok;										//String to grab each split
  
  while(getline(ss,tok,delimiter))		//while loop to get each split of the string
  {	
    Ingredients.push_back(tok);
    
  }
 
  return Ingredients;		//return the vector of strings with the splits inside
}

Menu Union(Menu A,Menu B)				//Union Function for two sets
{  
	Menu temp;					//Temp variable to store the result of union
	temp = B;						//setting the size of the boolean vector
	for (int j=0; j < B.GetSize(); ++j)  
	{    
		if((A.GetMember(j) == 1) || (B.GetMember(j) == 1 ))     //Finding when there is a value in the set that is in both sets
		{         
			temp.SetMembers(j,1); 		//Setting value to True if if statement is True
		}     
		else     
		{         
			temp.SetMembers(j,0);  		//Setting value to false if if statement is false   
		}  
	}  
	return temp;
}
Menu Intersection(Menu A, Menu B)
{
	Menu temp;				//Temp variable to store the result of Intersection
	temp = B;					//setting the size of the boolean vector
	for (int j=0; j < B.GetSize(); ++j)  		//For loop to run through the boolean vectors
	{    
		if((A.GetMember(j) == 1) && (B.GetMember(j) == 1 ))     		//Finding the Values that exist in both sets
		{         
			temp.SetMembers(j,1);	//Setting value to true if if statement is true
		}     
		else     
		{         
			temp.SetMembers(j,0);  		//Setting value to false if if statement is false   
		}  
	}  
	return temp;
}

Menu Difference(Menu A, Menu B)
{ 
	Menu temp;				//Temp variable to store the result of Difference
	temp = B;					//setting the size of the boolean vector
	for (int j=0; j < B.GetSize(); ++j)    		//For loop to run through the boolean vectors
	{    
		if((A.GetMember(j) - B.GetMember(j)) == 1 )     //Doing Set A - Set B
		{         
			temp.SetMembers(j,1);	//Setting value to true if if statement is true
		}     
		else     
		{         
			temp.SetMembers(j,0); 		//Setting value to false if if statement is false    
		}  
	}  
	return temp;
}

Menu SymDif(Menu A,Menu B)
{
	Menu temp;				//Temp variable to store the result of symmetric difference
	temp = B;					//setting the size of the boolean vector
	for (int j=0; j < B.GetSize(); j++)    		//For loop to run through the boolean vectors
	{    
		if((A.GetMember(j) == 1 && B.GetMember(j) == 0) || (A.GetMember(j) == 0 && B.GetMember(j) == 1))     	//Getting the values in the set that are not matching between sets
		{         
			temp.SetMembers(j,1);	//Setting value to true if if statement is true
		}     
		else     
		{         
			temp.SetMembers(j,0);     		//Setting value to false if if statement is false
		}  
	}  
	return temp;
}

Menu Complement(Menu C)
{
	Menu temp;				//Temp variable to store the result of complement
	temp = C;					//setting the size of the boolean vector
	for(int j = 0; j < temp.GetSize();j++)  		//For loop to run through the boolean vectors
	{
		if(C.GetMember(j) == 0)	//Switching the values for the set
		{
			temp.SetMembers(j,1);	//Setting value to true if if statement is true
		}
		else
		{
		 temp.SetMembers(j,0);		//Setting value to false if if statement is false
		}
	}
		
	return temp;
	
}
