#pragma once
#include <string>
#include <iostream>
using namespace std;

//工厂的产品，pizza
class Pizza
{
public:
	int GetName();
	void Prepare();
	void Bake();
	void Cut();
	void Box();
protected:
	int name;
	int dough;
	int sauce;
};

class CheesePizza : public Pizza 
{
public:
	CheesePizza()
	{
		name=11;
		dough=12;
		sauce=13;
	}
};

class PepperoniPizza : public Pizza 
{
public:
	PepperoniPizza()
	{
		name=21;
		dough=22;
		sauce=23;
	}
};

class ClamPizza : public Pizza 
{
public:
	ClamPizza()
	{
		name=31;
		dough=32;
		sauce=33;
	}
};