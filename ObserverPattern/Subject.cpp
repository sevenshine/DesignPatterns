#include "Subject.h"

WeatherData::~WeatherData()
{
	//??
	vector<Observer *>::iterator pos=m_vecObservers.begin();
	if (pos != m_vecObservers.end())
	{
		delete(*pos);
		++pos;
	}
}

void WeatherData::RegisterObserver(Observer *ob)
{
	m_vecObservers.push_back(ob);
}

void WeatherData::RemoveObserver(Observer *ob)
{
	vector<Observer *>::iterator pos=find(m_vecObservers.begin(),
		m_vecObservers.end(),ob);
	if (pos != m_vecObservers.end())
		m_vecObservers.erase(pos);
}

void WeatherData::NotifyObserver()
{
	vector<Observer *>::iterator pos=m_vecObservers.begin();
	while (pos != m_vecObservers.end())
	{
		(*pos)->Update(m_fTemperature,m_fHumility,m_fPressure);
		++pos;
	}
}

void WeatherData::MessurementsChanged()
{
	NotifyObserver();
}

//设置气象站观测值,用于测试
void WeatherData::SetMessurements(float temperature,float humility,float pressure)
{
	++g_SetConditionTimes;
	m_fTemperature=temperature;
	m_fHumility=humility;
	m_fPressure=pressure;
	MessurementsChanged();
}