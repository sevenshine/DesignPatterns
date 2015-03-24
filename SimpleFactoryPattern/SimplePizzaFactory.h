#pragma once
#include <iostream>
#include <string.h>
#include "Pizza.h"
using namespace std;

//�򵥹����࣬ʵ��������
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
