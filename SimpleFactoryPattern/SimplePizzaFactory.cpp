#include "SimplePizzaFactory.h"

Pizza* SimplePizzaFactory::CreatePizza(int type)
{
	if (type==1) 
		pizza = new CheesePizza();
	else if (type==2) 
		pizza = new PepperoniPizza();
	else if (type==3) 
		pizza = new ClamPizza();

	return pizza;
}

PizzaStore::PizzaStore(SimplePizzaFactory *factory) 
{ 
	m_pFactory = factory;
}

PizzaStore::~PizzaStore()
{
	delete m_pFactory;
	delete m_pPizza;
}

Pizza* PizzaStore::OrderPizza(int type) 
{
	//函数返回取代直接new实例
	m_pPizza = m_pFactory->CreatePizza(type);

	m_pPizza->Prepare();
	m_pPizza->Bake();
	m_pPizza->Cut();
	m_pPizza->Box();

	return m_pPizza;
}