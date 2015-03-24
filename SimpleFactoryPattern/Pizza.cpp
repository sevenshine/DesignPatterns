#include "Pizza.h"

int Pizza::GetName() 
{
	return name;
}

void Pizza::Prepare() 
{
	cout<<"Preparing "<<name <<endl;
}

void Pizza::Bake() 
{
	cout<<"Baking "<<name <<endl;
}

void Pizza::Cut() 
{
	cout<<"Cutting "<<name <<endl;
}

void Pizza::Box() 
{
	cout<<"Boxing "<<name <<endl;
}