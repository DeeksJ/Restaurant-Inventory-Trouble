#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

class Menu
{
private:
  int Size;
	vector<string> Ingredient;
	vector<bool> Member;
  string Name;
  
public:
	void SetIngredient(const vector<string> &x);
	const vector<string>& GetIngredient() const;
  void SetMember(const vector<bool>& y);
  const vector<bool>& GetMembers() const;
	void SetMembers(int,bool);
	bool GetMember(int i);
	void SetName(string Iname);
	string GetName();
  void SetSize(int size);
  int GetSize();
  void PrintUniversal();
  void PrintBit();
	bool Insert(string x);
	bool Contains(string x);
	bool Remove(string x);

};
