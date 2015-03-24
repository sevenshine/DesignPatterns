#pragma once
#include <iostream>
using namespace std;

class FlyBehavior
{
public:
	virtual void Fly()=0;
};

class FlyWithWings:public FlyBehavior
{
public:
	void Fly()
	{
		cout<< "I'm flying" << endl;
	}
};

class FlyNoWay:public FlyBehavior
{
public:
	void Fly()
	{
		cout << "I can't fly" << endl;
	}
};

class FlyRocketPowered:public FlyBehavior
{
public:
	void Fly()
	{
		cout << "I'm flying with a rocket" << endl;
	}
};