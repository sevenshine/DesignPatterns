#include <iostream>
#include "SimplePizzaFactory.h"

using namespace std;

int main()
{
	/*SimplePizzaFactory *pizzaFactory=NULL;
	PizzaStore pizza(pizzaFactory);
	pizza.OrderPizza(1);*/

	SimplePizzaFactory *factory = new SimplePizzaFactory();
	PizzaStore *store = new PizzaStore(factory);

	Pizza *pizza = store->OrderPizza(1);
	cout<< "We ordered a "<< pizza->GetName()<<endl;
}

