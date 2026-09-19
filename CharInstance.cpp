#include "Caracter.h"

CharInstance::CharInstance(char caracter) :
	character(caracter), instances(1) 
{
}

CharInstance::CharInstance(char caracter, int reps) :
	character(caracter), instances(reps)
{
}

void CharInstance::repeat()
{
	instances++;
}

char CharInstance::getChr()
{
	return character;
}

int CharInstance::getReps()
{
	return instances;
}