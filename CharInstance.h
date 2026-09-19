#pragma once
class CharInstance
{
	char character;
	int instances;
public:
	CharInstance(char);
	CharInstance(char, int);
	void repeat();
	char getChr();
	int getReps();
};

