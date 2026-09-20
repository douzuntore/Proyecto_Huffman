#pragma once
#include <iostream>
#include <string>
using namespace std;

class CharInstance
{
	char character;
	int instances;
	string code = "";
public:
	CharInstance(char);
	CharInstance(char, int);
	//CharInstance(char, int, string);
	void repeat();
	char getChr();
	int getInstances();
	string getCode();
	void addCode(string);
};

