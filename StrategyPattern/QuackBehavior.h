#pragma once
#include <iostream>
using namespace std;

class QuackBehavior
{
public:
	virtual void Quack()=0;
};

class JustQuack:public QuackBehavior
{
public:
	void Quack()
	{
		cout<<"say just quack"<<endl;
	}
};

class Squeak:public QuackBehavior
{
public:
	void Quack()
	{
		cout<<"say squeak"<<endl;
	}
};

class MuteQuack:public QuackBehavior
{
public:
	void Quack()
	{
		cout<<"can not say a word"<<endl;
	}
};