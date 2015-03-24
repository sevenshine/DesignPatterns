#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include "Observer.h"

using namespace std;

static int g_SetConditionTimes = 0;//记录设置的总次数

//观察者（布告板）抽象接口
class Observer
{
public:
	virtual void Update(float temp,float humidity,float pressure) = 0;
};

//主题抽象接口
class Subject
{
public:
	virtual void RegisterObserver(Observer *ob)=0;
	virtual void RemoveObserver(Observer *ob) = 0;		//删除观察者
	virtual void NotifyObserver() = 0;			//当主题状态改变时，通知所有观察者
};

//布告板显示
class DisplayElement
{
public:
	virtual void Display()=0;
};

//WeatherData具体类，继承自主题抽象类
class WeatherData:public Subject
{
public:
	WeatherData(){}
	~WeatherData()
	{
		//??
		vector<Observer *>::iterator pos=m_vecObservers.begin();
		if (pos != m_vecObservers.end())
		{
			delete(*pos);
			++pos;
		}
	}

	void RegisterObserver(Observer *ob)
	{
		m_vecObservers.push_back(ob);
	}

	void RemoveObserver(Observer *ob)
	{
		vector<Observer *>::iterator pos=find(m_vecObservers.begin(),
			m_vecObservers.end(),ob);
		if (pos != m_vecObservers.end())
			m_vecObservers.erase(pos);
	}

	void NotifyObserver()
	{
		vector<Observer *>::iterator pos=m_vecObservers.begin();
		while (pos != m_vecObservers.end())
		{
			(*pos)->Update(m_fTemperature,m_fHumility,m_fPressure);
			++pos;
		}
	}

	void MessurementsChanged()
	{
		NotifyObserver();
	}

	//设置气象站观测值,用于测试
	void SetMessurements(float temperature,float humility,float pressure)
	{
		++g_SetConditionTimes;
		m_fTemperature=temperature;
		m_fHumility=humility;
		m_fPressure=pressure;
		MessurementsChanged();
	}

private:
	vector<Observer *> m_vecObservers;
	float m_fTemperature;
	float m_fHumility;//湿度
	float m_fPressure;
};

//布告板具体类：目前状况
class CurrentConditionDisplay:public Observer,public DisplayElement
{
public:
	//初始化对象注册
	CurrentConditionDisplay(Subject *weatherData)
	{
		m_WeatherData = weatherData;
		weatherData->RegisterObserver(this);
	}
	~CurrentConditionDisplay(){}

	//update调用，保存、显示
	void Update(float temp,float humi,float pressure)
	{
		m_fTemperature=temp;
		m_fHumility=humi;

		Display();
	}

	void Display(){
		cout << "Current conditions: " << m_fTemperature << "F degrees and " <<
			m_fHumility << "% humility" << endl;
	}

private:
	float m_fTemperature;
	float m_fHumility;

	Subject *m_WeatherData;
};
