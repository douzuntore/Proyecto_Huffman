#include "CharInstance.h"

CharInstance::CharInstance(char character) :
	character(character), instances(1) 
{
}

CharInstance::CharInstance(char character, int instances) :
	character(character), instances(instances)
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
string CharInstance::getCode()
{
	return code;
}

void CharInstance::addCode(string digit)
{
	code = digit;
}