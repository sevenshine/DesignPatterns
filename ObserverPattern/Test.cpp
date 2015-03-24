#include <iostream>
#include <vector>
#include <algorithm>
#include "Observer.h"

using namespace std;

int main()
{
	WeatherData *weatherData = new WeatherData();

	CurrentConditionDisplay *currentConditionDisplay = new CurrentConditionDisplay(weatherData);
	//WeatherStatisticsDisplay *weatherStatisticsDisplay = new WeatherStatisticsDisplay(weatherData);

	weatherData->SetMessurements(80,65,30.4f);
	weatherData->SetMessurements(82,70,29.2f);
	weatherData->SetMessurements(78,90,29.2f);

	/*weatherData->removeObserver(weatherStatisticsDisplay);

	cout << "after remove observer WeatherStatisticsDisplay:" << endl;
	weatherData->setMessurements(80,65,30.4f);
	weatherData->setMessurements(82,70,29.2f);
	weatherData->setMessurements(78,90,29.2f);*/

	return 0;
}