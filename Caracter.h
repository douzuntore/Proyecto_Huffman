#pragma once
class Caracter
{
	char caracter;
	int repeticiones;
public:
	Caracter(char);
	Caracter(char, int);
	void repeat();
	char getChr();
	int getReps();
};

