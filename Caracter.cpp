#include "Caracter.h"

Caracter::Caracter(char caracter) :
	caracter(caracter), repeticiones(1) 
{
}

Caracter::Caracter(char caracter, int reps) :
	caracter(caracter), repeticiones(reps)
{
}

void Caracter::repeat()
{
	repeticiones++;
}

char Caracter::getChr()
{
	return caracter;
}

int Caracter::getReps()
{
	return repeticiones;
}