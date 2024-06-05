#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include"Stack.h"
using namespace std; 

class Checker {
public:
	string name;
	char* pairs;
	int qol = 0;
	
	Checker(string name_outside){
		name = name_outside;
	}
	void Add(char first, char sec);
	bool Check();
};
