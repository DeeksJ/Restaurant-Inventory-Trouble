#include "Menu.h"

void Menu::SetIngredient(const vector<string> &x)
	{
	Ingredient = x;
	SetSize(Ingredient.size());
	}

const vector<string>& Menu::GetIngredient() const		//Function to return whole ingredient vector
	{
  return Ingredient;
	}

void Menu::SetMember(const vector<bool>& y)	//Function to set the whole boolean vector 
{
  Member = y;
}

const vector<bool>& Menu::GetMembers() const		//Function to get the whole boolean vector
{
  return Member;
}
void Menu::SetMembers(int k,bool y)		//Function to set a place in the boolean function
{
	Member[k] = y;	
}

bool Menu::GetMember(int i)			//Function to reutrn a place in the boolean vector
{
	return Member[i];
}

void Menu::SetName(string Iname)	//Function to set the Dish name
	{
	 Name = Iname;
	}

string Menu::GetName()			//Fucntion to Reutrn The Dish Name
	{
	return Name;
	}

void Menu::SetSize(int size)		//Function to set the Size of the universal set to a easier variable to manipulate
{
 Size = Ingredient.size();
}

int Menu::GetSize()			//Returning the Size of the universal set
{
return Size;
}


void Menu::PrintUniversal()
{
  for(int i =0; i < Ingredient.size();i++)
  {
    cout << GetName() << setw(10) << Ingredient.at(i) << "  ";
  }
  cout << endl;  
}

void Menu::PrintBit()
{
 for(int i =0; i < Member.size();i++)
  {
    cout << setw(10) << Member.at(i) << "  ";
  }
  cout << endl;
}

bool Menu::Insert(string x)
{
	for (int y = 0; y < Ingredient.size(); y++)
	{	
		if (Ingredient.at(y) == x)
		{
			Member.at(y) = 1;
			return true;
		}
	}
	return false;
}

bool Menu::Contains(string x)
{
	for (int pos = 0; pos < Ingredient.size(); pos++)
	{
		if (Ingredient[pos] == x && Member[pos] == 1)
		{
			return true;
		}
	}
	return false;
}

bool Menu::Remove(string x)
{
	for (int pos = 0; pos < Ingredient.size(); pos++)
	{
		if (Ingredient[pos] == x)
		{
			Member[pos] = 0;
			return true;
		}
	}
	return false;
}


