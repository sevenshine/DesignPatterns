#pragma once
#include <iostream>
#include <string.h>
#include "Pizza.h"
using namespace std;

//简单工厂类，实例化对象
class SimplePizzaFactory
{
public:
	SimplePizzaFactory(){}
	Pizza* CreatePizza(int type);
private:
	Pizza *pizza;
};

class PizzaStore
{
public:
	PizzaStore(SimplePizzaFactory *factory);
	~PizzaStore();
	Pizza* OrderPizza(int type);
private:
	SimplePizzaFactory *m_pFactory;
	Pizza *m_pPizza;
};
